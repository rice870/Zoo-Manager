#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Animal.h"
#include <string>



class Elephant : public Animal {
public:
    // Constructor to initialize an Elephant object
    Elephant(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat);
    
    // Default constructor
    Elephant();

    // Override the getFed method
    void getFed(std::string food, int amountKg) override;

    // Override the rest method
    void rest(int hours) override;

    // Additional methods specific to Elephant
    void trumpet();
};

#endif // ELEPHANT_H

