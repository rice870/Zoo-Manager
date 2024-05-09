#ifndef ZOO_H
#define ZOO_H

#import <string>
#import <vector>
#import <iostream>
#include "Animal.h"
#include "Person.h"

using namespace std;


class Zoo {


    private:
        string name;
        string location;

        bool openStatus;
        vector<Animal*> animals;
        int animalCapacity;
        int currentAnimals;


    public:
        Zoo() {
            name = "";
            openStatus = false;
            currentAnimals = 0;
        }
        Zoo(string _name, bool _openStatus, int _animalCapacity) {
            name = _name;
            openStatus = _openStatus;
            animalCapacity = _animalCapacity;
            currentAnimals = 0;

        }
        string get_name() {
            return name;
        }
        vector get_animals() {
            return animals;
        }
        void set_name(string _name) {
            name = _name;
        }
        bool get_openStatus() {
            return openStatus;
        }
        void set_openStatus(bool _openStatus) {
            openStatus = _openStatus;
        }
        void addAnimal(Animal* _animal) {
            animals.push_back(_animal);
        }
        void openZoo() {
            openStatus = true;
        }
        void clozeZoo() {
            openStatus = false;
        }
        void set_animalCapacity(int _animalCapacity) {
            animalCapacity = _animalCapacity;
        }








};



#endif