#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Animal.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>



class Elephant : public Animal {
public:
    // Constructor to initialize an Elephant object
    Elephant(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat);
    Elephant(int weight, string name);
    
    // Default constructor
    Elephant();

    // Override the getFed method
    void getFed(std::string food, int amountKg);
    void getVisited();

    // Override the rest method
    void rest(int hours);

    // Additional methods specific to Elephant
    void trumpet();
};

#endif // ELEPHANT_H

