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
        string facilityName;
        int facilityID;

    public:
        Facility();
        Facility(string name, int facilityID)
        string get_name();
        int get_facilityID();

        void set_name(string _name);
        int set_facilityID(int _ID);
        
    

};

#endif