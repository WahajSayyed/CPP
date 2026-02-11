/*
Implement advanced interface patterns including virtual inheritance, interface composition, and polymorphic collections for enterprise-grade system architecture.

🔍 Practice
Test advanced interface patterns using the code below:

    Create EnterpriseTablet objects and test all interface implementations
    Use DeviceManager to demonstrate polymorphic device management
    Test security features through SecureDevice interface
    Verify remote management capabilities work correctly

Explore complex inheritance scenarios:

    Access the same object through different interface pointers
    Test virtual function dispatch through multiple inheritance paths
    Verify that interface segregation maintains clean separation of concerns*/

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
// Advanced interface for devices requiring secure authentication
class SecureDevice {
public:
    virtual ~SecureDevice() = default;
    virtual bool authenticate(const string& credentials) = 0;
    virtual void lockDevice() = 0;
    virtual void unlockDevice() = 0;
    virtual bool isLocked() const = 0;
};
// Interface for devices supporting remote management
class RemoteManageable {
public:
    virtual ~RemoteManageable() = default;
    virtual void executeRemoteCommand(const string& command) = 0;
    virtual string getRemoteStatus() const = 0;
    virtual bool enableRemoteAccess(const string& adminKey) = 0;
    virtual void disableRemoteAccess() = 0;
};
// Enterprise tablet with comprehensive interface implementation
class EnterpriseTablet : public Device, public NetworkCapable, public Chargeable, 
                        public StorageCapable, public SecureDevice, public RemoteManageable {
private:
    // Network state
    bool networkConnected;
    string ipAddress;    
    // Power management
    int batteryLevel;
    bool charging;    
    // Storage management
    long storageCapacity;
    long usedStorage;    
    // Security state
    bool deviceLocked;
    string secureHash;    
    // Remote management
    bool remoteAccessEnabled;
    string adminKey;    
public:
    EnterpriseTablet(const string& id, const string& mfg, long storage) 
        : Device(id, mfg), networkConnected(false), ipAddress(""),
          batteryLevel(100), charging(false), storageCapacity(storage), usedStorage(0),
          deviceLocked(true), secureHash(""), remoteAccessEnabled(false), adminKey("") {
        cout << "Enterprise Tablet initialized: " << storage << "GB, Security enabled" << endl;
    }    
    ~EnterpriseTablet() {
        cout << "Enterprise Tablet " << deviceID << " securely powered down" << endl;
    }    
    // Device interface implementation
    void turnOn() override {
        powered = true;
        deviceLocked = true; // Always start locked for security
        cout << "🔒 Enterprise Tablet " << deviceID << " powered on (locked)" << endl;
    }    
    void turnOff() override {
        powered = false;
        networkConnected = false;
        remoteAccessEnabled = false;
        cout << "🔒 Enterprise Tablet " << deviceID << " secured and powered off" << endl;
    }    
    void displayStatus() const override {
        cout << "\n--- Enterprise Tablet Status ---" << endl;
        cout << "ID: " << deviceID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Power: " << (powered ? "ON" : "OFF") << endl;
        cout << "Security: " << (deviceLocked ? "LOCKED" : "UNLOCKED") << endl;
        cout << "Network: " << (networkConnected ? "Connected (" + ipAddress + ")" : "Disconnected") << endl;
        cout << "Battery: " << batteryLevel << "%" << (charging ? " (Charging)" : "") << endl;
        cout << "Storage: " << usedStorage << "/" << storageCapacity << "GB used" << endl;
        cout << "Remote Access: " << (remoteAccessEnabled ? "ENABLED" : "DISABLED") << endl;
    }    
    string getDeviceType() const override {
        return "Enterprise Tablet";
    }    
    // NetworkCapable interface
    void connect(const string& network) override {
        if (powered && !deviceLocked) {
            networkConnected = true;
            ipAddress = "10.0.1." + to_string(rand() % 254 + 1); // Enterprise IP range
            cout << "🔐 Securely connected to " << network << " (IP: " << ipAddress << ")" << endl;
        } else {
            cout << "❌ Connection failed - device must be powered and unlocked" << endl;
        }
    }    
    void disconnect() override {
        networkConnected = false;
        remoteAccessEnabled = false; // Disable remote access on disconnect
        ipAddress = "";
        cout << "🔐 Secure disconnect completed" << endl;
    }    
    bool isConnected() const override { return networkConnected; }
    string getIPAddress() const override { return ipAddress; }    
    // Chargeable interface
    void startCharging() override {
        charging = true;
        cout << "🔋 Enterprise charging initiated - " << batteryLevel << "%" << endl;
    }    
    void stopCharging() override {
        charging = false;
        cout << "🔋 Enterprise charging stopped - " << batteryLevel << "%" << endl;
    }    
    int getBatteryLevel() const override { return batteryLevel; }
    bool isCharging() const override { return charging; }    
    // StorageCapable interface
    void writeData(const string& data) override {
        if (powered && !deviceLocked && usedStorage < storageCapacity) {
            usedStorage += data.length() / (1024 * 1024);
            cout << "🔐 Encrypted data written: " << data.substr(0, 20) << "..." << endl;
        } else {
            cout << "❌ Write denied - check power, security, and storage" << endl;
        }
    }    
    string readData(const string& filename) override {
        if (powered && !deviceLocked) {
            cout << "🔐 Reading encrypted file: " << filename << endl;
            return "Decrypted content from " + filename;
        }
        cout << "❌ Read denied - device must be powered and unlocked" << endl;
        return "";
    }    
    long getStorageCapacity() const override { return storageCapacity; }
    long getAvailableStorage() const override { return storageCapacity - usedStorage; }    
    // SecureDevice interface
    bool authenticate(const string& credentials) override {
        // Simple hash simulation for demo
        if (powered && credentials.length() >= 8) {
            secureHash = "hash_" + credentials;
            cout << "🔑 Authentication successful" << endl;
            return true;
        }
        cout << "❌ Authentication failed" << endl;
        return false;
    }    
    void lockDevice() override {
        deviceLocked = true;
        cout << "🔒 Device locked for security" << endl;
    }    
    void unlockDevice() override {
        if (!secureHash.empty()) {
            deviceLocked = false;
            cout << "🔓 Device unlocked - access granted" << endl;
        } else {
            cout << "❌ Unlock failed - authentication required" << endl;
        }
    }    
    bool isLocked() const override { return deviceLocked; }    
    // RemoteManageable interface
    void executeRemoteCommand(const string& command) override {
        if (powered && networkConnected && remoteAccessEnabled && !deviceLocked) {
            cout << "🌐 Executing remote command: " << command << endl;            
            if (command == "status") {
                displayStatus();
            } else if (command == "restart") {
                cout << "🔄 Remote restart initiated..." << endl;
            } else if (command == "lock") {
                lockDevice();
            } else {
                cout << "Unknown command: " << command << endl;
            }
        } else {
            cout << "❌ Remote command denied - check network, permissions, and security" << endl;
        }
    }    
    string getRemoteStatus() const override {
        if (remoteAccessEnabled) {
            return "Remote access enabled - " + ipAddress;
        }
        return "Remote access disabled";
    }    
    bool enableRemoteAccess(const string& key) override {
        if (powered && networkConnected && !deviceLocked && key.length() >= 12) {
            adminKey = key;
            remoteAccessEnabled = true;
            cout << "🌐 Remote access enabled with admin key" << endl;
            return true;
        }
        cout << "❌ Remote access denied - insufficient privileges or security" << endl;
        return false;
    }    
    void disableRemoteAccess() override {
        remoteAccessEnabled = false;
        adminKey = "";
        cout << "🌐 Remote access disabled" << endl;
    }
};
// Device management system for polymorphic operations
class DeviceManager {
private:
    vector<unique_ptr<Device>> devices;    
public:
    DeviceManager() {
        cout << "Device Management System initialized" << endl;
    }    
    ~DeviceManager() {
        cout << "Device Management System shutting down" << endl;
    }    
    // Inside DeviceManager
    Device* getDevice(size_t index) {
        if (index < devices.size()) return devices[index].get();
        return nullptr;
    }

    void registerDevice(unique_ptr<Device> device) {
        cout << "Registering device: " << device->getDeviceID() << endl;
        devices.push_back(move(device));
    }    
    void powerOnAllDevices() {
        cout << "\n=== Powering On All Devices ===" << endl;
        for (auto& device : devices) {
            device->turnOn();
        }
    }    
    void runSystemDiagnostics() {
        cout << "\n=== System Diagnostics ===" << endl;
        for (auto& device : devices) {
            cout << "\nDiagnosing " << device->getDeviceType() << " " << device->getDeviceID() << ":" << endl;
            device->performDiagnostic();
            device->displayStatus();
        }
    }    
    void manageNetworkDevices() {
        cout << "\n=== Network Management ===" << endl;
        for (auto& device : devices) {
            // Use dynamic_cast to safely check for network capability
            if (auto* networkDevice = dynamic_cast<NetworkCapable*>(device.get())) {
                cout << "\nManaging network for " << device->getDeviceID() << ":" << endl;
                networkDevice->connect("Corporate_WiFi");
                cout << "Connection status: " << (networkDevice->isConnected() ? "Connected" : "Failed") << endl;
            }
        }
    }    
    void manageChargeableDevices() {
        cout << "\n=== Battery Management ===" << endl;
        for (auto& device : devices) {
            if (auto* chargeableDevice = dynamic_cast<Chargeable*>(device.get())) {
                cout << "\nCharging " << device->getDeviceID() << ":" << endl;
                chargeableDevice->startCharging();
                cout << "Battery level: " << chargeableDevice->getBatteryLevel() << "%" << endl;
            }
        }
    }    
    void performSecurityAudit() {
        cout << "\n=== Security Audit ===" << endl;
        for (auto& device : devices) {
            if (auto* secureDevice = dynamic_cast<SecureDevice*>(device.get())) {
                cout << "\nAuditing " << device->getDeviceID() << ":" << endl;
                cout << "Lock status: " << (secureDevice->isLocked() ? "SECURED" : "UNSECURED") << endl;                
                if (!secureDevice->isLocked()) {
                    cout << "⚠️ WARNING: Device is unlocked!" << endl;
                    secureDevice->lockDevice();
                }
            }
        }
    }
    
    size_t getDeviceCount() const { return devices.size(); }
};

// Here’s a complete **`main()` function** that exercises all your **advanced interface patterns**, including polymorphism, virtual inheritance, interface segregation, security, and remote management. It’s designed to test **EnterpriseTablet** and the **DeviceManager** in a realistic scenario:
int main() {
    cout << "===== Enterprise Device Management Demo =====\n" << endl;

    // Initialize DeviceManager
    DeviceManager manager;

    // Create Enterprise Tablets
    auto tablet1 = make_unique<EnterpriseTablet>("ET-001", "Lenovo", 256);
    auto tablet2 = make_unique<EnterpriseTablet>("ET-002", "Microsoft", 512);

    // Register devices
    manager.registerDevice(move(tablet1));
    manager.registerDevice(move(tablet2));

    // Power on all devices
    manager.powerOnAllDevices();

    // Run system diagnostics
    manager.runSystemDiagnostics();

    // Manage network devices
    manager.manageNetworkDevices();

    // Manage charging
    manager.manageChargeableDevices();

    // Perform security audit
    manager.performSecurityAudit();

    cout << "\n===== Direct Interface Testing =====" << endl;

    // Access devices directly via interfaces
    for (size_t i = 0; i < manager.getDeviceCount(); ++i) {
        Device* device = manager.getDevice(i);

        // SecureDevice interface
        if (auto* secureDevice = dynamic_cast<SecureDevice*>(device)) {
            cout << "\nTesting SecureDevice for " << device->getDeviceID() << endl;
            secureDevice->authenticate("SuperSecure123");
            secureDevice->unlockDevice();
            secureDevice->lockDevice();
        }

        // RemoteManageable interface
        if (auto* remoteDevice = dynamic_cast<RemoteManageable*>(device)) {
            cout << "\nTesting RemoteManageable for " << device->getDeviceID() << endl;
            if (auto* netDevice = dynamic_cast<NetworkCapable*>(device)) {
                netDevice->connect("Corporate_WiFi"); // Ensure network connected
            }
            remoteDevice->enableRemoteAccess("AdminKey12345");
            remoteDevice->executeRemoteCommand("status");
            remoteDevice->disableRemoteAccess();
        }

        // StorageCapable interface
        if (auto* storageDevice = dynamic_cast<StorageCapable*>(device)) {
            storageDevice->writeData("Enterprise confidential data...");
            storageDevice->readData("report.docx");
        }
    }

    cout << "\n===== Program Ending (Destructors Triggered) =====" << endl;
    return 0;
}

/*
### ✅ What this `main()` demonstrates:

1. **Polymorphic collections**

   * `DeviceManager` holds `unique_ptr<Device>`, but devices implement multiple interfaces.

2. **Interface Segregation**

   * `EnterpriseTablet` implements `NetworkCapable`, `Chargeable`, `StorageCapable`, `SecureDevice`, `RemoteManageable`.
   * Operations are performed via interface pointers using `dynamic_cast`.

3. **Security & Remote Management**

   * SecureDevice interface allows lock/unlock, authentication.
   * RemoteManageable allows remote command execution.

4. **Multiple Inheritance & Virtual Functions**

   * Virtual functions are dispatched correctly even with multiple interfaces.

5. **Virtual destructors**

   * Proper destruction of `EnterpriseTablet` when `DeviceManager` goes out of scope.*/