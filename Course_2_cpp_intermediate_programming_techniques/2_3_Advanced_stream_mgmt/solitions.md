## Task 1 Solution

```
// Add product name validation:
std::string productName;
std::cout << "Enter product name: ";
std::cin.ignore(); // Clear any remaining newline
do {
    std::getline(std::cin, productName);
    if (productName.empty()) {
        std::cerr << "Error: Product name cannot be empty." << std::endl;
        std::cout << "Enter product name: ";
    }
} while (productName.empty());
```

## Task 2 Solution

```
// Add tax calculation with traditional formatting:
double taxRate = 0.085;
double tax = grandTotal * taxRate;
double finalTotal = grandTotal + tax;
std::cout << std::right << std::setw(34) << "Tax (8.5%): $"
          << std::fixed << std::setprecision(2) << tax << std::endl;
std::cout << std::right << std::setw(34) << "FINAL TOTAL: $"
          << std::fixed << std::setprecision(2) << finalTotal << std::endl;
```

## Task 3 Solution
```
// ZIP code validation function:
bool validateZip(const std::string& zip) {
    std::regex zip_pattern(R"(\d{5}(-\d{4})?)");
    return std::regex_match(zip, zip_pattern);
}
// Usage in main():
std::string zipCode;
do {
    std::cout << "Enter ZIP code (12345 or 12345-6789): ";
    std::getline(std::cin, zipCode);    
    if (!validateZip(zipCode)) {
        std::cerr << "Error: Invalid ZIP code format." << std::endl;
    }
} while (!validateZip(zipCode));
```