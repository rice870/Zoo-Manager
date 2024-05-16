#include <string>
#include <vector>
#include <iostream>
#include "Animal.h"
#include "Person.h"
#include "Enclosure.h"
#include "Zoo.h"

Zoo::Zoo() {
    name = "";
    openStatus = false;
    currentAnimals = 0;
}
Zoo::Zoo(string _name, bool _openStatus, int _animalCapacity) {
    name = _name;
    openStatus = _openStatus;
    animalCapacity = _animalCapacity;
    currentAnimals = 0;

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