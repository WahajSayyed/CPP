/*Refactor the financial calculator to use dependency injection, making it more testable and maintainable by separating concerns and enabling mock testing.

🔍 Practice
Analyze the dependency injection architecture in the code below:
    Interface segregation - each dependency has a focused, single-responsibility interface
    Dependency inversion - high-level FinancialCalculator depends on abstractions, not concrete classes
    Testability - mock implementations enable isolated unit testing
    Flexibility - different implementations can be swapped without changing core logic

Create additional test scenarios:
    Test with different rate providers (fixed vs. dynamic rates)
    Verify logging behavior using mock loggers
    Test error handling with custom validator implementations
Compare the testability of this version versus the original monolithic design.*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>
// Abstract interfaces for dependency injection
class InterestRateProvider {
public:
    virtual ~InterestRateProvider() = default;
    virtual double getCurrentRate() const = 0;
    virtual std::string getRateSource() const = 0;
};
class CalculationLogger {
public:
    virtual ~CalculationLogger() = default;
    virtual void logCalculation(const std::string& operation, double result) = 0;
    virtual void logError(const std::string& error) = 0;
};
class ValidationService {
public:
    virtual ~ValidationService() = default;
    virtual void validatePositive(double value, const std::string& fieldName) const = 0;
    virtual void validateNonNegative(double value, const std::string& fieldName) const = 0;
};
// Concrete implementations
class MarketRateProvider : public InterestRateProvider {
private:
    double baseRate;   
public:
    MarketRateProvider(double rate) : baseRate(rate) {}    
    double getCurrentRate() const override {
        // Simulate market rate fluctuation
        return baseRate + (rand() % 100 - 50) / 10000.0; // ±0.5% variation
    }    
    std::string getRateSource() const override {
        return "Market Data Provider";
    }
};
class FileLogger : public CalculationLogger {
private:
    std::string logLevel;    
public:
    FileLogger(const std::string& level = "INFO") : logLevel(level) {}    
    void logCalculation(const std::string& operation, double result) override {
        std::cout << "[" << logLevel << "] Calculation: " << operation 
                  << " = $" << result << std::endl;
    }    
    void logError(const std::string& error) override {
        std::cout << "[ERROR] " << error << std::endl;
    }
};
class StandardValidator : public ValidationService {
public:
    void validatePositive(double value, const std::string& fieldName) const override {
        if (value <= 0) {
            throw std::invalid_argument(fieldName + " must be positive");
        }
    }    
    void validateNonNegative(double value, const std::string& fieldName) const override {
        if (value < 0) {
            throw std::invalid_argument(fieldName + " cannot be negative");
        }
    }
};
// Refactored FinancialCalculator using dependency injection
class FinancialCalculator {
private:
    std::shared_ptr<InterestRateProvider> rateProvider;
    std::shared_ptr<CalculationLogger> logger;
    std::shared_ptr<ValidationService> validator;
    int calculationCount;    
public:
    FinancialCalculator(
        std::shared_ptr<InterestRateProvider> rateProvider,
        std::shared_ptr<CalculationLogger> logger,
        std::shared_ptr<ValidationService> validator
    ) : rateProvider(rateProvider), logger(logger), validator(validator), calculationCount(0) {}    
    double calculateCompoundInterest(double principal, int years) {
        try {
            validator->validatePositive(principal, "Principal");
            validator->validateNonNegative(years, "Years");            
            calculationCount++;
            double currentRate = rateProvider->getCurrentRate();
            double result = principal;            
            for (int i = 0; i < years; i++) {
                result = result * (1 + currentRate);
            }            
            double interest = result - principal;
            logger->logCalculation("Compound Interest (rate: " + 
                                 std::to_string(currentRate * 100) + "%)", interest);            
            return interest;            
        } catch (const std::exception& e) {
            logger->logError("Compound interest calculation failed: " + std::string(e.what()));
            throw;
        }
    }    
    double calculatePortfolioValue(const std::vector<double>& investments) {
        try {
            if (investments.empty()) {
                logger->logCalculation("Portfolio Value (empty)", 0.0);
                return 0.0;
            }            
            calculationCount++;
            double total = 0.0;            
            for (const auto& investment : investments) {
                validator->validateNonNegative(investment, "Investment value");
                total += investment;
            }            
            logger->logCalculation("Portfolio Value", total);
            return total;            
        } catch (const std::exception& e) {
            logger->logError("Portfolio calculation failed: " + std::string(e.what()));
            throw;
        }
    }    
    int getCalculationCount() const { return calculationCount; }
    std::string getRateSource() const { return rateProvider->getRateSource(); }
};
// Mock implementations for testing
class MockRateProvider : public InterestRateProvider {
private:
    double fixedRate;    
public:
    MockRateProvider(double rate) : fixedRate(rate) {}    
    double getCurrentRate() const override {
        return fixedRate;
    }    
    std::string getRateSource() const override {
        return "Mock Provider";
    }
};
class MockLogger : public CalculationLogger {
public:
    mutable std::vector<std::string> logEntries;
    mutable std::vector<std::string> errorEntries;    
    void logCalculation(const std::string& operation, double result) override {
        logEntries.push_back(operation + " = " + std::to_string(result));
    }    
    void logError(const std::string& error) override {
        errorEntries.push_back(error);
    }    
    size_t getLogCount() const { return logEntries.size(); }
    size_t getErrorCount() const { return errorEntries.size(); }
};
int main() {
    // Production configuration
    auto rateProvider = std::make_shared<MarketRateProvider>(0.05);
    auto logger = std::make_shared<FileLogger>("INFO");
    auto validator = std::make_shared<StandardValidator>();    
    FinancialCalculator calculator(rateProvider, logger, validator);    
    std::cout << "=== Production Financial Calculator ===" << std::endl;
    std::cout << "Rate source: " << calculator.getRateSource() << std::endl;    
    try {
        double interest = calculator.calculateCompoundInterest(1000.0, 3);
        std::cout << "Interest earned: $" << interest << std::endl;        
        std::vector<double> portfolio = {1500.0, 2300.0, 980.0};
        double total = calculator.calculatePortfolioValue(portfolio);
        std::cout << "Portfolio value: $" << total << std::endl;        
    } catch (const std::exception& e) {
        std::cout << "Calculation error: " << e.what() << std::endl;
    }    
    std::cout << "Calculations performed: " << calculator.getCalculationCount() << std::endl;    
    // Testing configuration with mocks
    std::cout << "\n=== Testing with Mocks ===" << std::endl;    
    auto mockRate = std::make_shared<MockRateProvider>(0.10); // 10% fixed rate
    auto mockLogger = std::make_shared<MockLogger>();
    auto mockValidator = std::make_shared<StandardValidator>();    
    FinancialCalculator testCalculator(mockRate, mockLogger, mockValidator);    
    double testInterest = testCalculator.calculateCompoundInterest(1000.0, 2);
    std::cout << "Test interest (10% fixed): $" << testInterest << std::endl;
    std::cout << "Mock logged " << mockLogger->getLogCount() << " entries" << std::endl;    
    return 0;
}
/*✅ Success Checklist
    Dependencies are properly abstracted through interfaces
    Mock implementations enable isolated testing
    Error handling is comprehensive and logged appropriately
    The design follows SOLID principles for maintainability

💡 Key Points
    Strategic breakpoint placement and variable inspection are essential debugging skills
    Comprehensive test suites should cover normal cases, edge cases, and error conditions
    Dependency injection dramatically improves code testability and maintainability
    Mock objects enable isolated testing of individual components
    Exception testing validates error handling and system resilience
    Test organization with sections and descriptive names improves maintainability

❗ Common Mistakes to Avoid
    Setting too many breakpoints, making debugging sessions unwieldy
    Testing only happy-path scenarios while ignoring edge cases and errors
    Writing tests that are too tightly coupled to implementation details
    Comparing floating-point numbers for exact equality without epsilon values
    Creating god classes that are difficult to test in isolation
    Not using mock objects to isolate units under test

🚀 Next Steps
These debugging and testing skills form the foundation of professional software development practices.
In enterprise environments, systematic debugging reduces time-to-resolution for production issues, while comprehensive testing prevents defects from reaching customers. 
Consider exploring advanced topics like continuous integration pipelines, automated testing in CI/CD, performance profiling, and test-driven development (TDD). 
These practices will be essential when working on large-scale systems where code quality, reliability, and maintainability directly impact business success.*/