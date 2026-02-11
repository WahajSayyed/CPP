#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int hitPoints;
    int attackStrength;
public:
    Character(const std::string& inputName, int point, int strength)
              : name(inputName), hitPoints(point), attackStrength(strength) {
              }
    std::string getName() const { return name;}
    int getHitPoints() const { return hitPoints; }
    int getAttackStrength() const { return attackStrength; }

    bool setName(std::string name) {
        if (name.size() < 3 || name.size() > 20) {
            std::cout << "Error: Name must be between 3 to 20 character long" << std::endl;
            return false;
        }
        this->name = name;
        return true;
    }

    bool setHitPoints(int points){
        if (points < 1 || points > 10) {
            std::cout << "Error: Points must be between 1 - 10" << std::endl;
            return false;
        }
        this->hitPoints += points;
        return true;
    }

    bool setAttackStrength(int strength){
        if (strength < 1 || strength > 5) {
            std::cout << "Error: Points must be between 1 - 5" << std::endl;
            return false;
        }
        this->attackStrength = strength;
        return true;
    }
    friend void displayCharacterInfo(Character& charctr);
};

void displayCharacterInfo(Character& charctr) {
    std::cout << "Name: " << charctr.name << ", HP: " << charctr.hitPoints 
                << ", Attack: " << charctr.attackStrength << std::endl;
}

int main() {
    Character heroheralal("Hero Hera Lal", 10, 5);
    displayCharacterInfo(heroheralal);
    heroheralal.setHitPoints(7);
    heroheralal.setAttackStrength(4);
    displayCharacterInfo(heroheralal);
}

// SAMPLE SOLUTION
// #include <iostream>
// #include <string>
// class Character {
// private:  // Step 2: Access control - protected game data
//     std::string name;
//     int hitPoints;
//     int attackStrength;
//     static const int MAX_HP = 200;
//     static const int MAX_ATTACK = 50;
// public:
//     // Constructor with validation
//     Character(std::string n, int hp, int attack) {
//         setName(n);
//         setHitPoints(hp);
//         setAttackStrength(attack);
//     }    
//     // Step 3: Getters for safe data access
//     std::string getName() const { return name; }
//     int getHitPoints() const { return hitPoints; }
//     int getAttackStrength() const { return attackStrength; }    
//     // Step 3: Setters with game logic validation
//     void setHitPoints(int hp) {
//         if (hp >= 0 && hp <= MAX_HP) {
//             hitPoints = hp;
//         } else {
//             std::cout << "Error: Invalid HP value!" << std::endl;
//         }
//     }    
//     void setAttackStrength(int attack) {
//         if (attack >= 1 && attack <= MAX_ATTACK) {
//             attackStrength = attack;
//         } else {
//             std::cout << "Error: Invalid attack value!" << std::endl;
//         }
//     }    
//     // Game mechanics methods
//     void takeDamage(int damage) {
//         if (damage > 0) {
//             hitPoints = std::max(0, hitPoints - damage);
//         }
//     }    
//     void displayInfo() const {
//         std::cout << "Name: " << name << ", HP: " << hitPoints 
//                   << ", Attack: " << attackStrength << std::endl;
//     }
    
//     // Step 4: Friend function for admin operations
//     friend void gameAdminBoost(Character& character, int hpBoost);
// };
// // Friend function for game master operations
// void gameAdminBoost(Character& character, int hpBoost) {
//     character.hitPoints += hpBoost;
//     character.hitPoints = std::min(character.hitPoints, character.MAX_HP);
// }