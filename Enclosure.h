#ifndef ENCLOSURE_H
#define ENCLOSURE_H


#include <vector>
#include "Animal.h"

using namespace std;


class Enclosure : public Facility {
    private:




        //vector<Animal*> animals;
        //int enclosure_capacity;
        //int posX;
        //int posY;
    public:
        Enclosure(int posX, int posY, int enclosure_capacity);
        Enclosure();
        void add_animal(Animal* a);
        void get_visited();
};

#endif