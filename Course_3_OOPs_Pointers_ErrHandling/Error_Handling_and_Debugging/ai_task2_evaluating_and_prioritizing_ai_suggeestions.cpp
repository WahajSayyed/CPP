/*Practice the critical skill of evaluating AI suggestions and making informed decisions about which improvements to implement.

🔍 Practice
Compare the original and improved versions of the code below to practice evaluation skills:

Step 1: AI Suggestion Evaluation Framework

For each improvement made, analyze:
Impact Assessment: How significantly does this change improve the code?
Implementation Cost: How much effort would this refactoring require?
Risk Analysis: What could go wrong with this change?
Maintenance Benefit: How does this help future development?

Step 2: Decision Making Practice
Create evaluation criteria for AI suggestions:

Evaluation Criteria:

1. Security Impact: Does this address security vulnerabilities?
2. Performance Gain: Does this improve runtime or memory efficiency?
3. Maintainability: Does this make code easier to understand/modify?
4. Testing: Does this improve testability?
5. Standards: Does this align with coding standards?

Decision Matrix:
High Priority: Security + Performance issues
Medium Priority: Maintainability + Standards improvements  
Low Priority: Minor style or preference changes

Step 3: Human vs AI Judgment Scenarios

Practice scenarios where human judgment should override AI:
AI suggests over-engineering for simple use cases
AI recommends patterns that don't fit project architecture
AI flags code that's intentionally written for specific business requirements
AI suggests changes that would break existing interfaces
Document your reasoning for accepting or rejecting different types of suggestions.
💻 Code*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
class ImprovedDataProcessor {
private:
    static const int DEFAULT_FILTER_THRESHOLD = 10;    
    // Helper method for validation (addressing duplication)
    bool validateData(const std::vector<int>& data, const std::string& context) const {
        if (data.empty()) {
            std::cout << context << ": No data available" << std::endl;
            return false;
        }
        return true;
    }    
    // Separate sorting responsibility
    void sortData(std::vector<int>& data) const {
        std::sort(data.begin(), data.end());  // More efficient algorithm
        std::cout << "Data sorted using std::sort" << std::endl;
    }    
    // Separate filtering responsibility  
    std::vector<int> filterData(const std::vector<int>& data, int threshold = DEFAULT_FILTER_THRESHOLD) const {
        std::vector<int> filtered;
        std::copy_if(data.begin(), data.end(), std::back_inserter(filtered),
                     [threshold](int value) { return value > threshold; });        
        std::cout << "Data filtered (values > " << threshold << ")" << std::endl;
        return filtered;
    }    
    // Separate statistics calculation
    void displayStatistics(const std::vector<int>& data) const {
        if (!validateData(data, "Statistics calculation")) return;        
        // Using standard algorithms
        double average = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
        int maximum = *std::max_element(data.begin(), data.end());        
        std::cout << "Average: " << average << std::endl;
        std::cout << "Maximum: " << maximum << std::endl;
    }    
    // Separate display responsibility
    void displayData(const std::vector<int>& data) const {
        std::cout << "Final data: ";
        for (const auto& value : data) {  // Range-based for loop
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }    
public:
    // Refactored main method with single responsibility
    void processData(const std::string& type, std::vector<int> data, bool sortFlag, bool filterFlag) {
        std::cout << "Processing " << type << " data..." << std::endl;        
        if (!validateData(data, "Initial validation")) return;        
        if (sortFlag) {
            sortData(data);
        }        
        if (filterFlag) {
            data = filterData(data);
            if (!validateData(data, "Post-filter validation")) return;
        }        
        displayData(data);
        displayStatistics(data);
    }    
    // Overloaded method for custom filter threshold
    void processData(const std::string& type, std::vector<int> data, bool sortFlag, bool filterFlag, int customThreshold) {
        std::cout << "Processing " << type << " data with custom threshold..." << std::endl;        
        if (!validateData(data, "Initial validation")) return;        
        if (sortFlag) {
            sortData(data);
        }        
        if (filterFlag) {
            data = filterData(data, customThreshold);
            if (!validateData(data, "Post-filter validation")) return;
        }        
        displayData(data);
        displayStatistics(data);
    }
};
int main() {
    ImprovedDataProcessor processor;
    std::vector<int> testData = {15, 3, 8, 12, 1, 20, 7};    
    std::cout << "=== Testing Improved Data Processor ===" << std::endl;
    processor.processData("numerical", testData, true, true);    
    std::cout << "\n=== Testing Custom Threshold ===" << std::endl;  
    processor.processData("numerical", testData, true, true, 5);    
    return 0;
}
/*Task 2 Solution
// Evaluation criteria applied:
// High Priority: Security, Performance, Major anti-patterns
// Medium Priority: Maintainability, Code standards, Readability
// Low Priority: Style preferences, Minor optimizations
// Decision framework:
// Accept: Clear benefit with reasonable implementation cost
// Reject: Low impact or high risk of breaking existing functionality
*/
/*✅ Success Checklist
Clear comparison between original and improved code versions
Systematic evaluation of each refactoring decision
Understanding of when to accept vs. reject AI suggestions
Documented decision-making framework for code improvements*/