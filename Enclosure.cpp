#include "Enclosure.h"

Enclosure::Enclosure(int posX, int posY, int enclosure_capacity){
    this->posX = posX;
    this->posY = posY;
    this->enclosure_capacity = enclosure_capacity;
}

Enclosure::Enclosure():Enclosure(0, 0, 0){}

void Enclosure::add_animal(Animal* a){
    if (animals.size() <= enclosure_capacity){
        animals.push_back(a);
    }
}

void Enclosure::get_visited(){
    for (int i=0;i<animals.size();i++){
//        animals[i]->get_visited();
    }
}