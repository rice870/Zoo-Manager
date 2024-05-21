#include "Kangaroo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor to initialize a Kangaroo object
Kangaroo::Kangaroo(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat)
    : Animal(weight, species, diet, name, favourite_treat) {
    // Additional initialization specific to Kangaroo
}

// Default constructor
Kangaroo::Kangaroo() : Animal() {
    // Default initialization specific to Kangaroo
}

// Override the getFed method
void Kangaroo::getFed(std::string food, int amountKg) {
    Animal::getFed(food, amountKg);  // Call the base class implementation
    if (food == favourite_treat) {
        happiness += amountKg;  // Kangaroos are especially happy when they eat their favourite treat
        cout << name << " the Kangaroo is especially happy with " << favourite_treat << "!" << endl;
    }
}

void Kangaroo::getVisited(){
    srand(time(NULL));
    if (rand() % 4 == 0){
        this->jump();
    }
    this->fatigue++;
}

// Override the rest method
void Kangaroo::rest(int hours) {
    Animal::rest(hours);  // Call the base class implementation
    // Additional behavior for Kangaroo resting (if any)
}

// Additional methods specific to Kangaroo
void Kangaroo::jump() {
    cout << name << " the Kangaroo is jumping!" << endl;
    happiness += 5;  // Increase happiness when jumping
}

