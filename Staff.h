#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include <string>

class Staff : public Person {
protected:
    std::string role;        // Role of the staff member (e.g., zookeeper, veterinarian)
    std::string name;
    double salary;           // Salary of the staff member
    int performanceRating;   // Performance rating of the staff member

public:
    // Constructor to initialize a Staff object with specific values
    //Staff(double posX, double posY, double speed, std::string role, double salary, int performanceRating, std::string name);
    Staff(std::string name, double salary);

    // Default constructor
    Staff();

    // Method for the staff member to perform their duties
    void performDuties();

    // Method for the staff member to attend training
    void attendTraining();

    // Method for the staff member to report their progress
    void reportProgress();

    // Getter and Setter methods for new attributes
    std::string getRole() const;         // Get the role of the staff member
    void setRole(std::string role);      // Set the role of the staff member
    double getSalary() const;            // Get the salary of the staff member
    void setSalary(double salary);       // Set the salary of the staff member
    int getPerformanceRating() const;    // Get the performance rating of the staff member
    void setPerformanceRating(int performanceRating); // Set the performance rating of the staff member
};

#endif // STAFF_H

