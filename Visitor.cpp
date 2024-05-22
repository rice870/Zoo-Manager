#include "Visitor.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructor to initialize a Visitor object
//Visitor::Visitor(double posX, double posY, double speed, int age, std::string preferences, std::string visitDate)
//    : Person(posX, posY, speed, "Visitor"), age(age), preferences(preferences), visitDate(visitDate) {}

Visitor::Visitor(string name, int age) : Person(name){this->age = age;}

// Default constructor
Visitor::Visitor() : Visitor("",0) {}

 void Visitor::chooseVisitSpots(Zoo* z){
    int facility_count = 0;
    for (int i=0;i<z->getFacilities().size();i++){
        if(rand() % 4 == 0){
            facility_count++;
            this->placesToVisit.push_back(z->getFacilities()[i]);
        }
    }
    if (facility_count == 0){
        this->placesToVisit.push_back(z->getFacilities()[0]);
    }
}

/* void Zoo::populateZoo() { // Written by Cooper Melville | This function is pretty similar to what enterZoo will do, fills up the visitors vector in Zoo
    srand(time(NULL));
    for(int i = 0; i > rand() % 100 + 50) { // Number of people that can come to the zoo is between 50 and 100
        int ageGenerator = rand() % 90;
        visitors[i] = new Visitor();

    }
    std::cout << countVisitors() << " people visited your zoo!" << std::endl;
} */


// Method for the visitor to visit an exhibit
void Visitor::visitFacility(Zoo * z) {
    if (placesToVisit.size() != 0){
        cout << "A visitor is visiting an exhibit." << endl;
        z->receiveMoney(placesToVisit[0]->getVisited());
        placesToVisit.erase(placesToVisit.begin());
    }
}


// Method for the visitor to make a purchase
/* void Visitor::makePurchase(Zoo *z, int payment) {
    cout << "A visitor has made a purchase." << endl;
    z->receiveMoney(payment)
} */

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

