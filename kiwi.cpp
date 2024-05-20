#include "Kiwi.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor to initialize a Kiwi object
Kiwi::Kiwi(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat)
    : Animal(weight, species, diet, name, favourite_treat) {
        visitWorth=6;
    // Additional initialization specific to Kiwi
}

// Default constructor
Kiwi::Kiwi() : Animal() {
    // Default initialization specific to Kiwi
}

// Override the getFed method
void Kiwi::getFed(std::string food, int amountKg) {
    Animal::getFed(food, amountKg);  // Call the base class implementation
    if (food == "Insect") {
        happiness += amountKg;  // Kiwis are especially happy when they eat insects
        cout << name << " the Kiwi is especially happy with insects!" << endl;
    }
}

void Kiwi::getVisited(){
    srand(time(nullptr));
    if (rand() % 6 == 0){
        this->dig();
    }
}

// Override the rest method
void Kiwi::rest(int hours) {
    Animal::rest(hours);  // Call the base class implementation
    // Additional behavior for Kiwi resting (if any)
}

// Additional methods specific to Kiwi
void Kiwi::dig() {
    cout << name << " the Kiwi is digging!" << endl;
    happiness += 5;  // Increase happiness when digging
}

