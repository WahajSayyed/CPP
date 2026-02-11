/*Create a formatted customer information display using stream manipulators.

🔍 Practice
Run the code below and observe the formatted output.

Complete the code by adding input collection for the customer data.

Combine validation from Task 1 with the formatting from this task.

💻 Code*/
#include <iostream>
#include <iomanip>
#include <string>

int main(){
    std::string name = "John Smith";
    int customerID = 1234;
    double balance = 456.234;
    // Header
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << std::right <<std::setw(30) << "CUSTOMER INFORMATION" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    // Data display
    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::setw(15) << "Customer ID:" << customerID << std::endl;
    std::cout << std::setw(15) << "Balance:" << std::fixed << std::setprecision(2)<< "$" << balance << std::endl;
    return 0;
}

/*
✅ Success Checklist
Output displays in a clean, aligned format

Monetary values show exactly 2 decimal places

Headers and data are properly aligned
*/