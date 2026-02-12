/*You're working on a financial calculation system that has critical bugs affecting transaction processing. Use systematic debugging techniques to identify and resolve these issues.

🔍 Practice
Compile the program below with debugging symbols enabled:
g++ -g -o financial_calc financial_calc.cpp
Use GDB to debug systematically:
    Set strategic breakpoints at the beginning of each calculation method
    Inspect variables during loop execution to identify the off-by-one error
    Monitor memory access in the portfolio calculation method
    Use the call stack to understand function execution flow
    Step through the code line by line to observe variable state changes

Debug the compound interest bug by examining the loop condition and expected vs. actual iterations.
Debug the portfolio calculation by checking array bounds and access patterns.
Document your debugging process and the fixes you applied.*/

#include <iostream>
#include <vector>
#include <string>
class FinancialCalculator {
private:
    double interestRate;
    int calculationCount;    
public:
    FinancialCalculator(double rate) : interestRate(rate), calculationCount(0) {}   
    // Bug: Compound interest calculation has logic error
    double calculateCompoundInterest(double principal, int years) {
        calculationCount++;
        double result = principal;        
        // Intentional bug: off-by-one error in loop
        for (int i = 0; i < years; i++) {
            result = result * (1 + interestRate);
        }        
        return result - principal; // Return only the interest earned
    }    
    // Bug: Memory access issue with portfolio calculations
    double calculatePortfolioValue(const std::vector<double>& investments) {
        calculationCount++;
        double total = 0.0;        
        // Intentional bug: potential out-of-bounds access
        for (size_t i = 0; i <= investments.size(); i++) {
            total += investments[i];
        }        
        return total;
    }    
    void displayStats() const {
        std::cout << "Calculations performed: " << calculationCount << std::endl;
        std::cout << "Interest rate: " << interestRate * 100 << "%" << std::endl;
    }
};
int main() {
    FinancialCalculator calculator(0.05); // 5% interest rate    
    // Test compound interest calculation
    std::cout << "Testing compound interest calculation:" << std::endl;
    double interest = calculator.calculateCompoundInterest(1000.0, 3);
    std::cout << "Interest earned: $" << interest << std::endl;    
    // Test portfolio calculation
    std::cout << "\nTesting portfolio calculation:" << std::endl;
    std::vector<double> portfolio = {1500.0, 2300.0, 980.0, 1200.0};
    double totalValue = calculator.calculatePortfolioValue(portfolio);
    std::cout << "Total portfolio value: $" << totalValue << std::endl;    
    calculator.displayStats();    
    return 0;
}
/*
✅ Success Checklist
Breakpoints correctly placed at critical code sections
Variable inspection reveals the logic errors in both methods
Memory access violations identified and resolved
Both calculation methods produce mathematically correct results*/