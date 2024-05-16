#ifndef PANDA_H
#define PANDA_H

#include "Animal.h"

class Panda : public Animal {
    public:
        Panda(int _weight, string _name);
        void getFed(string food, int amountKg);
};


#endif