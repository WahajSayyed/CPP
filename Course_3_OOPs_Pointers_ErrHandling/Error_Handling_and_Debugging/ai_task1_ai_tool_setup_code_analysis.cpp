/*You're joining a development team that has adopted AI-assisted code review tools. Practice analyzing a C++ class with common quality issues to understand how AI tools identify problems.

🔍 Practice
Analyze the code below systematically, simulating what AI tools would identify:

Step 1: Identify Code Quality Issues
Create a structured analysis document with these categories:
Method Length: Count lines in processData method
Single Responsibility Violations: List multiple tasks performed
Code Duplication: Identify repeated patterns
Magic Numbers: Find hardcoded values
Performance Issues: Spot inefficient algorithms
Modern C++ Usage: Note opportunities for improvement

Step 2: Anti-Pattern Detection
Document these common anti-patterns:
God Method: Methods doing too many things
Copy-Paste Programming: Duplicated code blocks
Magic Numbers: Unexplained constants
Primitive Obsession: Overuse of basic types instead of objects

Step 3: AI Suggestion Simulation
For each issue identified, write what an AI tool might suggest:
Specific refactoring recommendations
Performance improvement opportunities
Code style and readability enhancements
Security or reliability concerns
Use this template for documentation:
Issue Type: [Anti-pattern/Performance/Style/Security]
Location: Line X-Y in method Z
Description: [What the issue is]
AI Suggestion: [What improvement to make]
Priority: [High/Medium/Low]
Rationale: [Why this matters]*/

#include <iostream>
#include <vector>
#include <string>
class DataProcessor {
public:
    // Long method with multiple responsibilities
    void processData(std::string type, std::vector<int> data, bool sortFlag, bool filterFlag) {
        std::cout << "Processing " << type << " data..." << std::endl;        
        // Duplicate validation logic
        if (data.size() == 0) {
            std::cout << "Error: No data to process" << std::endl;
            return;
        }        
        if (sortFlag) {
            // Inefficient sorting implementation
            for (int i = 0; i < data.size(); i++) {
                for (int j = i + 1; j < data.size(); j++) {
                    if (data[i] > data[j]) {
                        int temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
            }
            std::cout << "Data sorted" << std::endl;
        }        
        if (filterFlag) {
            std::vector<int> filtered;
            for (int i = 0; i < data.size(); i++) {
                if (data[i] > 10) {  // Magic number
                    filtered.push_back(data[i]);
                }
            }
            data = filtered;
            std::cout << "Data filtered (values > 10)" << std::endl;
        }        
        // Duplicate validation logic
        if (data.size() == 0) {
            std::cout << "Warning: No data remaining after processing" << std::endl;
            return;
        }        
        // Display results
        std::cout << "Final data: ";
        for (int i = 0; i < data.size(); i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;        
        // Calculate basic stats
        int sum = 0;
        for (int i = 0; i < data.size(); i++) {
            sum += data[i];
        }
        double average = (double)sum / data.size();
        std::cout << "Average: " << average << std::endl;        
        int max = data[0];
        for (int i = 1; i < data.size(); i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        std::cout << "Maximum: " << max << std::endl;
    }
};
int main() {
    DataProcessor processor;
    std::vector<int> testData = {15, 3, 8, 12, 1, 20, 7};    
    processor.processData("numerical", testData, true, true);   
    return 0;
}
/*Task 1 Solution
// Key issues identified in original code:
// 1. Long method (55+ lines) - violates single responsibility
// 2. Code duplication - validation logic repeated
// 3. Performance issues - O(n²) bubble sort algorithm  
// 4. Magic numbers - hardcoded threshold value "10"
// 5. C-style patterns - traditional for loops vs. range-based
// 6. No error handling - missing input validation
*/
/*✅ Success Checklist
Systematic identification of at least 8 distinct code quality issues
Proper categorization of issues by type and severity
Clear documentation following professional review standards
Understanding of what AI tools typically flag in code analysis*/