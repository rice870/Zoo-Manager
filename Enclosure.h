#ifndef ENCLOSURE_H
#define ENCLOSURE_H

//#include "Zoo.h"
#include "Animal.h"
#include "Facility.h"
/* #include "Panda.h"
#include "Kangaroo.h"
#include "Elephant.h"
#include "Tortoise.h"
#include "Kiwi.h"
#include "Person.h"
#include "Visitor.h" */

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Enclosure : public Facility {
    private:
        //vector<Animal*> animals;
        //int enclosure_capacity;
        //int posX;
        //int posY;

        int enclosureCapacity;
        vector<Animal*> animals;
        string speciesType;
        int enclosedCount;
        int ID;
        string name;

    public:
        Enclosure();
        Enclosure(string name, int ID, int enclosureCapacity, string speciesType);
        
        void addAnimal(Animal* animal);
        void removeAnimal(Animal* animal);
        int getSize();
        string get_name();
        int get_ID();
        void set_name(string _name);
        void set_ID(int _ID);
        int get_visited();
        vector<Animal*> get_animals();
        int get_enclosure_capacity();
        string get_species_type();




        //Enclosure(int posX, int posY, int enclosure_capacity);
        // void get_visited();
};

#endif