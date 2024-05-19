
#ifndef KIWI_H
#define KIWI_H

#include "Animal.h"
#include <string>

class Kiwi : public Animal {
public:
    // Constructor to initialize a Kiwi object
    Kiwi(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat);
    
    // Default constructor
    Kiwi();

    // Override the getFed method
    void getFed(std::string food, int amountKg) override;

    // Override the rest method
    void rest(int hours) override;

    // Additional methods specific to Kiwi
    void dig();
};

#endif // KIWI_H