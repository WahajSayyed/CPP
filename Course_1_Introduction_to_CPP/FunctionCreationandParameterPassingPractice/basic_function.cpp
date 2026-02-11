/*
You're developing a simple employee management system. Start by creating functions that handle basic employee data operations.

🔍 Practice
Run the provided code and observe the output. Think about:

How does pass-by-value work for the string parameter in displayEmployee?

What happens to the original variables after the function calls?

Modify the code by:

Adding a function calculateBonus that takes a salary and returns 10% as a bonus

Testing your new function with different salary values
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
//Function to display employee information (pass-by-value)
void displayEmployee(int id, std::string name,  double salary){
    std::cout << "Employee ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Salary: $" << salary << std::endl;
    std::cout << "-----------------------" << std::endl;
}

// Function to calculate annual salary from monthly salary 
 double calculateAnnualSalary( double monthlySalary){
    return monthlySalary * 12;
}

int main(){
    // Test the function
    displayEmployee(1, "Wahaj Sayyed", 100000000000000000000.0);
     double monthly = 10000000000000000000.0;
     double annual = calculateAnnualSalary(monthly);
     std::cout << std::fixed << std::setprecision(0);
    std::cout << "Monthly: $" << monthly << " -> Annual: $" << annual << std::endl;
    return 0;
}

/*
Success Checklist
The display Employee function correctly shows all employee information

The calculate Annual Salary function returns the correct result

Your calculate Bonus function works with different salary inputs*/