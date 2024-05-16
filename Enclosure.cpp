#include "Enclosure.h"

Enclosure::Enclosure(int posX, int posY, int enclosure_capacity){
    this->posX = posX;
    this->posY = posY;
    this->enclosure_capacity = enclosure_capacity;
}

Enclosure::Enclosure():Enclosure(0, 0, 0){}

void Enclosure::add_animal(Animal* a){
    if (Animals.size() <= enclosure_capacity){
        Animals.push_back(a);
    }
}