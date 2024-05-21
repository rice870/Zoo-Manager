//
//  Panda.hpp
//  zoo management
//
//  Created by yanzhen li on 17/5/2024.
//

#ifndef PANDA_H
#define PANDA_H
#include <string>
#include <vector>
#include <iostream>
//#include "Zoo.h"
#include "Animal.h"
/* #include "Kangaroo.h"
#include "Elephant.h"
#include "Tortoise.h"
#include "Kiwi.h"
#include "Enclosure.h"
#include "Facility.h"
#include "Person.h" */
//#include "Visitor.h"

using namespace std;

class Panda : public Animal {
public:
    // Constructor to initialize a Panda object
    Panda(int weight, std::string species, std::string diet, std::string name, std::string favourite_treat);

    Panda(int weight, string name);
    
    // Default constructor
    Panda();

    // Override the getFed method
    void getFed(std::string food, int amountKg) override;
    void getVisited() override;

    // Override the rest method
    void rest(int hours) override;

    // Additional methods specific to Panda
    //void eatBamboo();
};

#endif // PANDA_H
