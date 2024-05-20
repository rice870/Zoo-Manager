#ifndef VISITOR_H
#define VISITOR_H

#include "Person.h"
#include <string>

class Visitor : public Person {
    private:
        int age;                // Age of the visitor
        std::string preferences; // Preferences of the visitor
        std::string visitDate;   // Date of the visit

    public:
        // Constructor to initialize a Visitor object
        Visitor(double posX, double posY, double speed, int age, std::string preferences, std::string visitDate);
        
        // Default constructor
        Visitor();

        // Methods specific to Visitor
        void enterZoo();
        void visitExhibit();
        void makePurchase();

        // Method to calculate the ticket price based on age
        double calculateTicketPrice() const;

        // Getter and Setter methods for new attributes
        int getAge() const;
        void setAge(int age);
        std::string getPreferences() const;
        void setPreferences(std::string preferences);
        std::string getVisitDate() const;
        void setVisitDate(std::string visitDate);
};

#endif // VISITOR_H

