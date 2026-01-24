#include <iostream>
#include <fstream>
#include <string>
class ResourceHandler {
private:
    std::fstream* fileStream;
    std::string filePath;
    bool isResourceOpen;
public:
    // Default constructor - RAII: Initialize without binding to resource
    ResourceHandler() : fileStream(nullptr), filePath(""), isResourceOpen(false) {
        std::cout << "ResourceHandler created (no resource bound)" << std::endl;
    }    
    // Parameterized constructor - RAII: Acquire resource during initialization
    ResourceHandler(const std::string& path) : filePath(path), isResourceOpen(false) {
        fileStream = new std::fstream();
        fileStream->open(filePath, std::ios::in | std::ios::out | std::ios::app);        
        if (fileStream->is_open()) {
            isResourceOpen = true;
            std::cout << "Resource acquired: " << filePath << std::endl;
        } else {
            std::cout << "Failed to acquire resource: " << filePath << std::endl;
            delete fileStream;
            fileStream = nullptr;
        }
    }    
    // Copy constructor - Safe resource handling
    ResourceHandler(const ResourceHandler& other) : filePath(other.filePath), isResourceOpen(false) {
        fileStream = new std::fstream();
        if (other.isResourceOpen) {
            fileStream->open(filePath, std::ios::in | std::ios::out | std::ios::app);
            if (fileStream->is_open()) {
                isResourceOpen = true;
                std::cout << "Resource copied: " << filePath << std::endl;
            } else {
                std::cout << "Failed to copy resource: " << filePath << std::endl;
                delete fileStream;
                fileStream = nullptr;
            }
        } else {
            fileStream = nullptr;
            std::cout << "Copied ResourceHandler (no active resource)" << std::endl;
        }
    }    
    // Destructor - RAII: Automatic resource cleanup
    ~ResourceHandler() {
        if (isResourceOpen && fileStream) {
            fileStream->close();
            std::cout << "Resource released: " << filePath << std::endl;
        }
        delete fileStream;
        std::cout << "ResourceHandler destroyed" << std::endl;
    }    
    // Method to check if resource is available
    bool isOpen() const {
        return isResourceOpen;
    }    
    // Method to write to resource (demonstrating usage)
    void writeData(const std::string& data) {
        if (isResourceOpen && fileStream) {
            *fileStream << data << std::endl;
            std::cout << "Data written to " << filePath << std::endl;
        } else {
            std::cout << "Cannot write - resource not available" << std::endl;
        }
    }
};
int main() {
    std::cout << "=== Testing ResourceHandler ===" << std::endl;    
    // Test default constructor
    ResourceHandler handler1;
    std::cout << "Handler1 is open: " << handler1.isOpen() << std::endl;    
    // Test parameterized constructor with valid resource
    {
        ResourceHandler handler2("test_file.txt");
        std::cout << "Handler2 is open: " << handler2.isOpen() << std::endl;        
        if (handler2.isOpen()) {
            handler2.writeData("Testing RAII resource management");
        }        
        // Test copy constructor
        ResourceHandler handler3 = handler2;
        std::cout << "Handler3 is open: " << handler3.isOpen() << std::endl;        
        std::cout << "\n=== Objects going out of scope ===" << std::endl;
    } // handler2 and handler3 destructors called here    
    // Test with invalid resource
    ResourceHandler handler4("invalid/path/file.txt");
    std::cout << "Handler4 is open: " << handler4.isOpen() << std::endl;
    handler4.writeData("This should fail");   
    std::cout << "\n=== Program ending ===" << std::endl;
    return 0;
}