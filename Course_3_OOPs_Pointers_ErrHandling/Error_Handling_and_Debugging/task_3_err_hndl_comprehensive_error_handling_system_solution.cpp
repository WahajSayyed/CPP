#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <iomanip>

// Exception hierarchy (complete from Task 2)
class BankingException : public std::exception {
protected:
    std::string errorMessage;
    int errorCode;
    std::time_t timestamp;
    
public:
    BankingException(const std::string& msg, int code = 0) 
        : errorMessage(msg), errorCode(code) {
        timestamp = std::time(nullptr);
    }
    
    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
    
    int getErrorCode() const { return errorCode; }
    std::time_t getTimestamp() const { return timestamp; }
};

class InsufficientFundsException : public BankingException {
private:
    double requestedAmount;
    double availableBalance;
    
public:
    InsufficientFundsException(double requested, double available) 
        : BankingException("Insufficient funds: requested $" + std::to_string(requested) + 
                          ", available $" + std::to_string(available), 1001),
          requestedAmount(requested), availableBalance(available) {}
    
    double getRequestedAmount() const { return requestedAmount; }
    double getAvailableBalance() const { return availableBalance; }
};

class InvalidAccountException : public BankingException {
public:
    InvalidAccountException(const std::string& accountId) 
        : BankingException("Invalid account: " + accountId, 1002) {}
};

class TransactionLimitException : public BankingException {
private:
    double transactionAmount;
    double remainingLimit;
    
public:
    TransactionLimitException(double amount, double limit) 
        : BankingException("Transaction amount $" + std::to_string(amount) + 
                          " exceeds remaining daily limit $" + std::to_string(limit), 1003),
          transactionAmount(amount), remainingLimit(limit) {}
    
    double getTransactionAmount() const { return transactionAmount; }
    double getRemainingLimit() const { return remainingLimit; }
};

// Enhanced Error logging system
class ErrorLogger {
public:
    static void logException(const BankingException& e, const std::string& context = "") {
        std::ofstream logFile("banking_errors.log", std::ios::app);
        if (logFile.is_open()) {
            char timeStr[100];
            std::time_t timestamp = e.getTimestamp();
            std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", 
                         std::localtime(&timestamp));
            
            logFile << "[" << timeStr << "] ERROR " << e.getErrorCode() 
                   << ": " << e.what();
            if (!context.empty()) {
                logFile << " | Context: " << context;
            }
            logFile << std::endl;
            logFile.close();
        }
    }
    
    static void logInfo(const std::string& message) {
        std::ofstream logFile("banking_errors.log", std::ios::app);
        if (logFile.is_open()) {
            std::time_t now = std::time(nullptr);
            char timeStr[100];
            std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
            
            logFile << "[" << timeStr << "] INFO: " << message << std::endl;
            logFile.close();
        }
    }
    
    static void logWarning(const std::string& message) {
        std::ofstream logFile("banking_errors.log", std::ios::app);
        if (logFile.is_open()) {
            std::time_t now = std::time(nullptr);
            char timeStr[100];
            std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
            
            logFile << "[" << timeStr << "] WARNING: " << message << std::endl;
            logFile.close();
        }
    }
    
    static void displayRecentLogs(int numLines = 10) {
        std::cout << "\n--- Recent Log Entries ---" << std::endl;
        std::ifstream logFile("banking_errors.log");
        if (logFile.is_open()) {
            std::vector<std::string> lines;
            std::string line;
            while (std::getline(logFile, line)) {
                lines.push_back(line);
            }
            
            int startIndex = std::max(0, static_cast<int>(lines.size()) - numLines);
            for (int i = startIndex; i < static_cast<int>(lines.size()); ++i) {
                std::cout << lines[i] << std::endl;
            }
            logFile.close();
        } else {
            std::cout << "No log file found." << std::endl;
        }
    }
};

// Enhanced Banking account class
class BankAccount {
private:
    std::string accountId;
    double balance;
    double dailyLimit;
    double dailyUsed;
    bool isActive;
    
public:
    BankAccount(const std::string& id, double initialBalance, double limit = 1000.0) 
        : accountId(id), balance(initialBalance), dailyLimit(limit), dailyUsed(0.0), isActive(true) {
        ErrorLogger::logInfo("Account created: " + id + " with initial balance $" + std::to_string(initialBalance));
    }
    
    void withdraw(double amount) {
        try {
            validateAccount();
            validateWithdrawal(amount);
            
            balance -= amount;
            dailyUsed += amount;
            
            ErrorLogger::logInfo("Successful withdrawal: $" + std::to_string(amount) + 
                               " from account " + accountId + ". New balance: $" + std::to_string(balance));
            std::cout << "✓ Withdrawal successful. New balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
            
        } catch (const BankingException& e) {
            ErrorLogger::logException(e, "Account: " + accountId + ", Attempted amount: $" + std::to_string(amount));
            throw; // Re-throw for upper-level handling
        }
    }
    
    void deposit(double amount) {
        if (amount <= 0) {
            throw BankingException("Deposit amount must be positive", 1004);
        }
        
        balance += amount;
        ErrorLogger::logInfo("Deposit: $" + std::to_string(amount) + " to account " + accountId);
        std::cout << "✓ Deposit successful. New balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }
    
    // Getter methods for recovery mechanisms
    double getBalance() const { return balance; }
    double getRemainingDailyLimit() const { return dailyLimit - dailyUsed; }
    std::string getAccountId() const { return accountId; }
    bool getIsActive() const { return isActive; }
    
    void deactivateAccount() { isActive = false; }
    void reactivateAccount() { isActive = true; }
    
    void resetDailyLimit() { 
        dailyUsed = 0.0; 
        ErrorLogger::logInfo("Daily limit reset for account " + accountId);
    }
    
private:
    void validateAccount() {
        if (accountId.empty()) {
            throw InvalidAccountException("Empty account ID");
        }
        if (!isActive) {
            throw InvalidAccountException("Account " + accountId + " is deactivated");
        }
    }
    
    void validateWithdrawal(double amount) {
        if (amount <= 0) {
            throw BankingException("Withdrawal amount must be positive", 1005);
        }
        if (amount > balance) {
            throw InsufficientFundsException(amount, balance);
        }
        if (amount + dailyUsed > dailyLimit) {
            throw TransactionLimitException(amount, dailyLimit - dailyUsed);
        }
    }
};

// Enhanced Recovery mechanism
class TransactionRecovery {
public:
    static bool attemptRecovery(const BankingException& e, BankAccount& account, double requestedAmount) {
        std::cout << "\n🔄 Attempting transaction recovery..." << std::endl;
        
        switch (e.getErrorCode()) {
            case 1001: // Insufficient funds
                return handleInsufficientFunds(e, account, requestedAmount);
                
            case 1003: // Transaction limit
                return handleTransactionLimit(e, account, requestedAmount);
                
            case 1002: // Invalid account
                return handleInvalidAccount(e, account);
                
            default:
                std::cout << "❌ No recovery mechanism available for error code " << e.getErrorCode() << std::endl;
                return false;
        }
    }
    
private:
    static bool handleInsufficientFunds(const BankingException& e, BankAccount& account, double requestedAmount) {
        const InsufficientFundsException* fundsException = 
            dynamic_cast<const InsufficientFundsException*>(&e);
        
        if (fundsException) {
            double availableBalance = fundsException->getAvailableBalance();
            
            if (availableBalance > 0) {
                std::cout << "💡 Recovery option: Partial withdrawal of $" << std::fixed << std::setprecision(2) 
                         << availableBalance << " is available." << std::endl;
                
                // In a real system, you'd prompt user for confirmation
                std::cout << "Would you like to withdraw the available amount? (Simulating: Yes)" << std::endl;
                
                try {
                    account.withdraw(availableBalance);
                    ErrorLogger::logWarning("Partial withdrawal recovery successful: $" + 
                                           std::to_string(availableBalance) + " instead of $" + 
                                           std::to_string(requestedAmount));
                    return true;
                } catch (const BankingException& recoveryError) {
                    ErrorLogger::logException(recoveryError, "Recovery attempt failed");
                    return false;
                }
            } else {
                std::cout << "❌ No funds available for partial withdrawal." << std::endl;
                return false;
            }
        }
        return false;
    }
    
    static bool handleTransactionLimit(const BankingException& e, BankAccount& account, double requestedAmount) {
        const TransactionLimitException* limitException = 
            dynamic_cast<const TransactionLimitException*>(&e);
        
        if (limitException) {
            double remainingLimit = limitException->getRemainingLimit();
            
            if (remainingLimit > 0) {
                std::cout << "💡 Recovery option: You can withdraw up to $" << std::fixed << std::setprecision(2) 
                         << remainingLimit << " within your daily limit." << std::endl;
                std::cout << "Remaining amount ($" << (requestedAmount - remainingLimit) 
                         << ") can be processed tomorrow." << std::endl;
                
                // Simulate processing within limit
                try {
                    account.withdraw(remainingLimit);
                    ErrorLogger::logWarning("Partial withdrawal within limit: $" + 
                                           std::to_string(remainingLimit) + " processed, $" + 
                                           std::to_string(requestedAmount - remainingLimit) + " queued");
                    return true;
                } catch (const BankingException& recoveryError) {
                    ErrorLogger::logException(recoveryError, "Limit recovery attempt failed");
                    return false;
                }
            } else {
                std::cout << "❌ Daily limit already reached. Transaction will be queued for tomorrow." << std::endl;
                scheduleTransaction(account.getAccountId(), requestedAmount);
                return true; // Queuing counts as successful recovery
            }
        }
        return false;
    }
    
    static bool handleInvalidAccount(const BankingException& e, BankAccount& account) {
        std::cout << "💡 Recovery option: Attempting to reactivate account..." << std::endl;
        
        if (!account.getIsActive()) {
            account.reactivateAccount();
            ErrorLogger::logWarning("Account reactivated: " + account.getAccountId());
            std::cout << "✓ Account has been reactivated. Please retry your transaction." << std::endl;
            return true;
        } else {
            std::cout << "❌ Account validation issue cannot be resolved automatically." << std::endl;
            return false;
        }
    }
    
    static void scheduleTransaction(const std::string& accountId, double amount) {
        ErrorLogger::logInfo("Transaction scheduled for next business day: Account " + 
                           accountId + ", Amount $" + std::to_string(amount));
        std::cout << "📅 Transaction of $" << std::fixed << std::setprecision(2) 
                 << amount << " scheduled for next business day." << std::endl;
    }
};

// Test scenarios
void runComprehensiveTests() {
    std::cout << "=== Comprehensive Banking System Test ===" << std::endl;
    
    // Create test account
    BankAccount account("ACC001", 800.0, 1000.0);
    
    // Test scenarios with various amounts
    std::vector<double> testAmounts = {200.0, 300.0, 400.0, 600.0, 100.0};
    
    for (size_t i = 0; i < testAmounts.size(); ++i) {
        double amount = testAmounts[i];
        
        std::cout << "\n--- Test " << (i + 1) << ": Attempting withdrawal of $" 
                 << std::fixed << std::setprecision(2) << amount << " ---" << std::endl;
        
        try {
            account.withdraw(amount);
            
        } catch (const BankingException& e) {
            std::cout << "❌ Transaction failed: " << e.what() 
                     << " (Error Code: " << e.getErrorCode() << ")" << std::endl;
            
            // Attempt recovery
            bool recovered = TransactionRecovery::attemptRecovery(e, account, amount);
            
            if (!recovered) {
                std::cout << "🚫 Recovery failed. Transaction cancelled." << std::endl;
            }
            
        } catch (const std::exception& e) {
            ErrorLogger::logInfo("System error: " + std::string(e.what()));
            std::cout << "💥 System error occurred: " << e.what() << std::endl;
        }
        
        // Small delay simulation
        std::cout << "Current account status: Balance $" << std::fixed << std::setprecision(2) 
                 << account.getBalance() << ", Remaining daily limit $" 
                 << account.getRemainingDailyLimit() << std::endl;
    }
}

void demonstrateAdditionalFeatures() {
    std::cout << "\n=== Additional Features Demonstration ===" << std::endl;
    
    BankAccount testAccount("ACC999", 500.0, 800.0);
    
    // Test deposit
    try {
        std::cout << "\nTesting deposit functionality:" << std::endl;
        testAccount.deposit(150.0);
    } catch (const BankingException& e) {
        std::cout << "Deposit failed: " << e.what() << std::endl;
    }
    
    // Test account deactivation and recovery
    std::cout << "\nTesting account deactivation and recovery:" << std::endl;
    testAccount.deactivateAccount();
    
    try {
        testAccount.withdraw(100.0);
    } catch (const BankingException& e) {
        std::cout << "Expected failure: " << e.what() << std::endl;
        TransactionRecovery::attemptRecovery(e, testAccount, 100.0);
        
        // Now try again after recovery
        try {
            std::cout << "Retrying withdrawal after account reactivation..." << std::endl;
            testAccount.withdraw(100.0);
        } catch (const BankingException& e2) {
            std::cout << "Still failed: " << e2.what() << std::endl;
        }
    }
}

int main() {
    // Clear previous log file for clean test
    std::ofstream logFile("banking_errors.log", std::ios::trunc);
    logFile.close();
    
    ErrorLogger::logInfo("Banking system started - comprehensive test session");
    
    try {
        runComprehensiveTests();
        demonstrateAdditionalFeatures();
        
    } catch (const std::exception& e) {
        ErrorLogger::logException(BankingException("System failure: " + std::string(e.what()), 9999), 
                                 "Main program execution");
        std::cout << "💥 Critical system error: " << e.what() << std::endl;
    }
    
    // Display recent log entries
    ErrorLogger::displayRecentLogs(15);
    
    ErrorLogger::logInfo("Banking system test session completed");
    
    std::cout << "\n=== Test Summary ===" << std::endl;
    std::cout << "✓ Complete exception hierarchy with enhanced error information" << std::endl;
    std::cout << "✓ Comprehensive logging system with timestamps and context" << std::endl;
    std::cout << "✓ Advanced recovery mechanisms for different error types" << std::endl;
    std::cout << "✓ Multiple layers of error handling and validation" << std::endl;
    std::cout << "✓ Real-world banking operations simulation" << std::endl;
    std::cout << "\nCheck 'banking_errors.log' for detailed transaction history." << std::endl;
    
    return 0;
}