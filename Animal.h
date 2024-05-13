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
        Animal(int weight, string species, string diet, string name, string favourite_treat):fatigue(0),happiness(0),hunger(0),weight(weight),species(species),diet(diet),name(name),favourite_treat(favourite_treat),posX(0),posY(0){}
        
        virtual void getFed(string food, int amountKg){
            if (diet==food){
                hunger -= amountKg;
                hunger = max(hunger, 0);
            }
           
            if (favourite_treat==food){
                hunger -= amountKg;
                hunger = max(hunger, 0);
                happiness += amountKg;
            }
        };

        virtual void rest(int hours){
            fatigue -= hours;
            fatigue = max(fatigue, 0);
        }

        /* we need to figure out how treats will differ from food
        virtual void receivefavourite_treat(string treat){
            if (favourite_treat==treat){
                happiness++;
            }
        } */ 

        void set_fatigue(int fatigue){
            this->fatigue = fatigue;
        }

        void set_hunger(int hunger){
            this->hunger = hunger;
        }

        void set_weight(int weight){
            this->weight = weight;
        }

        void set_fatigue(string species){
            this->species = species;
        }

        void set_diet(string diet){
            this->diet = diet;
        }

        void set_name(string name){
            this->name = name;
        }

        void set_favourite_treat(string favourite_treat){
            this->favourite_treat = favourite_treat;
        }

        int get_fatigue(){
            return fatigue;
        }

        int get_happiness(){
            return happiness;
        }

        int get_hunger(){
            return hunger;
        }

        int get_weight(){
            return weight;
        }

        string get_species(){
            return species;
        }

        string get_name(){
            return name;
        }

        string get_favourite_treat(){
            return favourite_treat;
        }
};

#endif