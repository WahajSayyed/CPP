#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <typeinfo>
using namespace std;

int main() {
    cout << "=== Polymorphic System Architecture Implementation ===" << endl;
    cout << "Duration: 45-60 minutes" << endl;
    cout << "Scenario: Adventure Game Entity System" << endl;
    
    // ========================================
    // STEP 1: Design Base Class and Interfaces
    // ========================================
    cout << "\n--- Step 1: Abstract Base Class Design ---" << endl;
    
    // TODO: Define Entity base class
    // Requirements:
    // - Pure virtual function interact()
    // - Virtual destructor
    // - Protected attributes: name, health, position
    // - Cannot be instantiated directly (abstract class)
    
    class Entity {
    protected:
        // TODO: Add protected attributes
        // string name;
        // int health;
        // pair<int, int> position; // x, y coordinates
        
    public:
        // TODO: Constructor with parameters
        // Entity(const string& entityName, int hp, int x, int y)
        
        // TODO: Virtual destructor (essential for polymorphism)
        // virtual ~Entity() = default;
        
        // TODO: Pure virtual function - makes class abstract
        // virtual void interact() const = 0;
        
        // TODO: Additional virtual methods
        // virtual void displayInfo() const { }
        // virtual string getType() const = 0;
        
        // TODO: Getter methods for protected attributes
    };
    
    // TODO: Define Player derived class
    // Requirements:
    // - Inherit from Entity
    // - Override interact() - should show player actions
    // - Override getType() to return "Player"
    // - Add player-specific attributes: level, experience
    // - Add player-specific methods: levelUp(), attack()
    
    class Player /* TODO: Add inheritance */ {
    private:
        // TODO: Add player-specific attributes
        
    public:
        // TODO: Constructor calling base constructor
        
        // TODO: Override pure virtual methods
        // void interact() const override { }
        // string getType() const override { }
        
        // TODO: Player-specific methods
    };
    
    // TODO: Define Enemy derived class
    // Requirements:
    // - Inherit from Entity
    // - Override interact() - should show threatening behavior
    // - Override getType() to return "Enemy" 
    // - Add enemy-specific attributes: damage, aggroRange
    // - Add enemy-specific methods: attack(), patrol()
    
    class Enemy /* TODO: Add inheritance */ {
    private:
        // TODO: Add enemy-specific attributes
        
    public:
        // TODO: Constructor and method implementations
    };
    
    // TODO: Define NPC derived class
    // Requirements:
    // - Inherit from Entity
    // - Override interact() - should show helpful behavior
    // - Override getType() to return "NPC"
    // - Add NPC-specific attributes: dialogue, questGiver
    // - Add NPC-specific methods: giveQuest(), talk()
    
    class NPC /* TODO: Add inheritance */ {
    private:
        // TODO: Add NPC-specific attributes
        
    public:
        // TODO: Constructor and method implementations
    };
    
    // TODO: Test basic inheritance and polymorphism
    cout << "Testing basic entity creation:" << endl;
    // TODO: Create Player, Enemy, and NPC objects
    // TODO: Call interact() on each to verify polymorphism
    
    // ========================================
    // STEP 2: Implement Polymorphic Behavior
    // ========================================
    cout << "\n--- Step 2: Polymorphic System Implementation ---" << endl;
    
    // TODO: Create game world function
    // Requirements:
    // - Take vector of Entity pointers/unique_ptrs
    // - Iterate through entities calling interact()
    // - Demonstrate polymorphic behavior
    
    // void runGameWorld(const vector<unique_ptr<Entity>>& entities) {
    //     cout << "\n🎮 Game World Simulation 🎮" << endl;
    //     TODO: Iterate through entities and call interact()
    // }
    
    // TODO: Define additional entity types for extensibility
    // Requirements:
    // - Merchant class for trading
    // - Guardian class for protection
    // - Show how system extends without modifying existing code
    
    class Merchant /* TODO: Add inheritance */ {
    private:
        // TODO: Add merchant-specific attributes (inventory, gold)
        
    public:
        // TODO: Implementation
        // TODO: Add sellItem(), buyItem() methods
    };
    
    class Guardian /* TODO: Add inheritance */ {
    private:
        // TODO: Add guardian-specific attributes (protectionArea, alertLevel)
        
    public:
        // TODO: Implementation  
        // TODO: Add protect(), alert() methods
    };
    
    // TODO: Test polymorphic behavior with container
    cout << "Testing polymorphic container:" << endl;
    // TODO: Create vector of unique_ptr<Entity>
    // TODO: Add different entity types to container
    // TODO: Call runGameWorld() function
    
    // ========================================
    // STEP 3: Dynamic Binding and RTTI
    // ========================================
    cout << "\n--- Step 3: Dynamic Binding and RTTI Implementation ---" << endl;
    
    // TODO: Create enhanced interaction function
    // Requirements:
    // - Use RTTI to identify specific entity types
    // - Perform type-specific operations using dynamic_cast
    // - Show safe downcasting techniques
    
    // void enhancedInteraction(Entity* entity) {
    //     TODO: Call base interact() method
    //     
    //     TODO: Use dynamic_cast to identify specific types
    //     if (auto* player = dynamic_cast<Player*>(entity)) {
    //         TODO: Player-specific operations
    //     }
    //     else if (auto* merchant = dynamic_cast<Merchant*>(entity)) {
    //         TODO: Merchant-specific operations
    //     }
    //     TODO: Add other entity types
    // }
    
    // TODO: Create game event system
    // Requirements:
    // - Demonstrate entity interactions
    // - Show combat between Player and Enemy
    // - Show trading between Player and Merchant
    // - Show quest giving by NPC
    
    // void simulateGameEvents(vector<unique_ptr<Entity>>& entities) {
    //     TODO: Find specific entity types in container
    //     TODO: Simulate interactions between different entity types
    //     TODO: Use RTTI where appropriate for type-specific behavior
    // }
    
    // TODO: Test RTTI and dynamic binding
    cout << "Testing RTTI and dynamic interactions:" << endl;
    // TODO: Create diverse set of entities
    // TODO: Test enhancedInteraction() function
    // TODO: Test simulateGameEvents() function
    
    // ========================================
    // ADVANCED: Open/Closed Principle Demonstration
    // ========================================
    cout << "\n--- Advanced: Open/Closed Principle ---" << endl;
    
    // TODO: Add new entity type without modifying existing code
    // Example: Dragon, Treasure, Portal
    
    class Dragon /* TODO: Implement */ {
        // TODO: Powerful enemy with special abilities
    };
    
    // TODO: Show that new entities work with existing polymorphic functions
    // TODO: Demonstrate extensibility without modification
    
    cout << "\n=== Implementation Complete ===" << endl;
    cout << "Architecture principles demonstrated:" << endl;
    cout << "□ Abstract base class with pure virtual functions" << endl;
    cout << "□ Polymorphic behavior through inheritance" << endl;
    cout << "□ Dynamic binding with virtual function tables" << endl;
    cout << "□ RTTI for runtime type identification" << endl;
    cout << "□ Open/Closed Principle - extensible without modification" << endl;
    cout << "□ Smart pointers for automatic memory management" << endl;
    
    return 0;
}

/*
IMPLEMENTATION GUIDE:

STEP 1: Abstract Base Class Design
□ Create Entity base class with pure virtual interact()
□ Add virtual destructor for safe polymorphic deletion
□ Use protected members for derived class access
□ Ensure class cannot be instantiated directly
□ Implement Player, Enemy, and NPC derived classes
□ Override all pure virtual functions in derived classes

STEP 2: Polymorphic System Implementation
□ Create container-based polymorphic functions
□ Use std::unique_ptr for automatic memory management
□ Demonstrate runtime method resolution
□ Add extensible entity types (Merchant, Guardian)
□ Show system extensibility without core modification

STEP 3: Dynamic Binding and RTTI
□ Implement enhanced interaction using dynamic_cast
□ Use typeid for type identification when needed
□ Create entity interaction system
□ Demonstrate safe downcasting techniques
□ Show practical RTTI usage patterns

DESIGN PRINCIPLES:
□ Abstract base class enforces interface contracts
□ Virtual functions enable polymorphic behavior
□ Pure virtual functions create abstract classes
□ Virtual destructors ensure proper cleanup
□ Open/Closed Principle allows extension without modification

SUCCESS CRITERIA:
□ Abstract Entity class compiles and cannot be instantiated
□ All derived classes properly override pure virtual functions
□ Polymorphic containers work with all entity types
□ RTTI correctly identifies entity types at runtime
□ New entity types integrate seamlessly
□ Memory management is automatic with smart pointers
□ Code demonstrates professional game architecture patterns

COMMON PITFALLS TO AVOID:
□ Forgetting virtual destructor in base class
□ Not making interact() pure virtual
□ Overusing dynamic_cast (performance cost)
□ Memory leaks with raw pointers
□ Violating Open/Closed Principle
□ Confusing overriding vs overloading
*/