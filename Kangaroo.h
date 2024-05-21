#ifndef KANGAROO_H
#define KANGAROO_H

#include "Animal.h"
#include <string>
#include <cstdlib>
#include <ctime>

class Kangaroo : public Animal {
public:
    // Constructor to initialize a Kangaroo object
    Kangaroo(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat);
    
    // Default constructor
    Kangaroo();

    // Override the getFed method
    void getFed(std::string food, int amountKg) override;
    void getVisited();
    // Override the rest method
    void rest(int hours) override;

    // Additional methods specific to Kangaroo
    void jump();
};

#endif // KANGAROO_H
