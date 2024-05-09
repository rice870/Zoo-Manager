#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
using namespace std;

class Animal{
    protected:
        int fatigue;
        int happiness;
        int hunger;
        string species;
        string diet;
    public:
        Animal():fatigue(0),happiness(0),hunger(0),species(""),diet(""){}
        
        virtual void feed(string food, int amountKg){
            hunger -= amountKg;
        };

};

#endif