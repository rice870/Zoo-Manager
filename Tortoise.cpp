#include "Tortoise.h"
#include <iostream>

using namespace std;

// Constructor to initialize a Tortoise object
Tortoise::Tortoise(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat)
    : Animal(weight, species, diet, name, favourite_treat) {
        this->visitWorth = 20;
    // Additional initialization specific to Tortoise
}

Tortoise::Tortoise(int weight, string name) : Animal(weight, "Tortoise", "Leaf", name, "Leaf"){}

// Default constructor
Tortoise::Tortoise() : Tortoise(0, "") {
    // Default initialization specific to Tortoise
}

// Override the getFed method
void Tortoise::getFed(std::string food, int amountKg) {
    Animal::getFed(food, amountKg);  // Call the base class implementation
    if (food == "Leaf") {
        happiness += amountKg;  // Tortoises are especially happy when they eat leaves
        cout << name << " the Tortoise is especially happy with leaves!" << endl;
    }
}

// Override the rest method
void Tortoise::rest(int hours) {
    Animal::rest(hours);  // Call the base class implementation
    // Additional behavior for Tortoise resting (if any)
}

// Additional methods specific to Tortoise
void Tortoise::hide() {
    cout << name << " the Tortoise is hiding in its shell!" << endl;
    happiness += 5;  // Increase happiness when hiding
}

