/*
You're building an inventory system that reads product information from a data file. Start by reading product names from a text file.

🔍 Practice
Create a products.txt file with the sample product names and run the code.

What happens if you run the program without creating the file first?

How does the error handling prevent the program from crashing?

Modify the code to read from a different filename and test the error handling.
*/

#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream inputfile("products.txt");
    if (!inputfile.is_open()){
        std::cerr << "Error: could not open the file.\n";
        return 1;
    }
    std::string productName; // or line or any variable name
    int count = 0;
    std::cout << "Product Inventory:" << std::endl;
    while (std::getline(inputfile, productName)){
        count++;
        std::cout << count << ". " << productName << std::endl;
    }
    inputfile.close();
    std::cout << "Total products: " << count << std::endl;
    return 0;

}

/*
✅ Success Checklist
Program displays appropriate error message when file doesn't exist

All product names are read and displayed correctly

Total product count is accurate
*/