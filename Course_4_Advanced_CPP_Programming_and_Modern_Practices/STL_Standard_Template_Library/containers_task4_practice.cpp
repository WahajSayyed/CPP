/*
 * File: sensor_processor.cpp
 * Purpose: This program implements a sensor data processing system
 *          demonstrating STL container selection for different data
 *          access patterns including fast lookups and priority processing.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;

struct SensorReading {
    int sensorId;
    string location;
    string sensorType;
    double value;
    
    SensorReading(int id, string loc, string type, double val)
        : sensorId(id), location(loc), sensorType(type), value(val) {}
//Missing default constructor:
SensorReading(){}
};

struct Alert {
    int priority;
    string message;
    string alertType;
    
    Alert(int p, string msg, string type)
        : priority(p), message(msg), alertType(type) {}
};

class SensorProcessor {
private:
    // TODO: Choose appropriate containers for different access patterns
    // Hint: You'll need containers for ID lookup, location grouping, and priority processing
    
public:
    /**
     * GRADED CHALLENGE 1
     * TASK: Implement addSensorReading to store sensor data with fast ID lookup 
     * and location-based grouping capabilities.
     */
    void addSensorReading(const SensorReading& reading) {
        // YOUR CODE HERE
        // Consider: What containers provide O(1) ID lookup?
        // How can you group sensors by location efficiently?
    }
    
    /**
     * GRADED CHALLENGE 2  
     * TASK: Implement addAlert to store alerts in priority order.
     * Higher priority numbers should be processed first.
     */
    void addAlert(const Alert& alert) {
        // YOUR CODE HERE
        // Consider: Which STL container automatically maintains priority order?
        // Do you need a custom comparator?
    }
    
    /**
     * GRADED CHALLENGE 3
     * TASK: Implement processNextAlert to handle the highest priority alert.
     * Display the alert information and remove it from the queue.
     */
    void processNextAlert() {
        // YOUR CODE HERE
        // Process and display the highest priority alert
        // Format: "Processing Priority [X]: [message] ([type])"
        // Handle empty queue case
    }
    
    /**
     * GRADED CHALLENGE 4
     * TASK: Implement findSensorById for fast sensor lookup by ID.
     * Return pointer to sensor data or nullptr if not found.
     */
    SensorReading* findSensorById(int sensorId) {
        // YOUR CODE HERE
        // Achieve O(1) average case lookup performance
        // Return nullptr if sensor not found
    }
    
    /**
     * GRADED CHALLENGE 5
     * TASK: Implement getSensorsByLocation to return all sensors
     * in a specified building location.
     */
    vector<SensorReading*> getSensorsByLocation(const string& location) {
        // YOUR CODE HERE
        // Return all sensors at the specified location
        // Return empty vector if location not found
    }
    
    /**
     * Function: runTests
     * Description: Test harness to verify basic functionality
     */
    void runTests() {
        cout << "=== Sensor Processing System Tests ===" << endl;
        
        // Add test sensor data
        cout << "Adding sensor readings..." << endl;
        addSensorReading(SensorReading(101, "Building_A", "temperature", 72.5));
        addSensorReading(SensorReading(102, "Building_A", "humidity", 45.2));
        addSensorReading(SensorReading(201, "Building_B", "temperature", 68.1));
        addSensorReading(SensorReading(202, "Building_B", "humidity", 52.7));
        addSensorReading(SensorReading(301, "Building_C", "temperature", 74.3));
        cout << "✓ Sensor data added" << endl;
        
        // Test ID lookup
        cout << "\nTesting ID-based lookup..." << endl;
        auto sensor = findSensorById(102);
        if (sensor != nullptr) {
            cout << "✓ Found sensor " << sensor->sensorId << " in " << sensor->location << endl;
        }
        
        // Test location queries
        cout << "\nTesting location-based queries..." << endl;
        auto buildingASensors = getSensorsByLocation("Building_A");
        cout << "✓ Found " << buildingASensors.size() << " sensors in Building_A" << endl;
        
        // Test priority processing
        cout << "\nTesting priority alert processing..." << endl;
        addAlert(Alert(3, "Temperature threshold exceeded", "WARNING"));
        addAlert(Alert(9, "Critical system failure", "CRITICAL"));
        addAlert(Alert(1, "Low battery detected", "INFO"));
        addAlert(Alert(7, "Network connectivity issue", "ERROR"));
        
        cout << "Processing alerts by priority:" << endl;
        processNextAlert();
        processNextAlert();
        processNextAlert();
        processNextAlert();
        
        cout << "\n=== Testing Complete ===" << endl;
    }
};

/**
 * Function: main
 * Description: Program entry point demonstrating the sensor processing system
 */
int main() {
    cout << "=== Sensor Data Processing System ===" << endl;
    cout << "Demonstrating STL container selection for efficient data processing\n" << endl;
    
    SensorProcessor processor;
    processor.runTests();
    
    return 0;
}
