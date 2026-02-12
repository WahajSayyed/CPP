/*Create a robust test suite using Catch2 that validates all aspects of the financial calculator functionality, including edge cases and error conditions.

🔍 Practice
Compile and run the test suite using the code below:
g++ -std=c++17 financial_calc_tests.cpp -o test_suite
./test_suite

Analyze the test results and observe:
    Test organization using sections and descriptive names
    Edge case coverage including boundary conditions and error cases
    Exception testing to verify proper error handling
    Floating-point comparisons using appropriate epsilon values

Add additional test cases for:
    Large number calculations (stress testing)
    Performance benchmarks for portfolio calculations
    Integration tests combining multiple operations

Run tests with verbose output to see detailed results for each test case.
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <stdexcept>
class FinancialCalculator {
private:
    double interestRate;
    int calculationCount;    
public:
    FinancialCalculator(double rate) : calculationCount(0) {
        if (rate < 0) {
            throw std::invalid_argument("Interest rate cannot be negative");
        }
        interestRate = rate;
    }    
    // Fixed version of compound interest calculation
    double calculateCompoundInterest(double principal, int years) {
        if (principal < 0) {
            throw std::invalid_argument("Principal cannot be negative");
        }
        if (years < 0) {
            throw std::invalid_argument("Years cannot be negative");
        }        
        calculationCount++;
        double result = principal;        
        // Fixed: correct loop condition
        for (int i = 0; i < years; i++) {
            result = result * (1 + interestRate);
        }        
        return result - principal;
    }    
    // Fixed version of portfolio calculation
    double calculatePortfolioValue(const std::vector<double>& investments) {
        if (investments.empty()) {
            return 0.0;
        }        
        calculationCount++;
        double total = 0.0;        
        // Fixed: correct loop bounds
        for (size_t i = 0; i < investments.size(); i++) {
            if (investments[i] < 0) {
                throw std::invalid_argument("Investment values cannot be negative");
            }
            total += investments[i];
        }        
        return total;
    }    
    double getInterestRate() const { return interestRate; }
    int getCalculationCount() const { return calculationCount; }
    void resetCalculationCount() { calculationCount = 0; }
};
// Comprehensive test cases
TEST_CASE("FinancialCalculator Construction", "[constructor]") {
    SECTION("Valid interest rate") {
        FinancialCalculator calc(0.05);
        REQUIRE(calc.getInterestRate() == 0.05);
        REQUIRE(calc.getCalculationCount() == 0);
    }    
    SECTION("Zero interest rate") {
        FinancialCalculator calc(0.0);
        REQUIRE(calc.getInterestRate() == 0.0);
    }    
    SECTION("Negative interest rate throws exception") {
        REQUIRE_THROWS_AS(FinancialCalculator(-0.01), std::invalid_argument);
    }
}
TEST_CASE("Compound Interest Calculations", "[compound_interest]") {
    FinancialCalculator calc(0.05);    
    SECTION("Basic compound interest calculation") {
        double interest = calc.calculateCompoundInterest(1000.0, 3);
        REQUIRE(interest == Approx(157.625).epsilon(0.001));
    }    
    SECTION("Zero years returns zero interest") {
        double interest = calc.calculateCompoundInterest(1000.0, 0);
        REQUIRE(interest == 0.0);
    }    
    SECTION("Zero principal returns zero interest") {
        double interest = calc.calculateCompoundInterest(0.0, 5);
        REQUIRE(interest == 0.0);
    }    
    SECTION("One year calculation") {
        double interest = calc.calculateCompoundInterest(1000.0, 1);
        REQUIRE(interest == Approx(50.0).epsilon(0.001));
    }    
    SECTION("Negative principal throws exception") {
        REQUIRE_THROWS_AS(calc.calculateCompoundInterest(-1000.0, 3), std::invalid_argument);
    }    
    SECTION("Negative years throws exception") {
        REQUIRE_THROWS_AS(calc.calculateCompoundInterest(1000.0, -1), std::invalid_argument);
    }
}
TEST_CASE("Portfolio Value Calculations", "[portfolio]") {
    FinancialCalculator calc(0.05);    
    SECTION("Standard portfolio calculation") {
        std::vector<double> portfolio = {1500.0, 2300.0, 980.0, 1200.0};
        double total = calc.calculatePortfolioValue(portfolio);
        REQUIRE(total == 5980.0);
    }    
    SECTION("Single investment portfolio") {
        std::vector<double> portfolio = {2500.0};
        double total = calc.calculatePortfolioValue(portfolio);
        REQUIRE(total == 2500.0);
    }    
    SECTION("Empty portfolio returns zero") {
        std::vector<double> portfolio = {};
        double total = calc.calculatePortfolioValue(portfolio);
        REQUIRE(total == 0.0);
    }    
    SECTION("Portfolio with zero values") {
        std::vector<double> portfolio = {1000.0, 0.0, 500.0};
        double total = calc.calculatePortfolioValue(portfolio);
        REQUIRE(total == 1500.0);
    }    
    SECTION("Negative investment throws exception") {
        std::vector<double> portfolio = {1000.0, -500.0, 800.0};
        REQUIRE_THROWS_AS(calc.calculatePortfolioValue(portfolio), std::invalid_argument);
    }
}
TEST_CASE("Calculation Count Tracking", "[statistics]") {
    FinancialCalculator calc(0.03);    
    SECTION("Count increments with each calculation") {
        REQUIRE(calc.getCalculationCount() == 0);        
        calc.calculateCompoundInterest(1000.0, 2);
        REQUIRE(calc.getCalculationCount() == 1);        
        std::vector<double> portfolio = {1000.0, 2000.0};
        calc.calculatePortfolioValue(portfolio);
        REQUIRE(calc.getCalculationCount() == 2);
    }    
    SECTION("Count can be reset") {
        calc.calculateCompoundInterest(1000.0, 1);
        calc.calculateCompoundInterest(2000.0, 2);
        REQUIRE(calc.getCalculationCount() == 2);        
        calc.resetCalculationCount();
        REQUIRE(calc.getCalculationCount() == 0);
    }
}
/*
✅ Success Checklist
All test cases pass with clear, descriptive names
Edge cases and error conditions are thoroughly tested
Exception handling is properly validated
Test organization follows logical grouping patterns
*/