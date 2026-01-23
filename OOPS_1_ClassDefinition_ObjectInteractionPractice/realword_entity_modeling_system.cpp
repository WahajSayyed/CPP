#include <iostream>
#include <string>

class Knight{
private:
    std::string name;
    int health;
    std::string strength;

public:
    Knight(std::string knightName, std::string kstrength)
    : name(knightName), health(100), strength(kstrength){        
    }
    void under_attack() {
        if (health >= 10){
            health -= 10;
        } else {
            std::cout << "Knight " << name << " is dead. Game Over." << std::endl;
        }
    }
    void attack(){
        if (health < 100){
            health += 5;
        }
    }
    void displayKnightInfo() const {
        std::cout << "Name: " << name
        << "| Health: " << health
        << "| Strength: " << strength << std::endl
        << "----------------------------" << std::endl;
    }    
};

class Sword{
private:
    std::string type;
    int weight;
};

class Environment{
private:
    std::string place;
    std::string weather;
    int temp;
public:
    Environment(std::string envPlace, std::string env, int envtmp){
        place = envPlace;
        weather  = env;
        temp = envtmp;
    }
    void displayEnv() const {
        std::cout << "Place: " << place
        << "\nWeather: " << weather
        << "\nTemprature: " << temp
        << std::endl;
    }
};

int main(){
    Environment env("Battle Ground", "Sunny", 40);
    env.displayEnv();
    Knight jay("Jay", "SuperPower");
    Knight martin("Martin", "Power");

    jay.displayKnightInfo();
    martin.displayKnightInfo();
    martin.attack();
    jay.under_attack();

    jay.displayKnightInfo();
    martin.displayKnightInfo();

    jay.attack();
    martin.under_attack();

    jay.displayKnightInfo();
    martin.displayKnightInfo();
}
