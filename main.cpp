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
#include "Panda.h"
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
    std::cout << "You've been gifted a panda for your zoo. Please name this panda: ";
    std::cin >> startingPandaName;
    z.addAnimal(z.get_enclosures()[0], new Panda(150, "Panda", "Omnivore", startingPandaName, "Bamboo"));
    while(z.get_money() > 0) {
        int userSelect = 0;
        while(true) {
            std::cout << "You have $" << z.get_money() << std::endl; 
            std::cout << "Press 1 to begin Day " << z.get_daysOpen() + 1 << std::endl;
            std::cout << "Press 2 to enter the shop" << std::endl;
            std::cout << "Press 3 to feed and view your animals" << std::endl;
            std::cin >> userSelect;

            switch (userSelect) {
                case 1:
                    // starts game, populates zoo with people
                    break;

                case 2:
                    while(true) {
                        std::cout << "From the shop, you can buy animal food, new animals, and new facilities such as enclosures." << std::endl;
                        std::cout << "Press 1 for the food menu" << std::endl;
                        std::cout << "Press 2 for the animals menu" << std::endl;
                        std::cout << "Press 3 for the facilities menu" << std::endl;
                        std::cin >> userSelect;
                        switch (userSelect) {
                            case 1:
                                while(true) {
                                    std::cout << "Animal food:" << std::endl;
                                    std::cout << "Press 1 to buy bamboo (For pandas) | Price: $5" << std::endl;
                                    std::cout << "Press 6 to exit the shop" << std::endl; 
                                    std::cin >> userSelect;
                                    switch(userSelect) {
                                        case 1:
                                            if(z.get_money() >= 5) {
                                                z.set_bamboo(z.get_bamboo() + 1);
                                                z.set_money(z.get_money() - 5);
                                                std::cout << "Bamboo purchased" << std::endl;
                                            } else {
                                                std::cout << "You do not have enough money for this item" << std::endl;
                                            }
                                            continue;
                                        case 6:
                                            break;
                                        

                                    }
                                    break;
                                }
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            default:
                                std::cout << "That is not a valid option" << std::endl;
                                continue;
                            break;
                        }
                        break;
                    }
                    break;
                case 3:
                    break;
                default:
                    std::cout << "That is not a valid option" << std::endl;
                    continue;
                break;
            }



        };


    }
    std::cout << "You are out of money! Game over" << std::endl;

}