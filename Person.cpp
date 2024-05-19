#include "Person.h"
#include <cmath> // For math functions

// Constructor to initialize a Person object with specific values
Person::Person(double posX, double posY, double speed, std::string role)
    : posX(posX), posY(posY), speed(speed), role(role) {}

// Default constructor
Person::Person() : Person(0.0, 0.0, 0.0, "") {}

// Method to move the person to a new position
void Person::Go(double goX, double goY) {
    // Calculate the distance to move
    double distance = sqrt(pow(goX - posX, 2) + pow(goY - posY, 2));

    // Move the person to the new position based on speed
    if (distance <= speed) {
        posX = goX;
        posY = goY;
    } else {
        posX += (goX - posX) * (speed / distance);
        posY += (goY - posY) * (speed / distance);
    }
}

// Getter methods
double Person::getPosX() const {
    return posX;  // Return the X position
}

double Person::getPosY() const {
    return posY;  // Return the Y position
}

// Setter method for speed
void Person::setSpeed(double speed) {
    this->speed = speed;  // Set the movement speed
}

// Getter method for speed
double Person::getSpeed() const {
    return speed;  // Return the movement speed
}

// Setter method for role
void Person::setRole(std::string role) {
    this->role = role;  // Set the role
}

// Getter method for role
std::string Person::getRole() const {
    return role;  // Return the role
}

