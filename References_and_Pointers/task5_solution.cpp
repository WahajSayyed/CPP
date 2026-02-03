#include <iostream>
#include <string>
using namespace std;

// Character class for the adventure game
class Character {
public:
    string name;
    int level;
    int experience;
    int health;

    // Constructor
    Character(string n, int l = 1, int exp = 0, int hp = 100) 
        : name(n), level(l), experience(exp), health(hp) {}

    // Display character information
    void displayInfo() const {
        cout << "Character: " << name << " | Level: " << level 
             << " | Experience: " << experience << " | Health: " << health << endl;
    }
};

// Node structure for linked list (inventory management)
struct Node {
    string itemName;  // The data
    Node* next;       // The pointer to the next node
    
    // Constructor for easier node creation
    Node(string item, Node* nextNode = nullptr) : itemName(item), next(nextNode) {}
};

// ========================================
// STEP 1: Function Parameter Passing with References
// ========================================

// SOLUTION: levelUp function using reference parameter
void levelUp(Character& charRef) {
    charRef.experience += 100;
    charRef.level++;
    cout << charRef.name << " leveled up! Now level " << charRef.level << endl;
}

// SOLUTION: healCharacter function with validation
void healCharacter(Character& charRef, int healAmount) {
    const int MAX_HEALTH = 100;
    int oldHealth = charRef.health;
    
    charRef.health += healAmount;
    if (charRef.health > MAX_HEALTH) {
        charRef.health = MAX_HEALTH;
    }
    
    int actualHealing = charRef.health - oldHealth;
    cout << charRef.name << " healed for " << actualHealing << " points! Health: " 
         << charRef.health << endl;
}

// ========================================
// STEP 2: Data Structure Navigation with Pointers
// ========================================

// SOLUTION: addItem function - adds to front of list
void addItem(Node*& head, const string& item) {
    Node* newNode = new Node(item, head);
    head = newNode;
    cout << "Added '" << item << "' to inventory." << endl;
}

// SOLUTION: displayInventory function - traverses and displays list
void displayInventory(Node* head) {
    if (head == nullptr) {
        cout << "Inventory is empty." << endl;
        return;
    }
    
    cout << "Inventory contents: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->itemName;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// SOLUTION: removeItem function - finds and removes item
bool removeItem(Node*& head, const string& item) {
    if (head == nullptr) {
        return false;  // Empty list
    }
    
    // Check if first item matches
    if (head->itemName == item) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    // Search in rest of list
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->itemName == item) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        current = current->next;
    }
    
    return false;  // Item not found
}

// ========================================
// STEP 3: Efficient Memory Usage - Dynamic Allocation
// ========================================

// SOLUTION: createScoreArray function - dynamic allocation
int* createScoreArray(int initialSize) {
    if (initialSize <= 0) {
        return nullptr;  // Invalid size
    }
    
    int* scores = new int[initialSize];
    
    // Initialize all elements to 0
    for (int i = 0; i < initialSize; i++) {
        scores[i] = 0;
    }
    
    cout << "Created score array of size " << initialSize << endl;
    return scores;
}

// SOLUTION: displayScores function - safely display array
void displayScores(int* scores, int size) {
    if (scores == nullptr) {
        cout << "No scores to display (null pointer)." << endl;
        return;
    }
    
    cout << "Scores: ";
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]: " << scores[i];
        if (i < size - 1) cout << " | ";
    }
    cout << endl;
}

// SOLUTION: updateScore function - safe array update
bool updateScore(int* scores, int size, int index, int newScore) {
    // Validate parameters
    if (scores == nullptr) {
        cout << "Error: Scores array is null!" << endl;
        return false;
    }
    
    if (index < 0 || index >= size) {
        cout << "Error: Index " << index << " is out of bounds!" << endl;
        return false;
    }
    
    scores[index] = newScore;
    cout << "Updated score[" << index << "] = " << newScore << endl;
    return true;
}

// ========================================
// STEP 4: Safety and Error Prevention
// ========================================

// SOLUTION: safeDeleteArray function - prevents memory leaks
void safeDeleteArray(int*& scores) {
    if (scores != nullptr) {
        delete[] scores;
        scores = nullptr;  // Prevent dangling pointer
        cout << "Score array deleted safely." << endl;
    } else {
        cout << "Array already null, no deletion needed." << endl;
    }
}

// SOLUTION: clearInventory function - clean up linked list
void clearInventory(Node*& head) {
    Node* temp;
    int itemCount = 0;
    
    while (head != nullptr) {
        temp = head;
        head = head->next;  // Move to next item
        delete temp;        // Delete current item
        itemCount++;
    }
    
    cout << "Inventory cleared. " << itemCount << " items deleted." << endl;
}

// Additional utility function for demonstration
int countInventoryItems(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// ========================================
// MAIN FUNCTION - Complete Demonstration
// ========================================

int main() {
    cout << "=== Adventure Game Memory Management System - SOLUTION ===" << endl;
    
    // Test Step 1: Function Parameter Passing with References
    cout << "\n--- Step 1: Character Management with References ---" << endl;
    Character hero("Aragorn", 1, 0, 80);
    hero.displayInfo();
    
    // Test levelUp function
    cout << "\nLeveling up character..." << endl;
    levelUp(hero);
    hero.displayInfo();
    
    // Test healCharacter function
    cout << "\nHealing character..." << endl;
    healCharacter(hero, 20);
    hero.displayInfo();
    
    cout << "\nTesting over-healing..." << endl;
    healCharacter(hero, 50);  // Should cap at 100
    hero.displayInfo();
    
    // Test Step 2: Inventory Management with Linked List
    cout << "\n--- Step 2: Inventory Management with Pointers ---" << endl;
    Node* inventory = nullptr;  // Empty inventory initially
    
    // Test addItem function
    cout << "\nAdding items to inventory..." << endl;
    addItem(inventory, "Health Potion");
    addItem(inventory, "Magic Sword");
    addItem(inventory, "Shield");
    addItem(inventory, "Gold Coin");
    
    // Test displayInventory function
    cout << "\nCurrent inventory:" << endl;
    displayInventory(inventory);
    cout << "Total items: " << countInventoryItems(inventory) << endl;
    
    // Test removeItem function
    cout << "\nRemoving 'Health Potion' from inventory..." << endl;
    if (removeItem(inventory, "Health Potion")) {
        cout << "Item removed successfully!" << endl;
    } else {
        cout << "Item not found!" << endl;
    }
    displayInventory(inventory);
    
    cout << "\nTrying to remove non-existent item..." << endl;
    if (removeItem(inventory, "Dragon Scale")) {
        cout << "Item removed successfully!" << endl;
    } else {
        cout << "Item 'Dragon Scale' not found in inventory!" << endl;
    }
    
    // Test Step 3: Dynamic Memory for Game Stats
    cout << "\n--- Step 3: Dynamic Score Management ---" << endl;
    const int numScores = 5;
    
    // Test createScoreArray function
    int* gameScores = createScoreArray(numScores);
    
    // Test updateScore function
    cout << "\nUpdating scores..." << endl;
    updateScore(gameScores, numScores, 0, 1500);
    updateScore(gameScores, numScores, 2, 2300);
    updateScore(gameScores, numScores, 4, 1800);
    
    // Test error handling
    cout << "\nTesting error handling..." << endl;
    updateScore(gameScores, numScores, 10, 999);  // Invalid index
    updateScore(nullptr, numScores, 0, 100);      // Null pointer
    
    // Test displayScores function
    cout << "\nGame scores:" << endl;
    displayScores(gameScores, numScores);
    
    // Test Step 4: Cleanup and Safety
    cout << "\n--- Step 4: Safe Memory Cleanup ---" << endl;
    
    // Test safeDeleteArray function
    cout << "\nCleaning up score array..." << endl;
    safeDeleteArray(gameScores);
    
    // Test double deletion safety
    cout << "Testing double deletion safety..." << endl;
    safeDeleteArray(gameScores);  // Should handle gracefully
    
    // Test clearInventory function
    cout << "\nClearing inventory..." << endl;
    clearInventory(inventory);
    
    // Verify inventory is empty
    cout << "Verifying inventory is empty:" << endl;
    displayInventory(inventory);
    
    // Demonstrate that all pointers are now null
    cout << "\nFinal safety check:" << endl;
    cout << "gameScores pointer: " << (gameScores == nullptr ? "NULL" : "NOT NULL") << endl;
    cout << "inventory pointer: " << (inventory == nullptr ? "NULL" : "NOT NULL") << endl;
    
    cout << "\n=== Adventure Game Demo Complete - All Memory Managed Safely! ===" << endl;
    
    return 0;
}

/*
SOLUTION FEATURES DEMONSTRATED:

STEP 1 - Reference Parameter Passing:
✓ Efficient function parameter passing without object copying
✓ Direct modification of objects through references
✓ Input validation and boundary checking

STEP 2 - Pointer-Based Data Structures:
✓ Dynamic linked list implementation
✓ Safe pointer navigation and manipulation
✓ Proper node creation and deletion
✓ Error handling for edge cases

STEP 3 - Dynamic Memory Management:
✓ Dynamic array allocation with new[]
✓ Safe array access with bounds checking
✓ Proper initialization of allocated memory
✓ Error handling for invalid parameters

STEP 4 - Memory Safety:
✓ Null pointer checking before operations
✓ Proper cleanup with delete and delete[]
✓ Setting pointers to nullptr after deletion
✓ Prevention of memory leaks and dangling pointers

ADDITIONAL FEATURES:
✓ Comprehensive error handling
✓ Informative console output for learning
✓ Edge case testing (over-healing, invalid indices, etc.)
✓ Memory safety verification
✓ Complete integration of all concepts

This solution demonstrates professional-level memory management
techniques essential for high-performance C++ applications.
*/