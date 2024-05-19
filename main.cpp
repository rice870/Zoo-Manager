#include <iostream>
#include <vector>
#include <string>
#include "Zoo.h"
#include "Animal.h"
//#include "Drinkshop.h"
//#include "Elephant.h"
#include "Enclosure.h"
#include "Facility.h"
//#include "Kangaroo.h"
//#include "Kiwi.h"
//#include "Panda.h"
//#include "Person.h"
//#include "Staff.h"
//#include "Tortoise.h"
//#include "Visitor.h"
//#include "Zookeeper.h"


int main() {
    std::string userName = "";
    std::string userLocation = "";
    std::string startingEnclosureName = "";
    std::cout << "Please enter the name of your zoo: ";
    std::cin >> userName;
    std::cout << "Please enter your zoo's location: ";
    std::cin >> userLocation;
    Zoo z(userName, userLocation, 50, 0, 10);
    std::cout << "Your zoo " << z.get_name() << " has been created in " << z.get_location() << "." << std::endl;
    std::cout << "Enter the name of your starting enclosure: ";
    std::cin >> startingEnclosureName;
    z.enclosures[0] = new Enclosure(startingEnclosureName, 0, 5, "panda");
    std::cout << "Your new enclosure " << z.enclosures[0]->get_name() << " was just created with an ID of " << z.enclosures[0]->get_ID() << std::endl;
}