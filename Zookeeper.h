#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H
#include "Staff.h"
#include "Animal.h"

class ZooKeeper : public Staff {
    public:
        ZooKeeper(double posX, double posY, double speed):Staff(posX,posY,speed,"ZooKeeper"){}
        ZooKeeper():ZooKeeper(0,0,0){}

        void feed(Animal* a, string food, int amountKg);
};

#endif