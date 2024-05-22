#include "TicketTaker.h"
#include <iostream>

TicketTaker::TicketTaker(std::string name, double salary) {
    this->name = name;
    this->salary = salary;
}

TicketTaker::TicketTaker() : TicketTaker("", 0) {}

void TicketTaker::get_status(){
    std::cout << "Name: " << this->name << " | Salary: " << this->salary;
}