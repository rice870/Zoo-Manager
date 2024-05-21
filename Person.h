#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    protected:
        double posX;    // X position of the person in the zoo
        double posY;    // Y position of the person in the zoo
        double speed;   // Movement speed of the person
        std::string role; // Role of the person (e.g., staff, visitor)
        std::string name;

    public:
        // Constructor to initialize a Person object with specific values
        Person(double posX, double posY, double speed, std::string role);
        Person(std::string name):name(name){}

        // Default constructor
        Person();

        // Method to move the person to a new position
        void Go(double goX, double goY);

        // Getter methods
        double getPosX() const;   // Get the X position
        double getPosY() const;   // Get the Y position

        // Setter method for speed
        void setSpeed(double speed);

        // Getter method for speed (optional, if needed)
        double getSpeed() const;

        std::string getName() const{return this->name;}

        // Setter and Getter methods for role (optional, if needed)
        void setRole(std::string role);
        std::string getRole() const;
};

#endif // PERSON_H

