#include <iostream>
#include <exception>
#include <string>

class BankingException : public std::exception {
private:
    std::string message;
public:
    explicit BankingException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class NetworkException : public std::exception {
private:
    std::string message;
public:
    explicit NetworkException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void testBasicException() {
    try {
        throw BankingException("Basic banking error occurred");
    } catch (const BankingException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void testMultipleExceptions() {
    std::cout << "\n--- Testing Multiple Exception Types ---" << std::endl;
    
    // Test BankingException
    try {
        throw BankingException("Banking system temporarily unavailable");
    } catch (const BankingException& e) {
        std::cout << "Banking error: " << e.what() << std::endl;
    } catch (const NetworkException& e) {
        std::cout << "Network error: " << e.what() << std::endl;
    }
    
    // Test NetworkException
    try {
        throw NetworkException("Network connection failed");
    } catch (const BankingException& e) {
        std::cout << "Banking error: " << e.what() << std::endl;
    } catch (const NetworkException& e) {
        std::cout << "Network error: " << e.what() << std::endl;
    }
    
    // Test catching both in same try-catch block with different messages
    try {
        // Simulate random error - in practice this might be determined by runtime conditions
        bool networkError = true; // Change this to false to test BankingException
        
        if (networkError) {
            throw NetworkException("Server unreachable - check internet connection");
        } else {
            throw BankingException("Account verification service down");
        }
        
    } catch (const BankingException& e) {
        std::cout << "Caught banking error: " << e.what() << std::endl;
    } catch (const NetworkException& e) {
        std::cout << "Caught network error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== Task 1: Basic Custom Exception Design ===" << std::endl;
    
    testBasicException();
    testMultipleExceptions();
    
    std::cout << "\nAll exception tests completed successfully!" << std::endl;
    return 0;
}