#include "Elephant.h"
#include <iostream>

using namespace std;

// Constructor to initialize an Elephant object
Elephant::Elephant(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat)
    : Animal(weight, species, diet, name, favourite_treat) {
    // Additional initialization specific to Elephant
}

// Default constructor
Elephant::Elephant() : Animal() {
    // Default initialization specific to Elephant
}

// Override the getFed method
void Elephant::getFed(std::string food, int amountKg) {
    Animal::getFed(food, amountKg);  // Call the base class implementation
    if (food == "Fruit") {
        happiness += amountKg;  // Elephants are especially happy when they eat fruit
        cout << name << " the Elephant is especially happy with fruit!" << endl;
    }
}

// Override the rest method
void Elephant::rest(int hours) {
    Animal::rest(hours);  // Call the base class implementation
    // Additional behavior for Elephant resting (if any)
}

// Additional methods specific to Elephant
void Elephant::trumpet() {
    cout << name << " the Elephant is trumpeting!" << endl;
    happiness += 10;  // Increase happiness when trumpeting
}

