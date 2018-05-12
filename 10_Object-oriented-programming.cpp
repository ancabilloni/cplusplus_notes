#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <functional> // for function

/* Example class and inheritance */

class Animal{
private :
    std::string name;
    double height;
    double weight;
    
    // static variable is a shared value between all values
    static int numOfAnimals;
    
public:
    std::string GetName(){return name;}
    void SetName(std::string name){this->name = name;}
    double GetHeight(){return height;}
    void SetHeight(double height){this->height = height;}
    double GetWeight(){return weight;}
    void SetWeight(double weight){this->weight = weight;}
    
    void SetAll(std::string, double, double);
    Animal(std::string, double, double); // call each time an object is created
    Animal();
    ~Animal(); // Deconstructor
    static int GetNumOfAnimals(){return numOfAnimals;}
    void ToString();
};

int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight){
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}

Animal::Animal(std::string name, double height, double weight){
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}

Animal::Animal(){
    this->name = "";
    this->weight = 0;
    this->height = 0;
    Animal::numOfAnimals++;
}

Animal::~Animal(){
    std::cout << "Animal " << this->name << " destroyed\n";
}

void Animal::ToString(){
    std::cout << this->name << " is " << this->height << " cms tall and "
            << this->weight << " kgs in weight\n";
}

class Dog: public Animal{
private:
    std::string sound = "Woof";
public:
    void MakeSound(){std::cout << "The dog " <<
            this->GetName() << " say " <<
            this->sound << "\n";
    }
    Dog(std::string, double, double, std::string);
    Dog(): Animal(){};
    void ToString();
};

Dog::Dog(std::string name, double height, 
        double weight, std::string sound) :
        Animal(name, height, weight){
    this-> sound = sound;
}

// Animal private, so cannot use this->name, height, weight
// Need to use GetName, GetHeight, GetWeight
void Dog::ToString(){
    std::cout << this->GetName() << " is " <<
            this->GetHeight() <<
            " cms tall and " <<
            this->GetWeight() <<
            " kgs in weight and says " <<
            this->sound <<"\n";
}

int main(){
    
    Animal fred;
    fred.ToString();
    fred.SetHeight(33);
    fred.SetWeight(10);
    fred.SetName("Fred");
    fred.ToString();
    Animal tom("Tom", 36, 15);
    tom.ToString();
    Dog spot("Spot", 38, 16, "Wooof");
    spot.ToString();
    
    std::cout << "Number of Animals " <<
            Animal::GetNumOfAnimals() << "\n";
    
    return 0;
}

/* Warrior Fight Example */

class Warrior{
private:
    int attkMax;
    int blockMax;
public:
    std::string name;
    int health;
    Warrior(std::string name, int health, int attkMax, int blockMax){
        this->name = name;
        this->health = health;
        this->attkMax = attkMax;
        this->blockMax = blockMax;
    };
    int Attack(){
        return std::rand() % this->attkMax;
    }
    int Block(){
        return std::rand() % this->blockMax;
    }
};

class Battle{
public:
    static void StartFight(Warrior& warrior1, Warrior& warrior2){
        while(true){
            if(Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0){
                std::cout << "Game Over\n";
                break;
            }
            if(Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0){
                std::cout << "Game Over\n";
                break;
            }
        }
    };
    
    static std::string GetAttackResult(Warrior& warriorA, Warrior& warriorB){
        int warriorAAttkAmt = warriorA.Attack();
        int warriorBBlockAmt = warriorB.Block();
        int damage2WarriorB = std::ceil(warriorAAttkAmt - warriorBBlockAmt);
        damage2WarriorB = (damage2WarriorB <= 0) ? 0 :
            damage2WarriorB;
        
        warriorB.health = warriorB.health - damage2WarriorB;
        warriorB.health = (warriorB.health <= 0) ? 0 :
            warriorB.health;
        
        printf("%s attack %s and deals %d damage\n",
                warriorA.name.c_str(), //c_str is to print with %s
                warriorB.name.c_str(),
                damage2WarriorB);
        printf("%s is down to %d health\n",
                warriorB.name.c_str(),
                warriorB.health);
        
        if(warriorB.health <= 0){
            printf("%s has Died and %s is Victorious\n",
                    warriorB.name.c_str(),
                    warriorA.name.c_str());
            return "Game Over";
        } else {
            return "Fight Again";
        }
    }
};

int main(){
    srand(time(NULL));
    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 25, 10);
    
    Battle::StartFight(thor, hulk);
}
