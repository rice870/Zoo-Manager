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
#include "Facility.h"
#include "Person.h"
#include "Visitor.h"
Zoo::Zoo() {
    name = "";
    openStatus = false;
    currentAnimals = 0;
}
Zoo::Zoo(string _name, bool _openStatus, int _animalCapacity, int money) {
    this->name = _name;
    this->openStatus = _openStatus;
    this->animalCapacity = _animalCapacity;
    this->money = money;
    currentAnimals = 0;
    int amt_enclosures = 1;

}
string Zoo::get_name() {
    return name;
}
vector<Animal*> Zoo::get_animals() {
    return animals;
}
void Zoo::set_name(string _name) {
    name = _name;
}
bool Zoo::get_openStatus() {
    return openStatus;
}
void Zoo::set_openStatus(bool _openStatus) {
    openStatus = _openStatus;
}
void Zoo::addAnimal(Animal* _animal) {
    animals.push_back(_animal);
}

void Zoo::releaseAnimal(string _nameChoose) {
    
    animals.remove();
}

void Zoo::openZoo() {
    openStatus = true;
}
void Zoo::clozeZoo() {
    openStatus = false;
}
void Zoo::set_animalCapacity(int _animalCapacity) {
    animalCapacity = _animalCapacity;
}