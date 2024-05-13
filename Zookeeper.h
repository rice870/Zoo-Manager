#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H
#include "Person.h"
#include "Animal.h"

class ZooKeeper : public Person {
    public:
        ZooKeeper(double posX, double posY, double speed):Person(posX,posY,speed,"ZooKeeper"){}
        ZooKeeper():ZooKeeper(0,0,0){}

        void feed(Animal* a, string food, int amountKg){
            a->getFed(food, amountKg);
        }
};

#endif