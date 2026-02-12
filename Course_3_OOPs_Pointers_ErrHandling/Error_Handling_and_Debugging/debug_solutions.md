# Task 1 Solution

```// Fixed compound interest calculation
for (int i = 0; i < years; i++) {  // Changed from i <= years
    result = result * (1 + interestRate);
}
// Fixed portfolio calculation  
for (size_t i = 0; i < investments.size(); i++) {  // Changed from i <= 
    total += investments[i];
}
```

# Task 2 Solution
```
// Key testing patterns demonstrated:
TEST_CASE("Descriptive test name", "[tag]") {
    SECTION("Specific scenario") {
        // Test setup
        FinancialCalculator calc(0.05);
        
        // Test execution
        double result = calc.calculateCompoundInterest(1000.0, 3);
        
        // Test verification with appropriate tolerance
        REQUIRE(result == Approx(157.625).epsilon(0.001));
    }
}
```

# Task 3 Solution
```
// Dependency injection constructor pattern:
FinancialCalculator(
    std::shared_ptr<InterestRateProvider> rateProvider,
    std::shared_ptr<CalculationLogger> logger,
    std::shared_ptr<ValidationService> validator
) : rateProvider(rateProvider), logger(logger), validator(validator) {}
// Mock testing pattern:
auto mockLogger = std::make_shared<MockLogger>();
FinancialCalculator testCalc(mockRate, mockLogger, mockValidator);
// Verify mock interactions after test execution
```