/*
You're building a digital asset management system for a creative agency that needs to track various digital resources like images, videos, and documents. Create a DigitalAsset class that properly manages the lifecycle of these assets.

🔍 Practice
Run the code below and observe the constructor and destructor messages. Think about:

How does each constructor type initialize the object differently?

When are destructors called and in what order?

Modify the code to experiment with:

Adding validation in the parameterized constructor (reject negative file sizes)

Creating arrays of objects to see multiple constructor/destructor calls

Adding more functionality like file extension validation
*/

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
class DigitalAsset {
private:
    std::string fileName;
    std::string fileType;
    double fileSizeMB;
    std::string creationDate;
    bool isActive;
    static int totalAssets; // Track total number of assets created

public:
    // Default constructor
    DigitalAsset() : fileName("untitled"), fileType("ünknown"), fileSizeMB(0.0), isActive(true) {
        // Get current date for creation timestamp
        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        creationDate = std::ctime(&time_t);
        creationDate.pop_back(); // Remove newline
        totalAssets++;
        std::cout << "✓ Default asset created: " << fileName << " | Total assets: " << totalAssets << std::endl;
    }
    // Parameterized constructor
    DigitalAsset(const std::string& name, const std::string& type, double size)
        : fileName(name), fileType(type), fileSizeMB(size), isActive(true) {
        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        creationDate = std::ctime(&time_t);
        creationDate.pop_back(); // Remove newline
        totalAssets++;
        std::cout <<  "✓ Asset created: " << fileName << " (" << fileType << ") | Total assets: " << totalAssets << std::endl;
        }
    // Copy constructor
    DigitalAsset(const DigitalAsset& other)
        : fileName(other.fileName + "_copy"), fileType(other.fileType),
          fileSizeMB(other.fileSizeMB), creationDate(other.creationDate), isActive(other.isActive) {
        totalAssets++;
        std::cout << "✓ Asset copied: " << fileName << " from " << other.fileName
                  << " | Total assets: " << totalAssets << std::endl;
          }
    ~DigitalAsset() {
        totalAssets--;
        std::cout << "✗ Asset destroyed: " << fileName << " | Remaining assets: " << totalAssets << std::endl;
    }
    // Member functions
    void displayInfo() const {
        std::cout << "Asset: " << fileName << " [" << fileType << "] - "
        << fileSizeMB << "MB - Created: " << creationDate
        << " - Status: " << (isActive ? "Active" : "Archived") << std::endl;
    }
    void archive() {
        isActive = false;
        std::cout << "Asset " << fileName << " has been archived." << std::endl;
    }
    static int getTotalAssets(){
        return totalAssets;
    }
};
// Initialize static member
int DigitalAsset::totalAssets = 0;
int main(){
    std::cout << "=== Digital Asset Management System ===" << std::endl;
    std::cout << "Initial total assets: " << DigitalAsset::getTotalAssets()  << std::endl << std::endl;
    // Test default constructor
    std::cout << "1. Creating default asset:" << std::endl;
    DigitalAsset defaultAsset;
    defaultAsset.displayInfo();
    std::cout << std::endl;
    // Test parameterized constructor
    std::cout << "2. Creating specific assets:" << std::endl;
    DigitalAsset logo("company_log.png", "image", 2.5);
    DigitalAsset video("promo_video.mp4", "video", 150.0);
    logo.displayInfo();
    video.displayInfo();
    std::cout << std::endl;
    // Test copy constructor to demonstrate lifecycle
    std::cout << "3. Testing copy contructor:" << std::endl;
    {
        DigitalAsset logoCopy = logo; // Copy constructor called
        logoCopy.displayInfo();
        logoCopy.archive();
        std::cout << "--- logoCopy going out of scope ---" << std::endl;
    } // logoCopy destructor called here
    std::cout << "\n4. Final status:" << std::endl;
    std::cout << "Total assets remaining: " << DigitalAsset::getTotalAssets() << std::endl;
    std::cout << "\n=== Program ending - remaining objects will be destroyed ===" << std::endl;
    return 0;
}

/*
✅ Success Checklist
All constructor types are implemented and working correctly

Destructors are called automatically when objects go out of scope

Object creation and destruction messages are properly displayed

Static member tracking works correctly across all instances
*/
