#include <iostream>
#include <exception>
#include <string>

class BankingException : public std::exception {
private:
    std::string message;
public:
    explicit BankingException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void testBasicException(){
    try {
        throw BankingException("Basic banking error occured");
    } catch (const BankingException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
};

int main() {
    testBasicException();
    return 0;
}

/*🔍 Practice
Run the code and observe how the custom exception is thrown and caught.
Modify the exception message and test again.
Create a second custom exception class called NetworkException following the same pattern.
Test throwing and catching both exception types in the same try-catch block.

✅ Success Checklist
    Custom exception class properly inherits from std::exception
    The what() method returns meaningful error messages
    Both exceptions can be caught and handled appropriately*/