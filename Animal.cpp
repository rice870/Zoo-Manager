
#include "Animal.h"
#include <algorithm> // For std::max

// Constructor to initialize an Animal object with specific values
Animal::Animal(int weight, string species, string diet, string name, string favourite_treat) {
    this->fatigue = 0;  // Initial fatigue level is set to 0
    this->happiness = 0;  // Initial happiness level is set to 0
    this->hunger = 0;  // Initial hunger level is set to 0
    this->weight = weight;  // Set the weight of the animal
    this->species = species;  // Set the species of the animal
    this->diet = diet;  // Set the diet of the animal
    this->name = name;  // Set the name of the animal
    this->favourite_treat = favourite_treat;  // Set the favorite treat of the animal
    this->posX = 0;  // Initial X position is set to 0
    this->posY = 0;  // Initial Y position is set to 0
}

// Default constructor to initialize an Animal object with default values
Animal::Animal() : Animal(0, "", "", "", "") {}

// Method to feed the animal
void Animal::getFed(string food, int amountKg) {
    if (diet == food) {  // Check if the food matches the animal's diet
        hunger -= amountKg;  // Decrease hunger by the amount of food given
        hunger = max(hunger, 0);  // Ensure hunger does not go below 0
    }
    if (food == favourite_treat) {  // Check if the food is the animal's favorite treat
        hunger -= amountKg;  // Decrease hunger by the amount of treat given
        hunger = max(hunger, 0);  // Ensure hunger does not go below 0
        happiness += amountKg;  // Increase happiness by the amount of treat given
    }
}

// Method to make the animal rest
void Animal::rest(int hours) {
    fatigue -= hours;  // Decrease fatigue by the number of hours of rest
    fatigue = max(fatigue, 0);  // Ensure fatigue does not go below 0
}

// Setter methods
void Animal::setFatigue(int fatigue) {
    this->fatigue = fatigue;  // Set the fatigue level
}

void Animal::setHunger(int hunger) {
    this->hunger = hunger;  // Set the hunger level
}

void Animal::setWeight(int weight) {
    this->weight = weight;  // Set the weight
}

void Animal::setSpecies(string species) {
    this->species = species;  // Set the species
}

void Animal::setDiet(string diet) {
    this->diet = diet;  // Set the diet
}

void Animal::setName(string name) {
    this->name = name;  // Set the name
}

void Animal::setFavouriteTreat(string favourite_treat) {
    this->favourite_treat = favourite_treat;  // Set the favorite treat
}

void Animal::setPosX(int posX) {
    this->posX = posX;  // Set the X position
}

void Animal::setPosY(int posY) {
    this->posY = posY;  // Set the Y position
}

// Getter methods
int Animal::getFatigue() const {
    return fatigue;  // Return the fatigue level
}

int Animal::getHappiness() const {
    return happiness;  // Return the happiness level
}

int Animal::getHunger() const {
    return hunger;  // Return the hunger level
}

int Animal::getWeight() const {
    return weight;  // Return the weight
}

string Animal::getSpecies() const {
    return species;  // Return the species
}

string Animal::getName() const {
    return name;  // Return the name
}

string Animal::getFavouriteTreat() const {
    return favourite_treat;  // Return the favorite treat
}

int Animal::getPosX() const {
    return posX;  // Return the X position
}

int Animal::getPosY() const {
    return posY;  // Return the Y position
}
