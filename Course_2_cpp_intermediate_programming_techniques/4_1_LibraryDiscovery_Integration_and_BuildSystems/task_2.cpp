/*
Extend your configuration manager to parse JSON data and provide access to configuration values with proper error handling.

🔍 Practice
Complete the displayConfiguration function in the code below to access and print each JSON value

Implement proper error handling for JSON parsing

Test with both valid and invalid JSON to verify error handling

Experiment with accessing nested JSON objects like the database configuration
*/
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
void displayConfiguration(const json& config) {
    std::cout << "\n=== Configuration Details ===" << std::endl;
    std::cout << "App Name: " << config["app_name"] << std::endl;
    std::cout << "Version: " << config["version"] << std::endl;
    std::cout << "Debug Mode: " << config["debug_mode"] << std::endl;
    std::cout << "Max Connections: " << config["max_connections"] << std::endl;    
    // Access nested objects
    if (config.contains("database")) {
        std::cout << "Database Host: " << config["database"]["host"] << std::endl;
        std::cout << "Database Port: " << config["database"]["port"] << std::endl;
    }
}
int main() {
    std::cout << "Configuration Manager v1.0" << std::endl;    
    std::string configData = R"({
        "app_name": "MyApplication",
        "version": "1.2.3", 
        "debug_mode": true,
        "max_connections": 100,
        "database": {
            "host": "localhost",
            "port": 5432
        }
    })";    
    try {
        json config = json::parse(configData);
        displayConfiguration(config);        
    } catch (const json::exception& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return 1;
    }    
    return 0;
}

// ✅ Success Checklist
// All configuration values are correctly extracted and displayed
 
// Error handling properly catches and reports JSON parsing errors
 
// Nested JSON objects are successfully accessed
 
// Program handles invalid JSON gracefully without crashing