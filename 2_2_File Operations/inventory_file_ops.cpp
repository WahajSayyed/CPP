/*
Create a complete system that reads product data and generates a summary report with file existence checking.

🔍 Practice
Run the program and observe how it creates the inventory file if it doesn't exist.

Examine both the input and output files to understand the data flow.

Modify the CSV data and re-run to see how the summary changes.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
int main() {
    const std::string inputFile = "inventory.txt";
    const std::string outputFile = "summary.txt";    
    // Check if input file exists using C++17 filesystem
    if (!std::filesystem::exists(inputFile)) {
        std::cout << "Creating sample inventory file..." << std::endl;        
        std::ofstream createFile(inputFile);
        createFile << "Widget A,25,15.50" << std::endl;
        createFile << "Widget B,40,22.00" << std::endl;
        createFile << "Widget C,15,8.75" << std::endl;
        createFile.close();
    }    
    // Read inventory data
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cerr << "Error opening inventory file" << std::endl;
        return 1;
    }    
    // Process and summarize
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error creating summary file" << std::endl;
        return 1;
    }    
    outFile << "INVENTORY SUMMARY" << std::endl;
    outFile << "=================" << std::endl;    
    std::string line;
    int totalItems = 0;
    double totalValue = 0.0;    
    while (std::getline(inFile, line)) {
        // Simple CSV parsing (find commas)
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);        
        if (firstComma != std::string::npos && secondComma != std::string::npos) {
            std::string name = line.substr(0, firstComma);
            int quantity = std::stoi(line.substr(firstComma + 1, secondComma - firstComma - 1));
            double price = std::stod(line.substr(secondComma + 1));            
            totalItems += quantity;
            totalValue += quantity * price;            
            outFile << "Product: " << name << ", Qty: " << quantity
                    << ", Value: $" << std::fixed << std::setprecision(2)
                    << quantity * price << std::endl;
        }
    }    
    outFile << std::endl << "Total Items: " << totalItems << std::endl;
    outFile << "Total Value: $" << std::fixed << std::setprecision(2) << totalValue << std::endl;    
    inFile.close();
    outFile.close();    
    std::cout << "Inventory summary completed!" << std::endl;
    std::cout << "Check summary.txt for results." << std::endl;    
    return 0;
}

/*
✅ Success Checklist
Program creates sample data file when needed

CSV data is parsed correctly

Summary calculations are accurate

Both input and output operations include error handling

💡 Key Points
Always check if files open successfully using is_open() or boolean conversion

Use std::getline() to read entire lines from text files

std::ios::app flag appends to existing files instead of overwriting

C++17 std::filesystem::exists() safely checks file presence before operations

Close files explicitly or let destructors handle it automatically

❗ Common Mistakes to Avoid
Forgetting to check file open status before using file operations

Not including proper error messages when file operations fail

Using the wrong file path or assuming files exist in specific locations

Mixing text and binary file operations without understanding the differences  

🚀 Next Steps

File I/O skills are essential for building production applications that handle configuration files, user data, logs, and reports. In enterprise software development, you'll use these techniques for database imports, system monitoring, data analysis pipelines, and creating audit trails that maintain business data integrity across application sessions.
*/