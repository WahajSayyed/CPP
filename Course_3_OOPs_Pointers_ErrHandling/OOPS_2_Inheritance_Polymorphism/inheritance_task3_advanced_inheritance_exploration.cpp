/*Create your own inheritance hierarchy for a different domain such as electronics, employees, or geometric shapes. Apply the patterns learned in previous tasks.

🔍 Practice
Design and implement your hierarchy using the code below:
    Choose a domain with clear hierarchical relationships
    Identify shared attributes for the base class
    Create 2-3 derived classes with unique specializations
    Test all functionality and access control mechanisms

Analyze your design:
    Does the inheritance relationship follow "is-a" logic?
    Are access specifiers used appropriately for encapsulation?
    Can the hierarchy be easily extended with new classes?*/

#include <iostream>

// TODO: Design your own inheritance system
// Example: Electronic Device hierarchy
class ElectronicDevice {
    ElectronicDevice(){}
    // TODO: Add appropriate members and access control
    // Consider: brand, model, powerConsumption, isOn
    // Methods: turnOn(), turnOff(), displaySpecs()
};
class Smartphone : public ElectronicDevice {
    // TODO: Add phone-specific features
    // Consider: screenSize, storageCapacity, batteryLife
    // Methods: makeCall(), sendText(), takePicture()
};
class Laptop : public ElectronicDevice {
    // TODO: Add laptop-specific features  
    // Consider: ramSize, processorType, screenSize
    // Methods: runProgram(), connectToWifi(), saveFile()
};

/*✅ Success Checklist
Custom hierarchy demonstrates clear inheritance relationships
Base class contains genuinely shared functionality
Derived classes add meaningful specialization without duplication
Access control maintains proper encapsulation

💡 Key Points
Inheritance models "is-a" relationships - derived classes are specialized versions of base classes
Access control maintains encapsulation - private for internal implementation, protected for derived class access, public for external interface
Constructor chaining ensures proper initialization - derived constructors call base constructors automatically or explicitly
Virtual destructors prevent memory leaks - essential when using polymorphism with base class pointers
Method overriding customizes behavior - derived classes can redefine base class methods while maintaining interface compatibility

❗ Common Mistakes to Avoid
Forgetting virtual destructors in base classes designed for inheritance
Using private inheritance when public inheritance is intended
Accessing protected members from outside the inheritance hierarchy
Not calling base class constructors explicitly when parameters are needed
Creating inheritance hierarchies for "has-a" relationships instead of "is-a" relationships

🚀 Next Steps
These inheritance skills are essential for developing enterprise software systems, 
game engines, user interface frameworks, and any application requiring extensible object hierarchies. 
Professional developers use inheritance to create maintainable codebases that can evolve with changing requirements while preserving existing functionality. 
Your next step involves mastering polymorphism, which builds on inheritance to enable dynamic method dispatch and flexible runtime behavior.*/