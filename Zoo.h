#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
#include <vector>

#include "Animal.h"
#include "Panda.h"
#include "Kangaroo.h"
#include "Elephant.h"
#include "Tortoise.h"
#include "Kiwi.h"
#include "Enclosure.h"
#include "Facility.h"
#include "Person.h"

using namespace std;


class Zoo {
    private:
        string name;
        string location; // Name and location can be chosen by the user. 

        int money; // Lets say the user begins the game with $500 or so.
        int daysOpen; // Increments at the end of the loop in main.cpp, at the start of the new day
        //The user should begin the game with one enclosure containing one animal.
        //vector<Visitor*> visitors;
        vector<int> usedAnimalIDs;
        int animalCapacity; // In a later development, this should be able to be upgraded by the user.
        int facilityCount;
        int enclosureCount;
        int animalCount; // Probably just counts all of the animals inside all of the enclosures
        //int cameraPosX;
        //vector<Animal*> allAnimals; // Animals will have 
        //bool openStatus;
        vector<Facility*> facilities;
        int bamboo;
        int fruit;
        int insects;
        int leaves;
        int australian_grass;


    public:
        Zoo();
        Zoo(string name, string location, int money, int daysOpen, int animalCapacity);
        void get_status();
        
        void addEnclosure(Enclosure* enclosure);
        void addFacility(Facility* facility);
        void receiveMoney(int payment);
        void pay(int payment);
        void addBamboo(int amount);
        void addInsects(int amount);
        void addFruit(int amount);
        void addLeaves(int amount);
        void addAustralianGrass(int amount);
        int generateUniqueID();
        void addAnimal(Enclosure* enclosure, Animal* animal);
        void releaseAnimal(int _IDchoose); 
        int countAnimals();
        int countFacilities();
        int countEnclosures();
        vector<Enclosure*> enclosures; // The zoo will have a vector of all if its enclosures, each enclosure can be seperately called, enclosures will each contain a animal pointer vector.
        vector<Animal*> allAnimals; // Think this should be public, as its being called directly in the addAnimal() function. Correct if wrong

        string get_name();
        string get_location();
        int get_money();
        int get_daysOpen();
        vector<Enclosure*> get_enclosures(); 
        vector<Animal*> get_animals();
        vector<Facility*> getFacilities();
        int get_animalCapacity();
        int get_enclosureCount();
        int get_animalCount();
        int get_bamboo();
        int get_insects();
        int get_fruit();
        int get_leaves();
        int get_Australian_grass();


        void set_name(string _name);
        void set_location(string _location);
        void set_money(int _money);
        void set_daysOpen(int _daysOpen);
        // enclosures doesn't really need a setter, as the vector will be modified with other functions such as addEnclosure(), etc
        void set_animalCapacity(int _animalCapacity);
        void set_enclosureCount(int _enclosureCount); 
        void set_animalCount(int _animalCount); 
        void set_bamboo(int _bamboo);


};

#endif