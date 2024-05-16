#include "Zookeeper.h"

ZooKeeper::ZooKeeper(double posX, double posY, double speed){
    this->posX = posX;
    this->posY = posY;
    this->speed = speed;
    this->role = "ZooKeeper";
}

ZooKeeper::ZooKeeper():ZooKeeper(0,0,0){}

void ZooKeeper::feed(Animal* a, string food, int amountKg){
    a->getFed(food, amountKg);
}