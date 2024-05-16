#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class Animal {
    protected:
        int fatigue;
        int happiness;
        int hunger;
        int weight;
        // If we implement a graphics thing this might be good
        int posX;
        int posY;
        string species;
        string diet;
        string name;
        string favourite_treat;
    public:
        Animal(int weight, string species, string diet, string name, string favourite_treat);
        Animal();
        virtual void getFed(string food, int amountKg);
        virtual void rest(int hours);

        /* we need to figure out how treats will differ from food
        virtual void receivefavourite_treat(string treat) */ 
        void set_fatigue(int fatigue);
        void set_hunger(int hunger);
        void set_weight(int weight);
        void set_fatigue(string species);
        void set_diet(string diet);
        void set_name(string name);
        void set_favourite_treat(string favourite_treat);
        int get_fatigue();
        int get_happiness();
        int get_hunger();
        int get_weight();
        string get_species();
        string get_name();
        string get_favourite_treat();
};

#endif