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
#include "Visitor.h"

using namespace std;


class Zoo {
    private:
        string name;
        string location; // Name and location can be chosen by the user. 

        int money; // Lets say the user begins the game with $500 or so.
        int daysOpen; // Increments at the end of the loop in main.cpp, at the start of the new day
        vector<Enclosure*> enclosures; // The zoo will have a vector of all if its enclosures, each enclosure can be seperately called, enclosures will each contain a animal pointer vector.
        //The user should begin the game with one enclosure containing one animal.
        vector<Visitor*> visitors;
        int animalCapacity; // In a later development, this should be able to be upgraded by the user.
        int facilityCount;
        int enclosureCount;
        int animalCount; // Probably just counts all of the animals inside all of the enclosures
        //int cameraPosX;
        vector<Animal*> allAnimals; // Animals will have 
        //bool openStatus;


    public:
        Zoo();
        Zoo(string name, string location, int money, int daysOpen, int animalCapacity);
        void addEnclosure(Enclosure* enclosure);
        void addAnimal(Enclosure* enclosure, Animal* animal);
        void releaseAnimal(int _IDchoose); 
        int countAnimals();
        int countFacilities();
        int countEnclosures();




        string get_name();
        string get_location();
        int get_money();
        int get_daysOpen();
        vector<Enclosure*> get_enclosures(); // Unsure if this is correct, it probably is, but it might be a bit more complicated of a getter than the other attributes because its a vector
        //vector<Animal*> get_animals();
        int get_animalCapacity();
        int get_enclosureCount();
        int get_animalCount();


        void set_name(string _name);
        void set_location(string _location);
        void set_money(int _money);
        void set_daysOpen(int _daysOpen);
        // enclosures doesn't really need a setter, as the vector will be modified with other functions such as addEnclosure(), etc
        void set_animalCapacity(int _animalCapacity);
        void set_enclosureCount(int _enclosureCount); 
        void set_animalCount(int _animalCount); 


};

#endif