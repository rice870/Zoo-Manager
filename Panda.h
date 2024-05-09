#ifndef PANDA_H
#define PANDA_H

#include "Animal.h"

class Panda : public Animal {
    public:
        Panda(int _weight, string _name):Animal(_weight, "panda", "bamboo", _name, "bamboo"){}

};


#endif