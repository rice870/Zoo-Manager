

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <algorithm> // For std::max
using namespace std;

class Animal {
protected:
    int fatigue;           // Tiredness level of the animal
    int happiness;         // Happiness level of the animal
    int hunger;            // Hunger level of the animal
    int weight;            // Weight of the animal
    int posX;
    int posY;        // Position of the animal within the zoo
    string species;        // Species of the animal
    string diet;           // Diet of the animal
    string name;           // Name of the animal
    string favourite_treat;// Favourite treat of the animal
    int ID;
    int visitWorth;

public:
    // Constructor to initialize an Animal object
    Animal(int weight, string species, string diet, string name, string favourite_treat);

    // Default constructor
    Animal();

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Animal() = default;

    // Methods to perform actions
    virtual void getFed(string food, int amountKg);
    virtual void getVisited(){}
    virtual void rest(int hours);

    // Setter methods
    void setFatigue(int fatigue);
    void setHunger(int hunger);
    void setWeight(int weight);
    void setSpecies(string species);
    void setDiet(string diet);
    void setName(string name);
    void setFavouriteTreat(string favourite_treat);
    void setPosX(int posX);
    void setPosY(int posY);
    void setID(int ID);

    // Getter methods
    int getFatigue() const;
    int getHappiness() const;
    int getHunger() const;
    int getWeight() const;
    string getSpecies() const;
    string getName() const;
    string getFavouriteTreat() const;
    int getPosX() const;
    int getPosY() const;
    int getID() const;
    int getVisitWorth() const;
};

#endif // ANIMAL_H
