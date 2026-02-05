/*You are developing a role-playing game character system. Create a base Character class and specialized Warrior and Mage derived classes with proper inheritance relationships.

🔍 Practice
Complete and test the character system using the code below:
    Create Warrior and Mage objects with different attributes
    Call displayStats() on each character to verify inheritance works
    Use attack() and castSpell() methods to test specialized behaviors
    Observe constructor and destructor output to understand the calling sequence

Experiment with access control:

    Try accessing private members directly (should fail)
    Access protected members from derived classes (should work)
    Use getter methods to access private data safely*/

#include <iostream>
#include <string>
using namespace std;
// TODO: Implement Character base class
class Character {
private:
    string name;        // Only Character class can modify name    
protected:
    int health;         // Derived classes need access for combat
    int speed;          // Derived classes use for abilities    
public:
    // Constructor with member initialization
    Character(const string& n, int h, int s) : name(n), health(h), speed(s) {
        cout << "Character " << name << " created" << endl;
    }    
    // Virtual destructor - essential for inheritance
    virtual ~Character() {
        cout << "Character " << name << " destroyed" << endl;
    }    
    // Virtual method for polymorphism
    virtual void displayStats() const {
        cout << "Name: " << name << ", Health: " << health << ", Speed: " << speed << endl;
    }    
    // Controlled access to private members
    string getName() const { return name; }    
    // Validation methods for protected members
    void setHealth(int h) {
        health = (h >= 0) ? h : 0;
    }    
    int getHealth() const { return health; }
};
// TODO: Implement Warrior derived class
class Warrior : public Character {
private:
    int strength;    
public:
    Warrior(const string& name, int health, int speed, int str) 
        : Character(name, health, speed), strength(str) {
        cout << "Warrior " << getName() << " created with strength " << strength << endl;
    }    
    ~Warrior() {
        cout << "Warrior " << getName() << " destroyed" << endl;
    }    
    void displayStats() const override {
        Character::displayStats();
        cout << "Strength: " << strength << ", Class: Warrior" << endl;
    }    
    void attack() {
        int damage = strength + (speed / 2);
        cout << getName() << " attacks for " << damage << " damage!" << endl;
    }
};
// TODO: Implement Mage derived class
class Mage : public Character {
private:
    int mana;    
public:
    Mage(const string& name, int health, int speed, int m) 
        : Character(name, health, speed), mana(m) {
        cout << "Mage " << getName() << " created with " << mana << " mana" << endl;
    }    
    ~Mage() {
        cout << "Mage " << getName() << " destroyed" << endl;
    }    
    void displayStats() const override {
        Character::displayStats();
        cout << "Mana: " << mana << ", Class: Mage" << endl;
    }    
    void castSpell() {
        if (mana >= 10) {
            int damage = mana / 2 + speed;
            mana -= 10;
            cout << getName() << " casts spell for " << damage << " damage!" << endl;
        } else {
            cout << getName() << " has insufficient mana!" << endl;
        }
    }
};

int main() {
    cout << "=== Character ===" << endl;
    Character c("Base Character", 100, 100);
    c.getName();
    c.displayStats();
    c.getHealth();
    cout << "================" << endl;
    cout << "=== Warrior ===" << endl;
    Warrior w("Warrior Character", 200, 250, 100);
    w.getName();
    w.displayStats();
    w.getHealth();
    w.attack();
    cout << "================" << endl;
    cout << "=== Mage ===" << endl;
    Mage m("Mage Character", 300, 350, 50);
    m.getName();
    m.displayStats();
    m.getHealth();
    m.castSpell();
    cout << "================" << endl;
}

/*✅ Success Checklist
Character base class properly encapsulates common attributes

Warrior and Mage classes inherit correctly and add specialization

Constructor chaining calls base class constructor first

Access specifiers prevent inappropriate member access

Virtual destructor ensures proper cleanup*/