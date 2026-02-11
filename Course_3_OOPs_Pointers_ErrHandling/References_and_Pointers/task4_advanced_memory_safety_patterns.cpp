/*Implement robust memory management patterns that prevent common errors in professional applications.

🔍 Practice
Run the memory safety demonstration using the code below, and observe the safety patterns.

Try adding invalid data to test the validation.

Experiment with finding non-existent sensors to see error handling.*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
struct SensorData {
    string sensorId;
    double reading;
    int batteryLevel;
};
class DataManager {
private:
    vector<SensorData*> sensors;    
public:
    // Add sensor with safety checks
    bool addSensor(const string& id, double reading, int battery) {
        if (id.empty() || battery < 0 || battery > 100) {
            cout << "Invalid sensor data provided" << endl;
            return false;
        }        
        SensorData* newSensor = new SensorData{id, reading, battery};
        sensors.push_back(newSensor);
        cout << "Added sensor: " << id << endl;
        return true;
    }    
    // Find sensor by ID using safe pointer handling
    SensorData* findSensor(const string& id) {
        for (SensorData* sensor : sensors) {
            if (sensor != nullptr && sensor->sensorId == id) {
                return sensor;
            }
        }
        return nullptr;  // Not found
    }    
    // Update sensor reading with reference for efficiency
    bool updateSensorReading(const string& id, double newReading) {
        SensorData* sensor = findSensor(id);
        if (sensor != nullptr) {
            sensor->reading = newReading;
            cout << "Updated " << id << " reading to " << newReading << endl;
            return true;
        }
        cout << "Sensor " << id << " not found" << endl;
        return false;
    }    
    // Display all sensors using const references for read-only access
    void displayAllSensors() const {
        cout << "\n=== All Sensors ===" << endl;
        for (const SensorData* sensor : sensors) {
            if (sensor != nullptr) {
                cout << "ID: " << sensor->sensorId 
                     << " | Reading: " << sensor->reading 
                     << " | Battery: " << sensor->batteryLevel << "%" << endl;
            }
        }
    }    
    // Destructor ensures no memory leaks
    ~DataManager() {
        cout << "Cleaning up DataManager..." << endl;
        for (SensorData* sensor : sensors) {
            if (sensor != nullptr) {
                delete sensor;
            }
        }
        sensors.clear();
    }
};
int main() {
    DataManager manager;    
    // Add sensors to the system
    manager.addSensor("TEMP001", 23.5, 85);
    manager.addSensor("HUM001", 60.2, 92);
    manager.addSensor("", 15.0, 50);  // Invalid - empty ID
    manager.addSensor("PRESS001", 1013.25, 105);  // Invalid - battery > 100    
    manager.displayAllSensors();    
    // Update sensor readings
    manager.updateSensorReading("TEMP001", 24.8);
    manager.updateSensorReading("NONEXISTENT", 0.0);  // Should handle gracefully    
    manager.displayAllSensors();    
    // Demonstrate safe pointer usage
    SensorData* tempSensor = manager.findSensor("TEMP001");
    if (tempSensor != nullptr) {
        cout << "\nFound temperature sensor: " << tempSensor->reading << "°C" << endl;
        // Safe to use tempSensor here
    } else {
        cout << "Temperature sensor not found" << endl;
    }    
    return 0;  // Destructor automatically cleans up memory
}

/*
✅ Success Checklist
Memory allocation and deallocation handled safely

Null pointer checks prevent crashes in all scenarios

Input validation prevents invalid data entry

Automatic cleanup prevents memory leaks

💡 Key Points
References are aliases that cannot be null or reassigned, making them safer for parameter passing

Pointers provide flexibility for dynamic allocation and reassignment but require careful null checking

Always initialize pointers to nullptr or a valid address to prevent undefined behavior

Use const references for read-only access to avoid unnecessary copying

Implement RAII (Resource Acquisition Is Initialization) patterns for automatic cleanup

❗ Common Mistakes to Avoid
Dereferencing null pointers without safety checks

Forgetting to delete dynamically allocated memory, causing memory leaks

Attempting to reassign references (which actually modifies the original variable)

Using uninitialized pointers that contain garbage values

Not setting pointers to nullptr after deletion, creating dangling pointers

 🚀 Next Steps

These memory management skills are essential for developing high-performance applications in embedded systems, game development, and financial software where efficiency and reliability are critical.
Understanding references and pointers prepares you for advanced topics like smart pointers, custom memory allocators, and performance optimization techniques used in professional C++ development.*/