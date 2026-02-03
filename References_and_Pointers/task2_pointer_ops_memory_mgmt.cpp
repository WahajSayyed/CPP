/*
The data processing system needs to handle dynamic datasets of varying sizes. Pointers provide the flexibility needed for dynamic memory allocation.

🔍 Practice
Complete the provided code to achieve safe dynamic memory management.

Test and modify it by creating additional data points.

Reflect using prompts:

Why do we check for nullptr before dereferencing?

What's the difference between the address stored in a pointer and the address of the pointer itself?*/

#include <iostream>
#include <string>
using namespace std;
struct DataPoint {
    double value;
    string label;
    int timestamp;
};
// Function to create a new data point dynamically
DataPoint* createDataPoint(double val, const string& lbl, int time) {
    DataPoint* newData = new DataPoint;
    newData->value = val;
    newData->label = lbl;
    newData->timestamp = time;    
    cout << "Created data point at address: " << newData << endl;
    return newData;
}
// Function to safely delete a data point
void deleteDataPoint(DataPoint*& dataPtr) {
    if (dataPtr != nullptr) {
        cout << "Deleting data point: " << dataPtr->label << endl;
        delete dataPtr;
        dataPtr = nullptr;  // Prevent dangling pointer
    }
}
int main() {
    // Create data points using pointers
    DataPoint* humidity = createDataPoint(65.2, "Humidity", 2000);
    DataPoint* pressure = createDataPoint(1013.25, "Pressure", 2000);    
    // Access data through pointers
    if (humidity != nullptr) {
        cout << "Humidity: " << humidity->value << "%" << endl;
        cout << "Address stored in humidity pointer: " << humidity << endl;
        cout << "Address of humidity pointer itself: " << &humidity << endl;        
        // Modify value through pointer
        humidity->value += 5.0;
        cout << "Updated humidity: " << humidity->value << "%" << endl;
    }    
    // Pointer arithmetic demonstration
    cout << "\n=== Pointer Arithmetic ===" << endl;
    DataPoint data[3] = {
        {10.5, "Sensor1", 1000},
        {20.3, "Sensor2", 1001},
        {30.8, "Sensor3", 1002}
    };    
    DataPoint* arrayPtr = data;  // Points to first element
    for (int i = 0; i < 3; i++) {
        cout << "Element " << i << ": " << arrayPtr->label 
             << " = " << arrayPtr->value << endl;
        arrayPtr++;  // Move to next element
    }    
    // Clean up dynamically allocated memory
    deleteDataPoint(humidity);
    deleteDataPoint(pressure);    
    // Verify pointers are now null
    cout << "Humidity pointer after deletion: " << humidity << endl;
    cout << "Pressure pointer after deletion: " << pressure << endl;    
    return 0;
}
/*
✅ Success Checklist
Pointers are declared and initialized correctly

Dynamic memory allocation and deallocation work properly

Null pointer checks prevent crashes

Understanding of pointer arithmetic for array traversal*/