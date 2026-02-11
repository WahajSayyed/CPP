#include <iostream>
#include <string>
#include <vector>
// Environment entity - Dungeon Room
class Room {
private:  // Encapsulation - secure data management
    std::string description;
    std::vector<std::string> exits;
    std::vector<std::string> items;
public:
    // Constructor for initialization
    Room(std::string desc) : description(desc) {}    
    // Member functions for room behavior
    void enter() {
        std::cout << "You enter: " << description << std::endl;
        listExits();
    }    
    void addExit(std::string direction) {
        exits.push_back(direction);
    }    
    void addItem(std::string item) {
        items.push_back(item);
    }    
    void listExits() {
        std::cout << "Exits: ";
        for(const auto& exit : exits) {
            std::cout << exit << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    // Object interaction simulation
    Room dungeonRoom("A dark stone chamber with flickering torches");
    dungeonRoom.addExit("north");
    dungeonRoom.addExit("east");
    dungeonRoom.addItem("rusty key");    
    dungeonRoom.enter();  // Simulate player entering room    
    return 0;
}
