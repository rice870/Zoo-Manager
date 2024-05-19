#include "Zoo.h"
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


Facility::Facility() {
    name = "";
    ID = 0;
}

Facility::Facility(string name, int ID) {
    this->name = name;
    this->ID = ID; // ID should always be the number corresponding to how many enclosures there are eg. first facility has ID of 1, second has ID of 2, so on.
}


string Facility::get_name() {
    return name;
}

int Facility::get_ID() {
    return ID:
}

void Facility::set_name(string _name) {
    name = _name;
}

void Facility::set_ID(int _ID) {
    ID = _ID;
}