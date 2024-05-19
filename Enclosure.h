#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include "Zoo.h"
#include "Animal.h"
//#include "Panda.h"
#include "Kangaroo.h"
#include "Elephant.h"
#include "Tortoise.h"
#include "Kiwi.h"
#include "Facility.h"
#include "Person.h"
#include "Visitor.h"

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
        int getSize();
        string get_name();
        int get_ID();
        void set_name(string _name);
        void set_ID(int _ID);




        //Enclosure(int posX, int posY, int enclosure_capacity);
        // void get_visited();
};

#endif