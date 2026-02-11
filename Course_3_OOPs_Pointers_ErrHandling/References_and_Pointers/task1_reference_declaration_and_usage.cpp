/*
You're developing a scientific data processing application where large datasets need to be processed efficiently. References allow you to work with data without creating expensive copies.

🔍 Practice
Run the provided code and observe the output. Think about:

How do references avoid copying the entire DataPoint structure?

What happens when you modify data through the reference?

Modify the code. Think about:

Add another DataPoint and create a reference to it

Try to reassign the reference to point to the new DataPoint (this will show you a key limitation)

Test your changes.*/
#include <iostream>
#include <string>
using namespace std;

struct DataPoint {
    double value;
    string label;
    int timestamp;
};

// Function using reference for efficient parameter passing
void processDatapoint(DataPoint& data) {
    data.value *= 1.1; // Applu 10% scaling factor
    data.timestamp += 1000; // Update timestamp
    cout << "Processes: " << data.label << " = " << data.value << endl;
}

// Function usign const reference for read-only access
void displayDataPoint(const DataPoint& data) {
    cout << "Data: " << data.label << " | Value: " << data.value
         << " | Time: " << data.timestamp << endl;
}

int main() {
    DataPoint sensor1 = {25.5, "Temperature", 1000};
    cout << "=== Before Processing ===" << endl;
    displayDataPoint(sensor1);
    // Create reference to the data point
    DataPoint& sensorRef = sensor1;
    cout << "Reference value: " << sensorRef.value << endl;
    cout << "Original and Reference have same address: "
         << (&sensor1 == &sensorRef ? "true" : "false") << endl;
    processDatapoint(sensorRef);
    cout << "\n=== After Processing ===" << endl;
    displayDataPoint(sensor1); // Shows modified values
    return 0;
}

/*
✅ Success Checklist
References are declared and used correctly

Data modifications through references affect the original variables

Understanding that references cannot be reassigned after initialization*/