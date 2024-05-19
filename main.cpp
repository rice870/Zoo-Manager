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
    std::string startingPandaName = "";
    std::cout << "Please enter the name of your zoo: ";
    std::cin >> userName;
    std::cout << "Please enter your zoo's location: ";
    std::cin >> userLocation;
    Zoo z(userName, userLocation, 50, 0, 10);
    std::cout << "Your zoo " << z.get_name() << " has been created in " << z.get_location() << "." << std::endl;
    std::cout << "You have a starting budget of " << z.get_money() << ", spend it wisely to grow your zoo." << std::endl;
    std::cout << "You have been gifted a panda enclosure to begin. Enter the name of your starting enclosure: ";
    std::cin >> startingEnclosureName;
    z.addEnclosure(new Enclosure(startingEnclosureName, 4, 5, "panda"));
    std::cout << "Your new enclosure " << z.enclosures[0]->get_name() << " was just created with an ID of " << z.enclosures[0]->get_ID() << std::endl;
    std::cout << "You've been gifted a panda for your zoo. Please name this panda: "
    std::cin >> startingPandaName;
    z.addAnimal(enclosures[0], new Panda(150, "Panda", "Omnivore", startingPandaName, "Bamboo"));
}