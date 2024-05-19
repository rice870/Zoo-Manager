
#include "Zoo.h"
#include "Animal.h"
#include "Panda.h"
#include "Kangaroo.h"
#include "Elephant.h"
#include "Tortoise.h"
#include "Kiwi.h"
#include "Facility.h"
#include "Enclosure.h"
#include "Person.h"
#include "Visitor.h"

using namespace std;


//Enclosure::Enclosure(int posX, int posY, int enclosure_capacity){
//    this->posX = posX;
//    this->posY = posY;
//    this->enclosure_capacity = enclosure_capacity;
//}

//Enclosure::Enclosure():Enclosure(0, 0, 0){}

void Enclosure::add_animal(Animal* a){
    if (animals.size() <= enclosure_capacity){
        animals.push_back(a);
    }
}

//void Enclosure::get_visited(){
//    for (int i=0;i<animals.size();i++){
//        animals[i]->get_visited();
//    }
//}

Enclosure::Enclosure() {
    name = "";
    ID = 0;
    enclosureCapacity = 0;
    speciesType = "";
    enclosedCount = 0;
}

Enclosure::Enclosure(string name, int ID, int enclosureCapacity, string speciesType) {
    this->name = name;
    this->ID = ID;
    this->enclosureCapacity = enclosureCapacity;
    this->speciesType = speciesType;
    enclosedCount = 0;
}

void Enclosure::addAnimal(Animal* animal) {
    set_animalCount(countAnimals());
    if(enclosureCapacity < animals.size() || get_animalCount < animals.size()) {
        animals.push_back(animal);
    }
}