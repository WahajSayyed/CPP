/*
You're developing a configuration management system that needs to read and parse JSON configuration files. You'll integrate the popular nlohmann/json library to handle JSON parsing tasks.

🔍 Practice
Research the nlohmann/json library online and examine its documentation

Complete the CMakeLists.txt file provided to properly find and link the nlohmann/json library

Update main.cpp code below to include the nlohmann/json header and parse the JSON string

Test your integration by compiling and running the program
*/

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main(){
    std::cout << "Configuration Manage v1.0" << std::endl;
    // Sample JSON string representing application configuration
    std::string configData = R"({
        "app_name": "MyApplication",
        "version": "1.2.3",
        "debug_mode": true,
        "max_connections": 100
        })";
    std::cout << "Raw configuration data:" << std::endl;
    std::cout << configData << std::endl;
    std::cout << "Parsed configuraiton data:" << std::endl;
    try{
        json config = json::parse(configData);
        std::cout << "Application Name: " << config["app_name"] << std::endl;
        std::cout << "Version: " << config["version"] << std::endl;
        std::cout << "debug_mode: " << config["debug_mode"] << std::endl;
        std::cout << "max_connections: " << config["max_connections"] << std::endl;
    }
    catch (const json::exception& e){
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return 1;
    }
    return 0;

}