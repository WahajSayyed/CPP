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

// TODO: Implement levelUp function
// This function should take a Character reference and:
// - Add 100 to experience
// - Increment level by 1
// - Display a level up message
void levelUp(/* TODO: Add parameter */) {
    // TODO: Implement function body
    // Hint: Use reference parameter to avoid copying the Character object
}

// TODO: Implement healCharacter function
// This function should take a Character reference and healing amount:
// - Add healing amount to health
// - Ensure health doesn't exceed a maximum (e.g., 100)
// - Display healing message
void healCharacter(/* TODO: Add parameters */) {
    // TODO: Implement function body
}

// ========================================
// STEP 2: Data Structure Navigation with Pointers
// ========================================

// TODO: Implement addItem function
// This function should add an item to the front of the linked list
// Parameters: Node*& head (reference to pointer), const string& item
void addItem(/* TODO: Add parameters */) {
    // TODO: Create new node with the item
    // TODO: Set the new node's next pointer to current head
    // TODO: Update head to point to new node
    // Hint: Node* newNode = new Node(item, head);
}

// TODO: Implement displayInventory function
// This function should traverse and display all items in the linked list
void displayInventory(/* TODO: Add parameter */) {
    // TODO: Check if inventory is empty
    // TODO: Traverse the linked list using a pointer
    // TODO: Display each item name
    // Hint: Use a while loop with current->next
}

// TODO: Implement removeItem function
// This function should remove the first occurrence of an item from the list
// Return true if item was found and removed, false otherwise
bool removeItem(/* TODO: Add parameters */) {
    // TODO: Handle empty list case
    // TODO: Handle case where first item matches
    // TODO: Traverse list to find item
    // TODO: Update pointers to remove node
    // TODO: Delete the removed node
    // TODO: Return appropriate boolean value
}

// ========================================
// STEP 3: Efficient Memory Usage - Dynamic Allocation
// ========================================

// TODO: Implement createScoreArray function
// This function should dynamically allocate an array of integers
// Parameters: int initialSize
// Return: pointer to the allocated array
int* createScoreArray(/* TODO: Add parameter */) {
    // TODO: Allocate array using new
    // TODO: Initialize all elements to 0
    // TODO: Return pointer to array
    // Hint: int* scores = new int[initialSize];
}

// TODO: Implement displayScores function
// This function should display all scores in the array
// Parameters: int* scores, int size
void displayScores(/* TODO: Add parameters */) {
    // TODO: Check if scores pointer is valid
    // TODO: Loop through array and display each score
}

// TODO: Implement updateScore function
// This function should safely update a score at given index
// Parameters: int* scores, int size, int index, int newScore
// Return: true if update successful, false if invalid index
bool updateScore(/* TODO: Add parameters */) {
    // TODO: Validate parameters (scores not null, valid index)
    // TODO: Update score at index
    // TODO: Return success/failure status
}

// ========================================
// STEP 4: Safety and Error Prevention
// ========================================

// TODO: Implement safeDeleteArray function
// This function should safely delete a dynamically allocated array
void safeDeleteArray(/* TODO: Add parameters */) {
    // TODO: Check if pointer is not null
    // TODO: Delete the array using delete[]
    // TODO: Set pointer to nullptr (passed by reference)
}

// TODO: Implement clearInventory function
// This function should safely delete all nodes in the linked list
void clearInventory(/* TODO: Add parameter */) {
    // TODO: Create temporary pointer
    // TODO: Loop through list
    // TODO: Store current node in temp
    // TODO: Move to next node
    // TODO: Delete temp node
    // TODO: Set head to nullptr when done
}

// ========================================
// MAIN FUNCTION - Testing Ground
// ========================================

int main() {
    cout << "=== Adventure Game Memory Management System ===" << endl;
    
    // Test Step 1: Function Parameter Passing with References
    cout << "\n--- Step 1: Character Management with References ---" << endl;
    Character hero("Aragorn", 1, 0, 80);
    hero.displayInfo();
    
    // TODO: Test levelUp function
    cout << "Leveling up character..." << endl;
    // levelUp(hero);
    // hero.displayInfo();
    
    // TODO: Test healCharacter function
    cout << "Healing character..." << endl;
    // healCharacter(hero, 20);
    // hero.displayInfo();
    
    // Test Step 2: Inventory Management with Linked List
    cout << "\n--- Step 2: Inventory Management with Pointers ---" << endl;
    Node* inventory = nullptr;  // Empty inventory initially
    
    // TODO: Test addItem function
    cout << "Adding items to inventory..." << endl;
    // addItem(inventory, "Health Potion");
    // addItem(inventory, "Magic Sword");
    // addItem(inventory, "Shield");
    
    // TODO: Test displayInventory function
    cout << "Current inventory:" << endl;
    // displayInventory(inventory);
    
    // TODO: Test removeItem function
    cout << "Removing 'Health Potion' from inventory..." << endl;
    // if (removeItem(inventory, "Health Potion")) {
    //     cout << "Item removed successfully!" << endl;
    // } else {
    //     cout << "Item not found!" << endl;
    // }
    // displayInventory(inventory);
    
    // Test Step 3: Dynamic Memory for Game Stats
    cout << "\n--- Step 3: Dynamic Score Management ---" << endl;
    const int numScores = 5;
    
    // TODO: Test createScoreArray function
    // int* gameScores = createScoreArray(numScores);
    
    // TODO: Test updateScore function
    // updateScore(gameScores, numScores, 0, 1500);
    // updateScore(gameScores, numScores, 2, 2300);
    // updateScore(gameScores, numScores, 4, 1800);
    
    // TODO: Test displayScores function
    cout << "Game scores:" << endl;
    // displayScores(gameScores, numScores);
    
    // Test Step 4: Cleanup and Safety
    cout << "\n--- Step 4: Safe Memory Cleanup ---" << endl;
    
    // TODO: Test safeDeleteArray function
    // safeDeleteArray(gameScores);
    
    // TODO: Test clearInventory function
    // clearInventory(inventory);
    
    cout << "All memory cleaned up safely!" << endl;
    cout << "\n=== Adventure Game Demo Complete ===" << endl;
    
    return 0;
}

/*
IMPLEMENTATION CHECKLIST:
□ Step 1: levelUp function implemented
□ Step 1: healCharacter function implemented
□ Step 2: addItem function implemented
□ Step 2: displayInventory function implemented  
□ Step 2: removeItem function implemented
□ Step 3: createScoreArray function implemented
□ Step 3: displayScores function implemented
□ Step 3: updateScore function implemented
□ Step 4: safeDeleteArray function implemented
□ Step 4: clearInventory function implemented
□ All test calls in main() uncommented
□ Program compiles and runs without errors
□ No memory leaks (all new matched with delete)

SAFETY REMINDERS:
- Always check pointers for nullptr before dereferencing
- Match every 'new' with 'delete', every 'new[]' with 'delete[]'
- Set pointers to nullptr after deletion
- Use references for function parameters to avoid unnecessary copying
- Validate array indices before access
*/