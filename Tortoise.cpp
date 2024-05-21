#include "Zoo.h"
#include "Animal.h"
//#include "Drinkshop.h"
//#include "Elephant.h"
#include "Enclosure.h"
#include "Facility.h"
//#include "Kangaroo.h"
//#include "Kiwi.h"
//#include "Panda.h"
//#include "Person.h"
//#include "Staff.h"
#include "Tortoise.h"
#include "Visitor.h"
//#include "Zookeeper.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor to initialize a Tortoise object
Tortoise::Tortoise(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat)
    : Animal(weight, species, diet, name, favourite_treat) {
    // Additional initialization specific to Tortoise
}

// Default constructor
Tortoise::Tortoise() : Animal() {
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

void Tortoise::getVisited() {

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

