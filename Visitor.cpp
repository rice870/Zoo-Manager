#include "Visitor.h"
#include <iostream>

using namespace std;

// Constructor to initialize a Visitor object
Visitor::Visitor(double posX, double posY, double speed, int age, std::string preferences, std::string visitDate)
    : Person(posX, posY, speed, "Visitor"), age(age), preferences(preferences), visitDate(visitDate) {}

// Default constructor
Visitor::Visitor() : Person(), age(0), preferences(""), visitDate("") {}

// Method for the visitor to enter the zoo
void Visitor::enterZoo() {
    cout << "A visitor has entered the zoo." << endl;
}

// Method for the visitor to visit an exhibit
void Visitor::visitExhibit() {
    cout << "A visitor is visiting an exhibit." << endl;
}

// Method for the visitor to make a purchase
void Visitor::makePurchase() {
    cout << "A visitor has made a purchase." << endl;
}

// Method to calculate the ticket price based on age
double Visitor::calculateTicketPrice() const {
    if (age < 12) {
        return 5.0;  // Child ticket price
    } else if (age >= 12 && age < 60) {
        return 10.0;  // Adult ticket price
    } else {
        return 7.0;  // Senior ticket price
    }
}

// Getter and Setter methods for new attributes
int Visitor::getAge() const {
    return age;
}

void Visitor::setAge(int age) {
    this->age = age;
}

std::string Visitor::getPreferences() const {
    return preferences;
}

void Visitor::setPreferences(std::string preferences) {
    this->preferences = preferences;
}

std::string Visitor::getVisitDate() const {
    return visitDate;
}

void Visitor::setVisitDate(std::string visitDate) {
    this->visitDate = visitDate;
}

