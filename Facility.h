#ifndef FACILITY_H
#define FACILITY_H

#include <string>
#include <vector>
#include <iostream>

#include "Zoo.h"
#include "Animal.h"
#include "Panda.h"
#include "Kangaroo.h"
#include "Elephant.h"
#include "Tortoise.h"
#include "Kiwi.h"
#include "Enclosure.h"
#include "Person.h"
#include "Visitor.h"

using namespace std;

class Facility{
    private:
        string name;
        int ID;

    public:
        Facility();
        Facility(string name, int ID);
        string get_name();
        int get_ID();

        void set_name(string _name);
        void set_ID(int _ID);
        
    

};

#endif