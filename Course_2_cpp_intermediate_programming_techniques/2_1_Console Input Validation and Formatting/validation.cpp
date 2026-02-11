/*
You're creating a customer registration system for a retail store. Start by collecting and validating a customer's age.

🔍 Practice
Run the code below and test with invalid inputs like letters, negative numbers, or unrealistic ages.

What happens when you enter text instead of a number?

How does the validation loop handle out-of-range values?

Modify the code to validate a customer ID number (must be between 1000 and 9999).

Test your changes with various inputs.
*/

#include <iostream>
#include <limits>

int main(){
    int id;
    std::cout << "Enter customer age: ";
    int count = 0;
    while (count < 3 && (!(std::cin >> id) || id < 1000 || id > 10000)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        count++;
        std::cout << count;
        std::cout << "Invalid Input. Valid range is between 0 to 120: ";
    }
    std::cout << "Age entered: " << id << std::endl;
    return 0;
}

/*
✅ Success Checklist
Program handles invalid input without crashing

Validation loop continues until valid data is entered

Clear error messages guide the user  
*/