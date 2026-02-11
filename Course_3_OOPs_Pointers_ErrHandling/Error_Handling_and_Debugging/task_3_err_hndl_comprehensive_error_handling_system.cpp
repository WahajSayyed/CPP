// Build a complete banking system with logging, recovery mechanisms, and multiple layers of error handling.

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
// Exception hierarchy (from Task 2)
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
public:
    InsufficientFundsException(double requested, double available) 
        : BankingException("Insufficient funds: requested $" + std::to_string(requested) + 
                          ", available $" + std::to_string(available), 1001) {}
};
class InvalidAccountException : public BankingException {
public:
    InvalidAccountException(const std::string& accountId) 
        : BankingException("Invalid account: " + accountId, 1002) {}
};
class TransactionLimitException : public BankingException {
public:
    TransactionLimitException(double amount, double limit) 
        : BankingException("Transaction amount $" + std::to_string(amount) + 
                          " exceeds limit $" + std::to_string(limit), 1003) {}
};
// Error logging system
class ErrorLogger {
public:
    static void logException(const BankingException& e, const std::string& context = "") {
        std::ofstream logFile("banking_errors.log", std::ios::app);
        if (logFile.is_open()) {
            char timeStr[100];
	 std::time_t timestamp1 = const_cast<BankingException&>(e).getTimestamp();
            std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", 
                         std::localtime(& timestamp1 ));            
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
};
// Banking account class
class BankAccount {
private:
    std::string accountId;
    double balance;
    double dailyLimit;
    double dailyUsed;    
public:
    BankAccount(const std::string& id, double initial_balance, double limit = 1000.0) 
        : accountId(id), balance(initial_balance), dailyLimit(limit), dailyUsed(0.0) {}    
    void withdraw(double amount) {
        try {
            validateAccount();
            validateWithdrawal(amount);            
            balance -= amount;
            dailyUsed += amount;            
            ErrorLogger::logInfo("Successful withdrawal: $" + std::to_string(amount) + 
                               " from account " + accountId);
            std::cout << "Withdrawal successful. New balance: $" << balance << std::endl;            
        } catch (const BankingException& e) {
            ErrorLogger::logException(e, "Account: " + accountId);
            throw; // Re-throw for upper-level handling
        }
    }    
private:
    void validateAccount() {
        if (accountId.empty()) {
            throw InvalidAccountException("Empty account ID");
        }
    }    
    void validateWithdrawal(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException(amount, balance);
        }
        if (amount + dailyUsed > dailyLimit) {
            throw TransactionLimitException(amount, dailyLimit - dailyUsed);
        }
    }
};
// Recovery mechanism
class TransactionRecovery {
public:
    static bool attemptRecovery(const BankingException& e, BankAccount& account, double amount) {
        switch (e.getErrorCode()) {
            case 1001: // Insufficient funds
                std::cout << "Recovery: Offering partial withdrawal option..." << std::endl;
                return false; // Could implement partial withdrawal logic                
            case 1003: // Transaction limit
                std::cout << "Recovery: Transaction will be processed tomorrow when limit resets." << std::endl;
                return false; // Could queue for next day                
            default:
                return false;
        }
    }
};
int main() {
    BankAccount account("ACC001", 500.0, 1000.0);    
    std::vector<double> withdrawalAmounts = {200.0, 400.0, 600.0}; // Test sequence    
    for (double amount : withdrawalAmounts) {
        try {
            std::cout << "\nAttempting withdrawal of $" << amount << std::endl;
            account.withdraw(amount);            
        } catch (const BankingException& e) {
            std::cout << "Transaction failed: " << e.what() << std::endl;            
            // Attempt recovery
            if (!TransactionRecovery::attemptRecovery(e, account, amount)) {
                std::cout << "Recovery failed. Transaction cancelled." << std::endl;
            }            
        } catch (const std::exception& e) {
            ErrorLogger::logInfo("System error: " + std::string(e.what()));
            std::cout << "System error occurred: " << e.what() << std::endl;
        }
    }    
    return 0;
}

/*🔍 Practice
Run the complete system and observe how different withdrawal amounts trigger different exceptions.
Check the generated log file to see how errors are recorded with timestamps.
Modify the recovery mechanism to implement actual recovery strategies.
Add additional exception types and corresponding recovery mechanisms.
Test the system with invalid account scenarios.

✅ Success Checklist
    Complete exception hierarchy handles all error scenarios
    Logging system captures detailed error information with timestamps
    Recovery mechanisms attempt to handle errors gracefully
    Multiple layers of error handling provide comprehensive coverage

💡 Key Points
    Custom exception hierarchies enable precise error handling for different scenarios
    The what() method should provide clear, actionable error messages
    Error codes allow programmatic distinction between exception types
    Logging systems are essential for debugging and monitoring in production
    Recovery mechanisms can transform potential failures into manageable situations
    Catch blocks should be ordered from most specific to most general exceptions

❗ Common Mistakes to Avoid
    Creating exception classes that don't inherit from std::exception
    Writing overly generic error messages that don't help with debugging
    Placing generic catch blocks before specific ones
    Forgetting to implement the noexcept specifier on the what() method
    Not providing sufficient context information in custom exceptions
    Catching exceptions by value instead of by const reference

🚀 Next Steps
These exception handling skills are fundamental for building enterprise-grade software systems. In professional development environments, robust error handling distinguishes reliable applications from fragile ones. Consider exploring advanced topics like exception safety guarantees, RAII patterns, and how exception handling integrates with modern C++ features like smart pointers and move semantics. These skills will be essential when working on large-scale systems where reliability and maintainability are critical business requirements.

*/