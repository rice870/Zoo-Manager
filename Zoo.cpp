
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

using namespace std;
Zoo::Zoo() {
    name = "";
    location = "";
    money = 0;
    daysOpen = 0;
    animalCapacity = 0;
    enclosureCount = 0;
    animalCount = 0;
    bamboo = 0;
}

Zoo::Zoo(string name, string location, int money, int daysOpen, int animalCapacity) {
    this->name = name;
    this->location = location;
    this->money = money;
    this->daysOpen = daysOpen;
    this->animalCapacity = animalCapacity;
    daysOpen = 0;
    enclosureCount = 0;
    animalCount = 0;
    bamboo = 0;
}


void Zoo::addEnclosure(Enclosure* enclosure) {
    enclosures.push_back(enclosure);
    enclosureCount++;
}

int Zoo::generateUniqueID() {
    int id;

    while (find(usedAnimalIDs.begin(), usedAnimalIDs.end(), id) != usedAnimalIDs.end()){
        id = std::rand(); // Generate a random ID
    }

    usedAnimalIDs.push_back(id); // Mark the ID as used
    return id; // Return the unique ID
}
void Zoo::addAnimal(Enclosure* enclosure, Animal* animal) {
    cout << "Welcome " << animal->getName() << "!" << endl;
    int id = generateUniqueID();
    animal->setID(id); // Set the unique ID to the animal
    allAnimals.push_back(animal);
    enclosure->addAnimal(animal); // Add the animal to the enclosure
    animalCount++;
}

void Zoo::releaseAnimal(int _IDchoose) {
    //cout << "Release animal called for ID: " << _IDchoose << endl;
    for(int i = 0; i < animalCount; i++) {
        if(allAnimals[i]->getID() == _IDchoose) {
            //cout << "Animal with ID: " << _IDchoose << " found!" << endl;
            string animalName = allAnimals[i]->getName();
            Animal* removedAnimal = allAnimals[i];
            allAnimals.erase(allAnimals.begin()+i);
            animalCount--;
            for (int j = 0; j < enclosureCount; j++) {
                enclosures[j]->removeAnimal(removedAnimal);
            }
            cout << animalName << " removed from zoo!" << endl;
        }
        
    }   
}

int Zoo::countAnimals() {
    int count = 0;
    for(int i = 0; i < enclosureCount; i++) {
        count += enclosures[i]->getSize();
    }
    return count; // this function's output should always be assigned to the attribute animalCount
}

int Zoo::countFacilities() {
    int count = 0;
    for(int i = 0; i < enclosureCount; i++) { // This will also include the total number of, say for example, shops, later on.
        count++; // Currently, countFacilities() and countEnclosures() do the same thing, as enclosure is the only facility.
    }
    return count;

}

int Zoo::countEnclosures() {
    int count = 0;
    for(int i = 0; i < enclosureCount; i++) { 
        count++; 
    }
    return count;
}



string Zoo::get_name() {
    return name;
}
string Zoo::get_location() {
    return location;
}
int Zoo::get_money() {
    return money;
}
int Zoo::get_daysOpen() {
    return daysOpen;
}
vector<Enclosure*> Zoo::get_enclosures() {
    return enclosures;
} 
vector<Animal*> Zoo::get_animals(){
    return allAnimals;
}
int Zoo::get_animalCapacity() {
    return animalCapacity;
}
int Zoo::get_enclosureCount() {
    return enclosureCount;
}
int Zoo::get_animalCount() {
    return animalCount;
}

int Zoo::get_bamboo() {
    return bamboo;
}

void Zoo::set_name(string _name) {
    name = _name;
}
void Zoo::set_location(string _location) {
    location = _location;
}
void Zoo::set_money(int _money) {
    money = _money;
}
void Zoo::set_daysOpen(int _daysOpen) {
    daysOpen = _daysOpen;
}
void Zoo::set_animalCapacity(int _animalCapacity) {
    animalCapacity = _animalCapacity;
}
void Zoo::set_enclosureCount(int _enclosureCount) {
    enclosureCount = _enclosureCount;
} 
void Zoo::set_animalCount(int _animalCount) {
    animalCount = _animalCount;
} 

void Zoo::set_bamboo(int _bamboo) {
    bamboo = _bamboo;
}
//vector<Animal*> Zoo::get_animals() { Think this goes in enclosures
//    return animals;
//}


//void Zoo::addAnimal(Animal* _animal) {
//    animals.push_back(_animal);
//}
