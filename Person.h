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
        Person(double posX, double posY, double speed, string role):posX(posX),posY(posY),speed(speed),role(role){}
        Person():Person(0,0,5,""){}
        void Go(double goX, double goY){
            double xDiff = goX-posX;
            double yDiff = goY-posY;
            if (sqrt( xDiff*xDiff + yDiff*yDiff ) > 5){
                double angle = atan(yDiff/xDiff);
                double newSpeed = speed * (!((yDiff < 0) && (xDiff < 0)) * 2 - 1);
                newSpeed = speed * (!((yDiff > 0) && (xDiff < 0)) * 2 - 1);
                posX += newSpeed * cos(angle);
                posY += newSpeed * sin(angle);
                cout << "xDiff: " << xDiff << " yDiff: " << yDiff << endl;
            } else {
                posX = goX;
                posY = goY;
            }
        }

        double get_posX(){
            return posX;
        }
        double get_posY(){
            return posY;
        }
};

#endif