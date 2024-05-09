#ifndef ZOO_H
#define ZOO_H

#import <string>
#import <iostream>
#include "Animal.h"
#include "Person.h"

using namespace std;


class Zoo {


    private:
        string name;
        string

        Animal* animals;

    public:
        string get_name();
        Animal* get_animals();
        void set_name();
        void addAnimal();
        




};



#endif