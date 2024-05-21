#include "Staff.h"
#include <iostream>

using namespace std;

// Constructor to initialize a Staff object with specific values
/* Staff::Staff(double posX, double posY, double speed, std::string role, double salary, int performanceRating, string name)
    : Person(posX, posY, speed, role), role(role), salary(salary), performanceRating(performanceRating),  {
    // Additional initialization specific to Staff can be added here
} */

Staff::Staff(string name, double salary) : Person(name){this->salary=salary;}

// Default constructor to initialize a Staff object with default values
Staff::Staff() : Staff("",0) {
    // Default initialization specific to Staff
}

// Method for the staff member to perform their duties
void Staff::performDuties() {
    cout << "Staff member with role " << role << " is performing their duties." << endl;
}

// Method for the staff member to attend training
void Staff::attendTraining() {
    cout << "Staff member with role " << role << " is attending training." << endl;
}

// Method for the staff member to report their progress
void Staff::reportProgress() {
    cout << "Staff member with role " << role << " is reporting their progress." << endl;
}

// Getter method for role
std::string Staff::getRole() const {
    return role;  // Return the role of the staff member
}

// Setter method for role
void Staff::setRole(std::string role) {
    this->role = role;  // Set the role of the staff member
}

// Getter method for salary
double Staff::getSalary() const {
    return salary;  // Return the salary of the staff member
}

// Setter method for salary
void Staff::setSalary(double salary) {
    this->salary = salary;  // Set the salary of the staff member
}

// Getter method for performance rating
int Staff::getPerformanceRating() const {
    return performanceRating;  // Return the performance rating of the staff member
}

// Setter method for performance rating
void Staff::setPerformanceRating(int performanceRating) {
    this->performanceRating = performanceRating;  // Set the performance rating of the staff member
}

