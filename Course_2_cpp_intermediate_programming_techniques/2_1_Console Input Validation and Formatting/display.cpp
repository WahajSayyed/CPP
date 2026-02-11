/*Build a complete system that collects customer data with validation and displays it professionally.

🔍 Practice
In the code below, complete the validation loops for customerID and balance.
Implement the formatted output section.
Test with various invalid inputs to ensure robustness.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
int main() {
    std::string name;
    int customerID;
    double balance;    
    // Collect customer name
    std::cout << "Enter customer name: ";
    // std::cin.ignore(); // Clear any leftover newline
    std::getline(std::cin, name);    
    std::cout << name;
    // Collect and validate customer ID
    std::cout << "Enter customer ID (1000-9999): ";
    // Your validation code here    
    while (!(std::cin >> customerID)|| customerID < 1000 || customerID > 9999){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Input must be between 1000-9999" << std::endl;
    }
    // Collect and validate balance
    std::cout << "Enter account balance: $";
    // Your validation code here  
    while (!(std::cin >> balance) || balance < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Balance can not be negative." << std::endl;
    } 
    // Display formatted output
    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::setw(15) << "Customer ID:" << customerID << std::endl;
    std::cout << std::setw(15) << "Balance:" << balance << std::endl;
    // Your formatting code here    
    return 0;
}
/*
✅ Success Checklist
All inputs are properly validated

Program handles mixed input types gracefully

Final output is professionally formatted

💡 Key Points
std::cin.clear() resets stream error flags after invalid input

std::cin.ignore() removes unwanted characters from the input buffer

Stream manipulators like std::setw() and std::setprecision() control output formatting

Input validation loops prevent program crashes and ensure data quality

❗ Common Mistakes to Avoid
Forgetting to clear the stream state after invalid input

Not using std::cin.ignore() to clear the input buffer

Mixing std::cin >> and std::getline() without proper buffer management

Setting precision without using std::fixed for consistent decimal places  

🚀 Next Steps

These input validation and formatting skills are fundamental for creating professional business applications. In the software industry, you'll use these techniques when building user interfaces, processing financial data, generating reports, and creating administrative tools where data accuracy and clear presentation are critical for success.
*/