#include "Panda.h"

Panda::Panda(int _weight, string _name):Animal(_weight, "panda", "bamboo", _name, "bamboo"){}

void Panda::getFed(string food, int amountKg){
    if (food==this->diet){
        hunger -= amountKg/50;
        hunger = max(0,hunger);
        happiness += amountKg/100;
    }

}