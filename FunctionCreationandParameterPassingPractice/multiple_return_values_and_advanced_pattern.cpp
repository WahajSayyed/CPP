/*
Implement functions that return multiple values and demonstrate professional function design patterns.

🔍 Practice
Complete the provided code, and experiment by:

    Adding validation to check if scores are within a reasonable range (0-100)

    Creating a function that returns both the formatted name and a success indicator

Test different scenarios:

    Empty score vectors

    Invalid employee data

    Edge cases with your validation logic
*/

#include <iostream>
#include <string>
#include <vector>
// Struct to return multiple employee statistics
struct EmployeeStats {
    double averageScore;
    double highestScore;
    double lowestScore;
    int totalEvaluations;
};
// Function returning multiple values using a struct
EmployeeStats calculateEmployeeStats(const std::vector<double>& scores) {
    if (scores.empty()) {
        return {0.0, 0.0, 0.0, 0};
    }    
    double sum = 0.0;
    double highest = scores[0];
    double lowest = scores[0];    
    for (double score : scores) {
        sum += score;
        if (score > highest) highest = score;
        if (score < lowest) lowest = score;
    }    
    return {
        sum / scores.size(),  // average
        highest,              // highest
        lowest,               // lowest
        static_cast<int>(scores.size())  // total count
    };
}
// Function that validates and processes employee data
bool processEmployeeData(int& employeeId, std::string& name, double& salary) {
    // Validate input data
    if (employeeId <= 0 || name.empty() || salary < 0) {
        return false;
    }    
    // Process the data (example: format name and adjust salary)
    // Convert name to title case (simplified)
    if (!name.empty()) {
        name[0] = std::toupper(name[0]);
    }    
    // Ensure minimum salary
    if (salary < 30000.0) {
        salary = 30000.0;
    }   
    return true;
}
int main() {
    // Test multiple return values
    std::vector<double> employeeScores = {87.5, 92.0, 78.5, 95.0, 84.0, 89.5};    
    EmployeeStats stats = calculateEmployeeStats(employeeScores);    
    std::cout << "Employee Performance Statistics:" << std::endl;
    std::cout << "Average Score: " << stats.averageScore << std::endl;
    std::cout << "Highest Score: " << stats.highestScore << std::endl;
    std::cout << "Lowest Score: " << stats.lowestScore << std::endl;
    std::cout << "Total Evaluations: " << stats.totalEvaluations << std::endl;    
    // Test validation and processing function
    int id = 0;
    std::string name = "john doe";
    double salary = 25000.0;    
    std::cout << "\nBefore processing:" << std::endl;
    std::cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << std::endl;    
    bool success = processEmployeeData(id, name, salary);    
    if (success) {
        std::cout << "After processing:" << std::endl;
        std::cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << std::endl;
    } else {
        std::cout << "Data processing failed - invalid input" << std::endl;        
        // Try with valid data
        id = 102;
        name = "jane smith";
        salary = 45000.0;        
        std::cout << "\nTrying with valid data:" << std::endl;
        std::cout << "Before: ID: " << id << ", Name: " << name << ", Salary: $" << salary << std::endl;        
        success = processEmployeeData(id, name, salary);
        if (success) {
            std::cout << "After: ID: " << id << ", Name: " << name << ", Salary: $" << salary << std::endl;
        }
    }    
    return 0;
}