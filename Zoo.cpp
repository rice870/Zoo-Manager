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
    currentAnimals = 0;
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
    currentAnimals = 0;


}





void Zoo::addEnclosure(Enclosure enclosure) {
    enclosures->push_back(enclosure);
    enclosureCount++;
}
// void addAnimal(Enclosure* enclosure, Animal* animal); A bit more involved, this might have to go in the enclosure class



//void releaseAnimal(int _IDchoose) {
//    for(int i = 0; i < animalCount; i++) {
//        if(get_ID() == _IDchoose) {
//            
//        }
//    }   
//}

int countAnimals() {
    int count = 0;
    for(int i = 0; i < enclosureCount; i++) {
        count += *(enclosures[i]).size();
    }
    return count; // this function's output should always be assigned to the attribute animalCount
}

int countFacilities() {
    int count = 0;
    for(int i = 0; i < enclosureCount; i++) { // This will also include the total number of, say for example, shops, later on.
        count++; // Currently, countFacilities() and countEnclosures() do the same thing, as enclosure is the only facility.
    }
    return count;

}

int countEnclosures() {
    int count = 0;
    for(int i = 0; i < enclosureCount; i++) { 
        count++; 
    }
    return count;
}

string Zoo::get_name() {
    return name:
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
int Zoo::get_animalCapacity() {
    return animalCapacity;
}
int Zoo::get_enclosureCount() {
    return enclosureCount;
}
int Zoo::get_animalCount() {
    return animalCount;
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


//vector<Animal*> Zoo::get_animals() { Think this goes in enclosures
//    return animals;
//}


//void Zoo::addAnimal(Animal* _animal) {
//    animals.push_back(_animal);
//}
