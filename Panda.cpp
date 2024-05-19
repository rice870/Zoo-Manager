#include "Panda.h"
#include <iostream>

using namespace std;

// Constructor to initialize a Panda object
Panda::Panda(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat)
    : Animal(weight, species, diet, name, favourite_treat) {
    // Additional initialization specific to Panda
}

Panda::Panda(int weight, string name):Panda(weight, "Panda", "Bamboo", name, "Bamboo"){}

// Default constructor
Panda::Panda() : Animal() {
    // Default initialization specific to Panda
}

// Override the getFed method
void Panda::getFed(std::string food, int amountKg) {
    Animal::getFed(food, amountKg);  // Call the base class implementation
    if (food == "Bamboo") {
        happiness += amountKg;  // Pandas are especially happy when they eat bamboo
        cout << name << " the Panda is especially happy with bamboo!" << endl;
    }
}

// Override the rest method
void Panda::rest(int hours) {
    Animal::rest(hours);  // Call the base class implementation
    // Additional behavior for Panda resting (if any)
}

// Additional methods specific to Panda
void Panda::eatBamboo() {
    cout << name << " the Panda is eating bamboo!" << endl;
    hunger = max(hunger - 10, 0);  // Reduce hunger significantly
    happiness += 10;  // Increase happiness significantly
}

