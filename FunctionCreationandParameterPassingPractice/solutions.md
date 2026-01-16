### Task 1 Solution
```
#include <iostream>
#include <string>
void displayEmployee(int id, std::string name, double salary) {
    std::cout << "Employee ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Salary: $" << salary << std::endl;
    std::cout << "------------------------" << std::endl;
}
double calculateAnnualSalary(double monthlySalary) {
    return monthlySalary * 12;
}
double calculateBonus(double salary) {
    return salary * 0.10; // 10% bonus
}
int main() {
    displayEmployee(101, "Alice Johnson", 5500.0);    
    double monthly = 4200.0;
    double annual = calculateAnnualSalary(monthly);
    double bonus = calculateBonus(monthly);    
    std::cout << "Monthly: $" << monthly << std::endl;
    std::cout << "Annual: $" << annual << std::endl;
    std::cout << "Bonus: $" << bonus << std::endl;    
    return 0;
}
```

### Task 2 Solution
```
// Add to the existing code:
double calculateAverageScore(const std::vector<double>& scores) {
    if (scores.empty()) return 0.0;    
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}
void increaseAllScores(std::vector<double>& scores, double increment) {
    for (double& score : scores) {
        score += increment;
        // Optional: cap at maximum value
        if (score > 100.0) score = 100.0;
    }
}
```

### Task 3 Solution

// The provided code is complete and demonstrates all concepts.
// Students should focus on understanding the struct return type
// and the validation patterns shown in processEmployeeData.