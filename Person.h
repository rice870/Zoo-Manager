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
            double newSpeed;
            if (sqrt( xDiff*xDiff + yDiff*yDiff ) > speed){
                double angle = atan(yDiff/xDiff);

                // these basically adjust for any of the 4 quadrants the desired spot could be in relative to the Person object
                newSpeed = speed * (!((yDiff < 0) && (xDiff < 0)) * 2 - 1);
                newSpeed = newSpeed * (!((yDiff > 0) && (xDiff < 0)) * 2 - 1);

                // it'll move toward the desired location, scaled by it's speed
                posX += newSpeed * cos(angle);
                posY += newSpeed * sin(angle);
            } else {
                // if the desired location is within a distance of speed, it will instantly go there
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

        void set_speed(double speed){
            this->speed = speed;
        }
};

#endif