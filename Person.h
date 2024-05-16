#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Person{
    protected:
        double posX;
        double posY;
        double speed;
        string role;
    public:
        Person(double posX, double posY, double speed, string role);
        Person();
        void Go(double goX, double goY);
        double get_posX();
        double get_posY();
        void set_speed(double speed);
};

#endif