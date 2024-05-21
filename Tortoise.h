#ifndef TORTOISE_H
#define TORTOISE_H

#include "Animal.h"
#include <string>

class Tortoise : public Animal {
public:
    // Constructor to initialize a Tortoise object
    Tortoise(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat);
    Tortoise(int weight, string name);
    
    // Default constructor
    Tortoise();

    // Override the getFed method
    void getFed(std::string food, int amountKg) override;

    // Override the rest method
    void rest(int hours) override;

    // Additional methods specific to Tortoise
    void hide();
};

#endif // TORTOISE_H

