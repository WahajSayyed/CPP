/*
Build a customer registration system that validates email addresses and phone numbers using regular expressions.

🔍 Practice
Run the program below and test with various invalid inputs:

Try invalid email formats (missing @, missing domain)

Try invalid phone numbers (wrong number of digits)

Try names with numbers or special characters

Add validation for a ZIP code (5 digits or 5+4 format: 12345 or 12345-6789).
*/
#include <iostream>
#include <string>
#include <regex>
bool validateEmail(const std::string& email) {
    // Basic email pattern: username@domain.extension
    std::regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, email_pattern);
}
bool validatePhone(const std::string& phone) {
    // US phone pattern: (123) 456-7890 or 123-456-7890
    std::regex phone_pattern(R"((\d3
\d{3}
\s?|\d{3}[-.]?)\d{3}[-.]?\d{4})");
    return std::regex_match(phone, phone_pattern);
}
bool validateName(const std::string& name) {
    // Name should contain only letters and spaces, at least 2 characters
    std::regex name_pattern(R"([a-zA-Z\s]{2,})");
    return std::regex_match(name, name_pattern) && !name.empty();
}
int main() {
    std::string name, email, phone;    
    // Validate name
    do {
        std::cout << "Enter full name: ";
        std::getline(std::cin, name);        
        if (!validateName(name)) {
            std::cerr << "Error: Name must contain only letters and spaces (minimum 2 characters)." << std::endl;
        }
    } while (!validateName(name));   
    // Validate email
    do {
        std::cout << "Enter email address: ";
        std::getline(std::cin, email);        
        if (!validateEmail(email)) {
            std::cerr << "Error: Invalid email format. Use: user@domain.com" << std::endl;
        }
    } while (!validateEmail(email));    
    // Validate phone
    do {
        std::cout << "Enter phone number (123-456-7890 or (123) 456-7890): ";
        std::getline(std::cin, phone);        
        if (!validatePhone(phone)) {
            std::cerr << "Error: Invalid phone format. Use: 123-456-7890 or (123) 456-7890" << std::endl;
        }
    } while (!validatePhone(phone));    
    // Display success message with formatted output
    std::cout << "\nRegistration successful!" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Customer Information:" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    std::cout << "Name:  " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << std::string(40, '=') << std::endl;    
    return 0;
}

/*
✅ Success Checklist
All validation functions work correctly

Clear error messages guide users

Program continues until valid input is provided

Final output is professionally formatted

💡 Key Points
std::cin.clear() resets error flags, std::cin.ignore() clears the input buffer

Regular expressions provide powerful pattern matching for input validation

Raw string literals R"(...)" make regex patterns more readable

Modern formatting features improve output quality and code maintainability

Comprehensive error handling prevents crashes and guides users

❗ Common Mistakes to Avoid
Forgetting to clear both error flags AND the input buffer after invalid input

Using complex regex patterns without testing edge cases thoroughly

Not providing clear error messages that guide users toward correct input format

Mixing std::cin >> and std::getline() without proper buffer management

🚀 Next Steps
These advanced I/O and validation techniques are essential for building enterprise-grade applications. In professional software development, you'll use these skills to create data processing systems, user interfaces, API endpoints, and configuration management tools where input validation and error handling are critical for maintaining system reliability and security.
*/