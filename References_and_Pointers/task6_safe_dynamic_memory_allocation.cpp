/*
You're building a data processing system for a research laboratory that handles variable-sized datasets. The system must allocate memory dynamically based on incoming data volume while ensuring robust error handling.

🔍 Practice
Run the provided code and observe the allocation/deallocation process. Think about:
    How does exception handling protect against allocation failures?
    What happens when you enter invalid input (negative numbers, zero)?
Modify the code. Think about:
    Test with very large numbers to trigger allocation failures
    Add logging timestamps for each allocation/deallocation
Test your changes.
*/
#include <iostream>
#include <new>
#include <string>
using namespace std;
// Function to safely allocate memory with error handling
int* createDataArray(int size, const string& arrayName) {
    // Input validation
    if (size <= 0) {
        cout << "Error: Invalid array size " << size << " for " << arrayName << endl;
        return nullptr;
    }    
    try {
        cout << "Allocating " << size << " integers for " << arrayName << "..." << endl;
        int* array = new int[size];        
        cout << "Successfully allocated memory at address: " << array << endl;
        return array;
    }
    catch (const bad_alloc& e) {
        cout << "Memory allocation failed for " << arrayName << ": " << e.what() << endl;
        return nullptr;
    }
}
// Function to safely deallocate memory
void destroyDataArray(int*& array, const string& arrayName) {
    if (array != nullptr) {
        cout << "Deallocating " << arrayName << " at address: " << array << endl;
        delete[] array;
        array = nullptr;  // Prevent dangling pointer
        cout << arrayName << " successfully deallocated and pointer set to null." << endl;
    } else {
        cout << "Warning: " << arrayName << " is already null - no deallocation needed." << endl;
    }
}
int main() {
    cout << "=== Laboratory Data Processing System ===" << endl;    
    int experimentSize;
    cout << "Enter number of data points for experiment: ";
    cin >> experimentSize;    
    // Safe allocation with error handling
    int* experimentData = createDataArray(experimentSize, "ExperimentData");    
    if (experimentData == nullptr) {
        cout << "Failed to allocate experiment data. Exiting." << endl;
        return 1;
    }    
    // Initialize array with sample data
    cout << "Initializing experiment data..." << endl;
    for (int i = 0; i < experimentSize; i++) {
        experimentData[i] = (i + 1) * 10;  // Sample data: 10, 20, 30, ...
    }    
    // Display first few data points
    cout << "First " << min(5, experimentSize) << " data points: ";
    for (int i = 0; i < min(5, experimentSize); i++) {
        cout << experimentData[i] << " ";
    }
    cout << endl;    
    // Process data (simulate some computation)
    cout << "Processing data..." << endl;
    long long sum = 0;
    for (int i = 0; i < experimentSize; i++) {
        sum += experimentData[i];
    }
    cout << "Data processing complete. Sum: " << sum << endl;    
    // Safe cleanup
    destroyDataArray(experimentData, "ExperimentData");    
    return 0;
}

/*✅ Success Checklist
Input validation prevents invalid allocations

Exception handling manages allocation failures gracefully

Memory is properly deallocated, and pointers nullified

The system provides clear feedback about memory operations*/