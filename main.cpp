#include <iostream>
#include <vector>
#include <string>
#include "Zoo.h"
#include "Animal.h"
#include "Drinkshop.h"
#include "Elephant.h"
#include "Enclosure.h"
#include "Facility.h"
#include "Kangaroo.h"
#include "Kiwi.h"
#include "Panda.h"
#include "Person.h"
#include "Staff.h"
#include "Tortoise.h"
#include "Visitor.h"
#include "Zoo.h"
#include "Zookeeper.h"


int main() {
    string userName = "";
    string userLocation = "";
    std::cin << "Please enter the name of your zoo: " << userName << std::endl;
    std::cin << "Please enter your zoo's location: " << userLocation << std::endl;
    Zoo z(userName, userLocation, 50, 0, 10);
    std::cout << "Your zoo " << z.get_name() << " has been created in " << z.get_location() << "." << std::endl;
    
}