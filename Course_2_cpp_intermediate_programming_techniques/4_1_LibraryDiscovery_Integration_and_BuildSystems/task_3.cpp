/*
Enhance your program to read JSON configuration from an external file, making it more practical for real-world use.

🔍 Practice
Using the code provided, implement the loadConfigFromFile function using ifstream

Add error handling for file operations (file not found, permission issues)

Display the configuration loaded from the file

Test with different JSON structures, including arrays
*/

#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
json loadConfigFromFile(const std::string& filename) {
    std::ifstream configFile(filename);
    if (!configFile.is_open()) {
        throw std::runtime_error("Could not open config file: " + filename);
    }    
    json config;
    configFile >> config;
    return config;
}
int main() {
    std::cout << "Configuration Manager v2.0" << std::endl;    
    try {
        // Create sample config file
        std::ofstream configFile("config.json");
        configFile << R"({
            "app_name": "FileBasedApp",
            "version": "2.0.0",
            "debug_mode": false,
            "max_connections": 200,
            "features": ["logging", "caching", "monitoring"]
        })";
        configFile.close();        
        // Load and display configuration
        json config = loadConfigFromFile("config.json");        
        std::cout << "\n=== Configuration from File ===" << std::endl;
        std::cout << "App Name: " << config["app_name"] << std::endl;
        std::cout << "Version: " << config["version"] << std::endl;
        std::cout << "Debug Mode: " << config["debug_mode"] << std::endl;
        std::cout << "Max Connections: " << config["max_connections"] << std::endl;        
        std::cout << "Features: ";
        for (const auto& feature : config["features"]) {
            std::cout << feature << " ";
        }
        std::cout << std::endl;        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }    
    return 0;
}

/*
✅ Success Checklist
Configuration is successfully loaded from external file

File operation errors are properly handled and reported

JSON arrays are correctly processed and displayed

Program works with various JSON file formats

💡 Key Points
External libraries extend C++ functionality without requiring custom implementations

CMake's find_package() simplifies library discovery and linking

Proper error handling is crucial when working with external data sources

JSON parsing libraries provide robust, tested solutions for data interchange

❗ Common Mistakes to Avoid
Forgetting to include the library header files after configuring CMake

Not handling JSON parsing exceptions, leading to program crashes

Incorrectly configuring library paths in CMakeLists.txt

Attempting to access JSON fields without checking if they exist

 🚀 Next Steps

These library integration skills are fundamental in professional software development. You'll use similar techniques to integrate graphics libraries for game development, networking libraries for distributed systems, database libraries for data-driven applications, and testing frameworks for quality assurance. Mastering build system configuration and dependency management will make you more effective in collaborative development environments and open-source contributions.
*/