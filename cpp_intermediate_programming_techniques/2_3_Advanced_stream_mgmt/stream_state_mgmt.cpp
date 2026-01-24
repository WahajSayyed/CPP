/*
You're building a data entry system that must handle invalid input gracefully. Start with basic stream state management and error recovery.

🔍 Practice
Run the provided code and test with various invalid inputs:

Try entering text instead of numbers

Try entering negative values

What happens when you enter valid data?

Modify the code to also validate a product name (must not be empty).
*/

#include <iostream>
#include <limits>
#include <string>

int main(){
    double price;
    int quantity;
    std::cout << "Enter product price: $";
    while (!(std::cin >> price)|| price < 0){
        if (std::cin.fail()){
            std::cerr << "Error: Invalid price format" << std::endl;
            std::cin.clear(); //Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cerr << " Error: Price can not be negative." << std::endl;
        }
        std::cout << "Enter product price: $";
    }
    std::cout << "Enter quantity: ";
    while (!(std::cin >> quantity) || quantity < 1){
        if (std::cin.fail()){
            std::cerr << "Error: Invalid quantity format." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cerr << "Error: Quantity must be at least 1." << std::endl;
        }
        std::cout << "Enter quantity: ";
    }
    std::cout << "Valid input received!" << std::endl;
    std::cout << "Price: $" << price << ", Quantity: " << quantity << std::endl;
    return 0;
}

/*
✅ Success Checklist
The program handles invalid input without crashing

Clear error messages guide users to correct input

Stream state is properly reset after errors
*/