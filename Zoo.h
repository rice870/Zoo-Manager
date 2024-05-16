#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <vector>
#include <iostream>
#include "Animal.h"
#include "Person.h"
#include "Enclosure.h"

using namespace std;


class Zoo {
    private:
        string name;
        string location;

        bool openStatus;
        vector<Animal*> animals;
        int animalCapacity;
        int currentAnimals;
        int money;
        int cameraPosX;
        int amt_enclosures;


    public:
        Zoo();
        Zoo(string _name, bool _openStatus, int _animalCapacity, int money);
        string get_name();
        vector<Animal*> get_animals();
        void set_name(string _name);
        bool get_openStatus();
        void set_openStatus(bool _openStatus);
        void addAnimal(Animal* _animal);
        void openZoo();
        void clozeZoo();
        void set_animalCapacity(int _animalCapacity);
        void add_enclosure();
};

#endif