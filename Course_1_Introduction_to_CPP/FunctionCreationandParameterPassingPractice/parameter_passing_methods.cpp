/*
Now implement functions that demonstrate different parameter passing techniques for efficiency and modification control.

🔍 Practice
Complete and test the provided code, then experiment by:

Adding a function that calculates the average of scores using const reference

Creating a function that increases all scores by a fixed amount using reference

Observe how:

The const reference prevents accidental modification of input data

Pass-by-reference allows functions to modify the original variables
*/

#include <iostream>
#include <string>
#include <vector>

//Function using const reference for efficiency (no copying, no modification)
void printEmployeeReport(const std::string& name, const std::vector<double>& scores){
    std::cout << "Performance Report for: " << name << std::endl;
    std::cout << "Scores: ";
    for (double score : scores){
        std::cout << score << " ";
    }
    std::cout << std::endl;
}
// Function using reference to modify original data
void applyRaise(double& salary, double percentage){
    salary = salary * (1.0 + percentage / 100.0);
}
// Function using reference to modify vectore elements
void normalizeScore(std::vector<double>& scores){
    if (scores.empty()) return;
    // Find maximum score
    double maxScore = scores[0];
    for (double score : scores){
        if (score > maxScore) {
            maxScore = score;
        }
    }
    // Normalize all scores to percentage of maximum
    for (double& score : scores) {
        score = (score / maxScore) * 100.0;
    }
}

int main() {
    std::string employeeName = "Wahaj Sayyed";
    std::vector<double> performaceScores = {85.0, 92, 786.0};
    double currentSalary = 99990.0;
    // Test const reference function
    printEmployeeReport(employeeName, performaceScores);
    // Test reference modification
    std::cout << "Original salary: $" << currentSalary << std::endl;
    applyRaise(currentSalary, 30.0); //30% raise
    std::cout << "After raise: $" << currentSalary << std::endl;
    std::cout << "\nOriginal scores: ";
    for (double score : performaceScores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    normalizeScore(performaceScores);
    std::cout << "Normalized scores: ";
    for (double score : performaceScores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    return 0;
}