#include "Zookeeper.h"


void ZooKeeper::feed(Animal* a, string food, int amountKg){
    a->getFed(food, amountKg);
}