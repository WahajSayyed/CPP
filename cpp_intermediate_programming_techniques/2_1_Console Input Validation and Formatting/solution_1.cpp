#include <iostream>
#include <limits>
int main() {
    int customerID;    
    std::cout << "Enter customer ID (1000-9999): ";
    while (!(std::cin >> customerID) || customerID < 1000 || customerID > 9999) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a customer ID between 1000 and 9999: ";
    }    
    std::cout << "Customer ID entered: " << customerID << std::endl;
    return 0;
}