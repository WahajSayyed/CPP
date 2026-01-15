/*
Extend the inventory system to generate a sales report file with product sales data.

🔍 Practice
Run the provided code and open the generated sales_report.txt file to view the formatted output.

Add more product entries to the report.

Modify the code to append new entries to an existing report using std::ios::app.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(){
    std::ofstream reportFile("sales_report.txt");
    if (!reportFile){
        std::cerr << "Error: Could not create sales report.";
        return 1;
    }
    // Write report header
    reportFile << "DAILY SALES REPORT" << std::endl;
    reportFile << "==================" << std::endl;
    reportFile << std::left << std::setw(15) << "Product"
               << std::setw(10) << "Quality"
               << std::setw(10) << "Price" << std::endl;
    //Sample sales data
    reportFile << std::left << std::setw(15) << "Laptop"
               << std::setw(10) << "5"
               << "$" << std::fixed << std::setprecision(2) << 999.999 << std::endl;
    reportFile << std::left << std::setw(15) << "Mouse"
               << std::setw(10) << "12"
               << "$" << std::fixed << std::setprecision(2) << 29.999 << std::endl;
    reportFile.close();
    std::cout << "Sales report generated successfully!" << std::endl;
    return 0;
}

/*
✅ Success Checklist
Report file is created successfully

Data is properly formatted and aligned

File operations handle errors gracefully  
*/