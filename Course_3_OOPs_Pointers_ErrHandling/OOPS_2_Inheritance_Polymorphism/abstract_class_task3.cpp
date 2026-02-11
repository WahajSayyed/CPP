/*Implement virtual inheritance patterns to resolve diamond problem scenarios while maintaining clean interface hierarchies.

🔍 Practice
Explore virtual inheritance mechanics using the code below:

    Create SecureNetworkDevice objects and observe constructor calling order
    Test polymorphic access through different base class pointers
    Verify that only one instance of Identifiable exists in the object
    Compare behavior with and without virtual inheritance

Analyze diamond problem resolution:

    Draw the inheritance hierarchy to understand the diamond shape
    Test virtual function dispatch through different inheritance paths
    Verify that virtual inheritance eliminates ambiguity*/
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <typeinfo>
using namespace std;

// Base interface that might be inherited by multiple paths
class Identifiable {
protected:
    string uniqueID;    
public:
    Identifiable(const string& id) : uniqueID(id) {
        cout << "Identifiable created: " << uniqueID << endl;
    }    
    virtual ~Identifiable() {
        cout << "Identifiable destroyed: " << uniqueID << endl;
    }    
    virtual string getID() const { return uniqueID; }
    virtual void displayIdentity() const {
        cout << "ID: " << uniqueID << endl;
    }
};
// Multiple inheritance with virtual inheritance to avoid diamond problem
class NetworkIdentifiable : public virtual Identifiable {
protected:
    string networkAddress;    
public:
    NetworkIdentifiable(const string& id, const string& addr) 
        : Identifiable(id), networkAddress(addr) {
        cout << "Network identity established: " << networkAddress << endl;
    }    
    virtual ~NetworkIdentifiable() {
        cout << "Network identity cleared: " << networkAddress << endl;
    }    
    virtual string getNetworkAddress() const { return networkAddress; }    
    void displayIdentity() const override {
        Identifiable::displayIdentity();
        cout << "Network Address: " << networkAddress << endl;
    }
};
class SecureIdentifiable : public virtual Identifiable {
protected:
    string securityToken;    
public:
    SecureIdentifiable(const string& id, const string& token) 
        : Identifiable(id), securityToken(token) {
        cout << "Security identity established: " << token.substr(0, 8) << "..." << endl;
    }    
    virtual ~SecureIdentifiable() {
        cout << "Security identity cleared" << endl;
    }    
    virtual string getSecurityToken() const { return securityToken; }
    virtual bool validateSecurity() const { return !securityToken.empty(); }    
    void displayIdentity() const override {
        Identifiable::displayIdentity();
        cout << "Security Token: " << securityToken.substr(0, 8) << "..." << endl;
    }
};
// Diamond inheritance resolved with virtual inheritance
class SecureNetworkDevice : public NetworkIdentifiable, public SecureIdentifiable {
private:
    string deviceName;
    bool secureConnectionActive;    
public:
    // Must explicitly call virtual base constructor
    SecureNetworkDevice(const string& id, const string& name, 
                       const string& addr, const string& token)
        : Identifiable(id), // Virtual base constructor
          NetworkIdentifiable(id, addr),
          SecureIdentifiable(id, token),
          deviceName(name), secureConnectionActive(false) {
        cout << "Secure Network Device created: " << deviceName << endl;
    }    
    ~SecureNetworkDevice() {
        cout << "Secure Network Device destroyed: " << deviceName << endl;
    }    
    void displayIdentity() const override {
        cout << "\n--- Secure Network Device Identity ---" << endl;
        cout << "Device Name: " << deviceName << endl;
        Identifiable::displayIdentity();
        cout << "Network Address: " << getNetworkAddress() << endl;
        cout << "Security Status: " << (validateSecurity() ? "VALID" : "INVALID") << endl;
        cout << "Secure Connection: " << (secureConnectionActive ? "ACTIVE" : "INACTIVE") << endl;
    }    
    void establishSecureConnection() {
        if (validateSecurity()) {
            secureConnectionActive = true;
            cout << "🔐 Secure connection established for " << deviceName << endl;
            cout << "Network: " << getNetworkAddress() << endl;
            cout << "Security validated ✓" << endl;
        } else {
            cout << "❌ Secure connection failed - invalid security token" << endl;
        }
    }    
    void terminateConnection() {
        secureConnectionActive = false;
        cout << "🔐 Secure connection terminated for " << deviceName << endl;
    }    
    bool isSecurelyConnected() const {
        return secureConnectionActive && validateSecurity();
    }    
    string getDeviceName() const { return deviceName; }
};
// Demonstration function for virtual inheritance concepts
void demonstrateVirtualInheritance() {
    cout << "\n🔹 Virtual Inheritance Demonstration 🔹" << endl;
    cout << "Resolving diamond problem with virtual inheritance" << endl;    
    // Create secure network device
    SecureNetworkDevice device("DEV001", "Enterprise Router", 
                              "192.168.1.1", "SecureToken123456");    
    cout << "\n--- Testing polymorphic access ---" << endl;    
    // Access through different base class pointers
    Identifiable* identPtr = &device;
    NetworkIdentifiable* networkPtr = &device;
    SecureIdentifiable* securePtr = &device;    
    cout << "\nAccessing through Identifiable pointer:" << endl;
    cout << "ID: " << identPtr->getID() << endl;    
    cout << "\nAccessing through NetworkIdentifiable pointer:" << endl;
    cout << "Network Address: " << networkPtr->getNetworkAddress() << endl;    
    cout << "\nAccessing through SecureIdentifiable pointer:" << endl;
    cout << "Security Valid: " << (securePtr->validateSecurity() ? "Yes" : "No") << endl;    
    cout << "\n--- Testing virtual function dispatch ---" << endl;
    identPtr->displayIdentity();    // Should call most derived version    
    cout << "\n--- Testing secure connection ---" << endl;
    device.establishSecureConnection();
    cout << "Connection Status: " << (device.isSecurelyConnected() ? "Secure" : "Insecure") << endl;    
    device.terminateConnection();
}

int main() {
    cout << "=== Virtual Inheritance & Diamond Problem Demo ===" << endl;

    // Create SecureNetworkDevice instance
    SecureNetworkDevice device1("DEV001", "Enterprise Router", 
                                "192.168.1.1", "SecureToken123456");

    SecureNetworkDevice device2("DEV002", "Core Switch", 
                                "192.168.1.2", "SwitchTokenABCDEF");

    // Polymorphic collection
    vector<Identifiable*> devices;
    devices.push_back(&device1);
    devices.push_back(&device2);

    cout << "\n--- Displaying identities via Identifiable pointers ---" << endl;
    for (auto* d : devices) {
        d->displayIdentity();  // Virtual dispatch
        cout << endl;
    }

    cout << "\n--- Accessing through specific base class pointers ---" << endl;
    NetworkIdentifiable* netPtr = &device1;
    SecureIdentifiable* secPtr = &device2;

    cout << "Device1 Network Address: " << netPtr->getNetworkAddress() << endl;
    cout << "Device2 Security Valid: " 
         << (secPtr->validateSecurity() ? "Yes" : "No") << endl;

    cout << "\n--- Testing secure connections ---" << endl;
    device1.establishSecureConnection();
    cout << "Device1 Secure Status: " 
         << (device1.isSecurelyConnected() ? "Secure" : "Insecure") << endl;

    device2.establishSecureConnection();
    cout << "Device2 Secure Status: " 
         << (device2.isSecurelyConnected() ? "Secure" : "Insecure") << endl;

    cout << "\n--- Terminating connections ---" << endl;
    device1.terminateConnection();
    device2.terminateConnection();

    cout << "\n=== End of Demo ===" << endl;
    return 0;
}
/*✅ Success Checklist
Virtual inheritance resolves diamond problem without ambiguity

Single instance of virtual base class exists in derived objects

Polymorphic access works correctly through all inheritance paths

Constructor calling order follows virtual inheritance rules

💡 Key Points
Abstract classes define contracts - pure virtual functions force implementation in derived classes

Interface segregation principle - create focused, single-purpose interfaces rather than monolithic ones

Multiple inheritance enables composition - classes can implement multiple interface contracts simultaneously

Virtual inheritance solves diamond problems - ensures single instance of virtual base classes in complex hierarchies

Dynamic casting enables safe interface access - runtime type checking prevents invalid downcasts

Open/Closed Principle through interfaces - systems remain open for extension but closed for modification

❗ Common Mistakes to Avoid
Forgetting virtual destructors in abstract base classes

Creating interfaces that are too broad or do too many things

Using multiple inheritance without considering the diamond problem

Overusing dynamic_cast instead of designing proper virtual interfaces

Not using virtual inheritance when diamond inheritance patterns exist

Making abstract classes too concrete by including implementation details

🚀 Next teps
Interface-based design is fundamental to enterprise software architecture, plugin systems, microservices communication, and any system requiring extensible, maintainable code. Professional developers use these patterns to create frameworks that can evolve with changing requirements while maintaining backward compatibility. Your mastery of abstract classes and interface design prepares you for advanced architectural patterns like Dependency Injection, Strategy Pattern, and Service-Oriented Architecture that power modern software systems.*/