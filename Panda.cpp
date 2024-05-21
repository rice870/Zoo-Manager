#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "Zoo.h"
#include "Animal.h"
#include "Panda.h"
/* #include "Kangaroo.h"
#include "Elephant.h"
#include "Tortoise.h"
#include "Kiwi.h"
#include "Enclosure.h"
#include "Facility.h"
#include "Person.h"
#include "Visitor.h" */

using namespace std;

// Constructor to initialize a Panda object
Panda::Panda(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat)
    : Animal(weight, species, diet, name, favourite_treat) {
    // Additional initialization specific to Panda
}

Panda::Panda(int weight, string name):Panda(weight, "Panda", "Bamboo", name, "Bamboo"){
    visitWorth = 15;
}

// Default constructor
Panda::Panda() : Animal() {
    // Default initialization specific to Panda
}

// Override the getFed method
void Panda::getFed(std::string food, int amountKg) {
    Animal::getFed(food, amountKg);  // Call the base class implementation
    if (food == "bamboo") {
        happiness += amountKg;  // Pandas are especially happy when they eat bamboo
        cout << name << " the Panda is especially happy with bamboo!" << endl;
    }
}

void Panda::getVisited(){
    if (rand() % 4 == 0){
        this->eatBamboo();
    }
    this->fatigue++;
}

// Override the rest method
void Panda::rest(int hours) {
    Animal::rest(hours);  // Call the base class implementation
    // Additional behavior for Panda resting (if any)
}

// Additional methods specific to Panda
void Panda::eatBamboo() {
    cout << name << " the Panda is eating some bamboo from his habitat!" << endl;
    hunger = max(hunger - 10, 0);  // Reduce hunger significantly
    happiness += 10;  // Increase happiness significantly
}

