/*
Create a professional invoice generator using modern C++ formatting features. 

Note: If your compiler doesn't support C++20 std::format, use traditional formatting methods.

🔍 Practice
Run the code to see the formatted invoice output.

Add tax calculation using traditional formatting methods.

If your compiler supports C++20, uncomment the std::format examples and test them.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
// Note: std::format requires C++20. If unavailable, we'll use traditional formatting
// #include <format> // Uncomment if available
struct Product {
    std::string name;
    double price;
    int quantity;
    double total() const { return price * quantity; }
};
int main() {
    std::vector<Product> products = {
        {"Laptop", 999.99, 2},
        {"Mouse", 29.50, 5},
        {"Keyboard", 89.99, 3}
    };    
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "INVOICE SUMMARY" << std::endl;
    std::cout << std::string(50, '=') << std::endl;    
    // Traditional formatting (works on all compilers)
    std::cout << std::left << std::setw(15) << "Product"
              << std::right << std::setw(8) << "Price"
              << std::right << std::setw(8) << "Qty"
              << std::right << std::setw(10) << "Total" << std::endl;
    std::cout << std::string(50, '-') << std::endl;    
    double grandTotal = 0.0;
    for (const auto& product : products) {
        std::cout << std::left << std::setw(15) << product.name
                  << std::right << std::setw(7) << std::fixed << std::setprecision(2)
                  << "$" << product.price
                  << std::right << std::setw(8) << product.quantity
                  << std::right << std::setw(9) << "$" << std::fixed
                  << std::setprecision(2) << product.total() << std::endl;
        grandTotal += product.total();
    }    
    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::right << std::setw(41) << "GRAND TOTAL: $"
              << std::fixed << std::setprecision(2) << grandTotal << std::endl;    
    // Modern formatting example (uncomment if C++20 is available)
    /*
    std::cout << std::format("Tax (8.5%): ${:.2f}\n", grandTotal * 0.085);
    std::cout << std::format("Final Total: ${:.2f}\n", grandTotal * 1.085);
    */    
    return 0;
}

/*
✅ Success Checklist
Invoice displays with proper alignment and formatting

Monetary values show exactly 2 decimal places

Professional-looking output with headers and totals
*/