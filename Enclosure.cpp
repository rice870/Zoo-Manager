
//#include "Zoo.h"
#include "Animal.h"
#include "Enclosure.h"
/* #include "Panda.h"
#include "Kangaroo.h"
#include "Elephant.h"
#include "Tortoise.h"
#include "Kiwi.h"
#include "Facility.h"

#include "Person.h"
#include "Visitor.h" */

using namespace std;


//Enclosure::Enclosure(int posX, int posY, int enclosure_capacity){
//    this->posX = posX;
//    this->posY = posY;
//    this->enclosure_capacity = enclosure_capacity;
//}

//Enclosure::Enclosure():Enclosure(0, 0, 0){}



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

int Enclosure::getSize(){
    return animals.size();
}

void Enclosure::addAnimal(Animal* a){
    if (animals.size() < enclosureCapacity){
        animals.push_back(a);
        enclosedCount++;
    }
}

void Enclosure::removeAnimal(Animal* a){
    vector<Animal*>::iterator animalToDelete = find(animals.begin(), animals.end(), a);
    if (animalToDelete != animals.end()){
        string name = a->getName();
        animals.erase(animalToDelete);
        enclosedCount--;
        cout << name << " removed from enclosure: " << this->name << endl;
    }
}

string Enclosure::get_name() {
    return name;

}

int Enclosure::get_ID() {
    return ID;
}

void Enclosure::set_name(string _name) {
    name = _name;
}

void Enclosure::set_ID(int _ID) {
    ID = _ID;
}

int Enclosure::get_visited(){
    int expenditure;
    for (int i=0;i<enclosedCount;i++){
        animals[i]->getVisited();
        expenditure += animals[i]->getVisitWorth();
    }
    return expenditure;
}

vector<Animal*> Enclosure::get_animals(){
    return this->animals;
}

int Enclosure::get_enclosure_capacity(){
    return this->enclosureCapacity;
}

string Enclosure::get_species_type(){
    return speciesType;
}