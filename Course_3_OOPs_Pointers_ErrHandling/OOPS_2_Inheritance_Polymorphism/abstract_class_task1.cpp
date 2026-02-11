/*Build a comprehensive device management system for an IT company using abstract base classes and interface design. 
Create contracts that all devices must implement while allowing specialized behavior.

🔍 Practice
Build and test the abstract class foundation using the code below:
    Try to instantiate Device directly (should fail - abstract class)
    Create Smartphone and Laptop objects with different specifications
    Call pure virtual functions through base class pointers
    Verify that all interface contracts are properly implemented

Explore multiple inheritance behavior:
    Access methods from different interfaces on the same object
    Test interface-specific behavior through different pointer types
    Observe how virtual destructors work in multiple inheritance scenarios*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <typeinfo>
using namespace std;
// Abstract base class defining core device contract
class Device {
protected:
    string deviceID;
    string manufacturer;
    bool powered;    
public:
    Device(const string& id, const string& mfg) 
        : deviceID(id), manufacturer(mfg), powered(false) {
        cout << "Device registered: " << deviceID << " by " << manufacturer << endl;
    }    
    // Virtual destructor essential for polymorphic cleanup
    virtual ~Device() {
        cout << "Device unregistered: " << deviceID << endl;
    }    
    // Pure virtual functions - must be implemented by derived classes
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void displayStatus() const = 0;
    virtual string getDeviceType() const = 0;    
    // Virtual function with default implementation
    virtual void performDiagnostic() const {
        cout << "Running standard diagnostic on " << deviceID << endl;
        cout << "Power status: " << (powered ? "ON" : "OFF") << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }    
    // Non-virtual utility methods
    string getDeviceID() const { return deviceID; }
    string getManufacturer() const { return manufacturer; }
    bool isPowered() const { return powered; }
};
// Interface for network-enabled devices
class NetworkCapable {
public:
    virtual ~NetworkCapable() = default;
    virtual void connect(const string& network) = 0;
    virtual void disconnect() = 0;
    virtual bool isConnected() const = 0;
    virtual string getIPAddress() const = 0;
};
// Interface for devices with charging capability
class Chargeable {
public:
    virtual ~Chargeable() = default;
    virtual void startCharging() = 0;
    virtual void stopCharging() = 0;
    virtual int getBatteryLevel() const = 0;
    virtual bool isCharging() const = 0;
};
// Interface for devices with storage capability
class StorageCapable {
public:
    virtual ~StorageCapable() = default;
    virtual void writeData(const string& data) = 0;
    virtual string readData(const string& filename) = 0;
    virtual long getStorageCapacity() const = 0;
    virtual long getAvailableStorage() const = 0;
};
// Concrete implementation: Smartphone
class Smartphone : public Device, public NetworkCapable, public Chargeable, public StorageCapable {
private:
    bool networkConnected;
    string ipAddress;
    int batteryLevel;
    bool charging;
    long storageCapacity;
    long usedStorage;    
public:
    Smartphone(const string& id, const string& mfg, long storage) 
        : Device(id, mfg), networkConnected(false), ipAddress(""),
          batteryLevel(100), charging(false), storageCapacity(storage), usedStorage(0) {
        cout << "Smartphone initialized with " << storage << "GB storage" << endl;
    }    
    ~Smartphone() {
        cout << "Smartphone " << deviceID << " powering down" << endl;
    }    
    // Implement Device interface
    void turnOn() override {
        powered = true;
        cout << "📱 Smartphone " << deviceID << " powered on" << endl;
        cout << "OS booting... Welcome screen displayed" << endl;
    }    
    void turnOff() override {
        powered = false;
        networkConnected = false;
        cout << "📱 Smartphone " << deviceID << " shutting down" << endl;
    }    
    void displayStatus() const override {
        cout << "\n--- Smartphone Status ---" << endl;
        cout << "ID: " << deviceID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Power: " << (powered ? "ON" : "OFF") << endl;
        cout << "Network: " << (networkConnected ? "Connected (" + ipAddress + ")" : "Disconnected") << endl;
        cout << "Battery: " << batteryLevel << "%" << (charging ? " (Charging)" : "") << endl;
        cout << "Storage: " << usedStorage << "/" << storageCapacity << "GB used" << endl;
    }    
    string getDeviceType() const override {
        return "Smartphone";
    }    
    // Implement NetworkCapable interface
    void connect(const string& network) override {
        if (powered) {
            networkConnected = true;
            ipAddress = "192.168.1." + to_string(rand() % 254 + 1);
            cout << "📶 Connected to " << network << " (IP: " << ipAddress << ")" << endl;
        } else {
            cout << "❌ Cannot connect - device is powered off" << endl;
        }
    }    
    void disconnect() override {
        networkConnected = false;
        ipAddress = "";
        cout << "📵 Network disconnected" << endl;
    }    
    bool isConnected() const override {
        return networkConnected;
    }    
    string getIPAddress() const override {
        return ipAddress;
    }    
    // Implement Chargeable interface
    void startCharging() override {
        charging = true;
        cout << "🔋 Charging started - current level: " << batteryLevel << "%" << endl;
    }    
    void stopCharging() override {
        charging = false;
        cout << "🔌 Charging stopped - battery level: " << batteryLevel << "%" << endl;
    }    
    int getBatteryLevel() const override {
        return batteryLevel;
    }    
    bool isCharging() const override {
        return charging;
    }    
    // Implement StorageCapable interface
    void writeData(const string& data) override {
        if (powered && usedStorage < storageCapacity) {
            usedStorage += data.length() / (1024 * 1024); // Simulate MB usage
            cout << "💾 Data written to storage: " << data.substr(0, 20) << "..." << endl;
        } else {
            cout << "❌ Cannot write - device off or storage full" << endl;
        }
    }    
    string readData(const string& filename) override {
        if (powered) {
            cout << "📂 Reading file: " << filename << endl;
            return "File content from " + filename;
        }
        cout << "❌ Cannot read - device is powered off" << endl;
        return "";
    }    
    long getStorageCapacity() const override {
        return storageCapacity;
    }    
    long getAvailableStorage() const override {
        return storageCapacity - usedStorage;
    }    
    // Smartphone-specific methods
    void makeCall(const string& number) {
        if (powered && networkConnected) {
            cout << "📞 Calling " << number << "..." << endl;
        } else {
            cout << "❌ Cannot make call - check power and network" << endl;
        }
    }    
    void sendMessage(const string& message) {
        if (powered && networkConnected) {
            cout << "💬 Message sent: " << message << endl;
        } else {
            cout << "❌ Cannot send message - check power and network" << endl;
        }
    }
};
// Concrete implementation: Laptop
class Laptop : public Device, public NetworkCapable, public Chargeable, public StorageCapable {
private:
    bool networkConnected;
    string ipAddress;
    int batteryLevel;
    bool charging;
    long storageCapacity;
    long usedStorage;
    string operatingSystem;    
public:
    Laptop(const string& id, const string& mfg, long storage, const string& os) 
        : Device(id, mfg), networkConnected(false), ipAddress(""),
          batteryLevel(100), charging(false), storageCapacity(storage), 
          usedStorage(0), operatingSystem(os) {
        cout << "Laptop initialized: " << os << " with " << storage << "GB storage" << endl;
    }    
    ~Laptop() {
        cout << "Laptop " << deviceID << " shutting down" << endl;
    }    
    // Implement Device interface
    void turnOn() override {
        powered = true;
        cout << "💻 Laptop " << deviceID << " booting " << operatingSystem << endl;
        cout << "Boot sequence complete - desktop loaded" << endl;
    }    
    void turnOff() override {
        powered = false;
        networkConnected = false;
        cout << "💻 Laptop " << deviceID << " shutting down " << operatingSystem << endl;
    }    
    void displayStatus() const override {
        cout << "\n--- Laptop Status ---" << endl;
        cout << "ID: " << deviceID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "OS: " << operatingSystem << endl;
        cout << "Power: " << (powered ? "ON" : "OFF") << endl;
        cout << "Network: " << (networkConnected ? "Connected (" + ipAddress + ")" : "Disconnected") << endl;
        cout << "Battery: " << batteryLevel << "%" << (charging ? " (Charging)" : "") << endl;
        cout << "Storage: " << usedStorage << "/" << storageCapacity << "GB used" << endl;
    }    
    string getDeviceType() const override {
        return "Laptop";
    }    
    // Implement NetworkCapable interface
    void connect(const string& network) override {
        if (powered) {
            networkConnected = true;
            ipAddress = "192.168.1." + to_string(rand() % 254 + 1);
            cout << "🌐 Connected to " << network << " (IP: " << ipAddress << ")" << endl;
        } else {
            cout << "❌ Cannot connect - laptop is powered off" << endl;
        }
    }    
    void disconnect() override {
        networkConnected = false;
        ipAddress = "";
        cout << "📡 Network disconnected" << endl;
    }    
    bool isConnected() const override {
        return networkConnected;
    }   
    string getIPAddress() const override {
        return ipAddress;
    }    
    // Implement Chargeable interface
    void startCharging() override {
        charging = true;
        cout << "🔌 Power adapter connected - charging at " << batteryLevel << "%" << endl;
    }    
    void stopCharging() override {
        charging = false;
        cout << "🔌 Power adapter disconnected - battery: " << batteryLevel << "%" << endl;
    }    
    int getBatteryLevel() const override {
        return batteryLevel;
    }    
    bool isCharging() const override {
        return charging;
    }    
    // Implement StorageCapable interface
    void writeData(const string& data) override {
        if (powered && usedStorage < storageCapacity) {
            usedStorage += data.length() / (1024 * 1024);
            cout << "💾 File saved: " << data.substr(0, 30) << "..." << endl;
        } else {
            cout << "❌ Write failed - check power and storage space" << endl;
        }
    }    
    string readData(const string& filename) override {
        if (powered) {
            cout << "📁 Opening file: " << filename << endl;
            return "Document content from " + filename;
        }
        cout << "❌ Cannot access file - laptop is powered off" << endl;
        return "";
    }    
    long getStorageCapacity() const override {
        return storageCapacity;
    }   
    long getAvailableStorage() const override {
        return storageCapacity - usedStorage;
    }    
    // Laptop-specific methods
    void runApplication(const string& appName) {
        if (powered) {
            cout << "🖥️ Launching " << appName << " on " << operatingSystem << endl;
        } else {
            cout << "❌ Cannot run application - laptop is off" << endl;
        }
    }    
    void compileCode(const string& language) {
        if (powered) {
            cout << "⚙️ Compiling " << language << " code..." << endl;
        } else {
            cout << "❌ Cannot compile - laptop is off" << endl;
        }
    }
};

// Here’s a **complete, well-structured `main()`** that exercises **everything your assignment asks for**: abstraction, polymorphism, multiple inheritance, interface usage, and virtual destructors.


int main() {
    cout << "===== Device Management System =====\n" << endl;

    // ❌ This should NOT compile (abstract class)
    // Device d("DEV-000", "Generic"); 

    // Polymorphic container of base-class pointers
    vector<unique_ptr<Device>> devices;

    // Create concrete devices
    devices.push_back(make_unique<Smartphone>(
        "SP-101", "Samsung", 128));

    devices.push_back(make_unique<Laptop>(
        "LP-202", "Dell", 512, "Linux"));

    cout << "\n===== Powering On Devices =====" << endl;
    for (auto& device : devices) {
        device->turnOn();              // Pure virtual call
        device->displayStatus();       // Polymorphic behavior
        device->performDiagnostic();   // Base implementation
    }

    cout << "\n===== Interface-Based Operations =====" << endl;

    for (auto& device : devices) {
        cout << "\nDevice Type: " << device->getDeviceType() << endl;

        // NetworkCapable interface
        if (auto* net = dynamic_cast<NetworkCapable*>(device.get())) {
            net->connect("Office_WiFi");
            cout << "Connected: " << (net->isConnected() ? "Yes" : "No") << endl;
        }

        // Chargeable interface
        if (auto* power = dynamic_cast<Chargeable*>(device.get())) {
            power->startCharging();
            cout << "Battery Level: " << power->getBatteryLevel() << "%" << endl;
        }

        // StorageCapable interface
        if (auto* storage = dynamic_cast<StorageCapable*>(device.get())) {
            storage->writeData("Important company data and logs...");
            cout << "Available Storage: "
                 << storage->getAvailableStorage() << "GB" << endl;
        }
    }

    cout << "\n===== Device-Specific Behavior =====" << endl;

    // Smartphone-specific behavior
    if (auto* phone = dynamic_cast<Smartphone*>(devices[0].get())) {
        phone->makeCall("+1-555-1234");
        phone->sendMessage("System deployment complete.");
    }

    // Laptop-specific behavior
    if (auto* laptop = dynamic_cast<Laptop*>(devices[1].get())) {
        laptop->runApplication("IDE");
        laptop->compileCode("C++");
    }

    cout << "\n===== Powering Off Devices =====" << endl;
    for (auto& device : devices) {
        device->turnOff();
    }

    cout << "\n===== Program Ending (Destructors Triggered) =====" << endl;
    return 0;
}

/*
### What this `main()` demonstrates clearly

✅ **Abstract class enforcement**
* `Device` cannot be instantiated

✅ **Polymorphism**
* `vector<unique_ptr<Device>>`
* Calls to pure virtual functions via base pointers

✅ **Multiple inheritance**
* Same object accessed through:

  * `Device*`
  * `NetworkCapable*`
  * `Chargeable*`
  * `StorageCapable*`

✅ **RTTI + `dynamic_cast`**
* Safe downcasting for interface-specific behavior

✅ **Virtual destructors**
* Correct destruction order when `unique_ptr` cleans up
*/