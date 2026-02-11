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
    std::getline(std::cin, name);    
    // Collect and validate customer ID
    std::cout << "Enter customer ID (1000-9999): ";
    while (!(std::cin >> customerID) || customerID < 1000 || customerID > 9999) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a customer ID between 1000 and 9999: ";
    }    
    // Collect and validate balance
    std::cout << "Enter account balance: $";
    while (!(std::cin >> balance) || balance < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a positive balance: $";
    }    
    // Display formatted output
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << "CUSTOMER INFORMATION" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;    
    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::setw(15) << "Customer ID:" << customerID << std::endl;
    std::cout << std::setw(15) << "Balance:" << std::fixed << std::setprecision(2) << "$" << balance << std::endl;    
    return 0;
}