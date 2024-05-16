#include "Person.h"

Person::Person(double posX, double posY, double speed, string role){
   this->posX == posX;
   this->posY == posY;
   this->speed == speed;
   this->role == role;
}

Person::Person():Person(0,0,5,""){}

void Person::Go(double goX, double goY){
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

double Person::get_posX(){
   return posX;
}
double Person::get_posY(){
   return posY;
}

void Person::set_speed(double speed){
   this->speed = speed;
}