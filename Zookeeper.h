#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H
#include "Staff.h"
#include "Animal.h"

class ZooKeeper : public Staff {
    public:
       // ZooKeeper(double posX, double posY, double speed, double salary, int performanceRating):Staff(posX,posY,speed,"ZooKeeper",salary,performanceRating){}
        ZooKeeper(string name, double salary) : Staff(name, salary){cout << "Welcome " << name << " to our zoo!";}
        ZooKeeper():ZooKeeper("",0){}

        void feed(Animal* a, string food, int amountKg);
};

#endif