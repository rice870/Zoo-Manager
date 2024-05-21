#include <iostream>
#include <fstream>
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
#include "Staff.h"
//#include "Tortoise.h"
#include "Visitor.h"
#include "Zookeeper.h"

using namespace std;


int main() {
    ifstream inputFile("Names.txt");
    vector<string> names;
    string line;
    while (getline(inputFile, line)) {
        names.push_back(line);
    }

    int day=0;
    const int COST_PANDA = 200;
    const int COST_PANDA_ECLOSURE = 2500;
    const int COST_BAMBOO = 5;
    const int COST_KIWI = 85;
    const int COST_PANDA_ECLOSURE = 1250;
    const int COST_INSECT = 10;
    const int COST_ELEPHANT = 500;
    const int COST_ELEPHANT_ENCLOSURE = 7500;
    const int COST_FRUIT = 25;
    const int COST_LEAVES = 13;
    const int COST_TORTOISE = 150;
    const int COST_TORTOISE_ENCLOSURE = 2000;
    const int COST_AUSTRALIAN_GRASS = 18;
    const int COST_KANGAROO = 500;
    const int COST_KANGAROO_ENCLOSURE = 5000;

    const int COST_ZOOKEEPER = 50;

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
    z.addEnclosure(new Enclosure(startingEnclosureName, 4, 5, "Panda"));
    std::cout << "Your new enclosure " << z.enclosures[0]->get_name() << " was just created with an ID of " << z.enclosures[0]->get_ID() << std::endl;
    std::cout << "You've been gifted a panda for your zoo. Please name this panda: ";
    std::cin >> startingPandaName;
    z.addAnimal(z.get_enclosures()[0], new Panda(150, "Panda", "Omnivore", startingPandaName, "Bamboo"));

    vector<ZooKeeper*> zookeepers;

    while(z.get_money() > 0) {
        int userSelect = 0;
        while(true) {
            srand(time(NULL));
            std::cout << "You have $" << z.get_money() << std::endl; 
            std::cout << "Press 1 to begin Day " << z.get_daysOpen() + 1 << std::endl;
            std::cout << "Press 2 to enter the shop" << std::endl;
            std::cout << "Press 3 to feed and view your animals" << std::endl;
            std::cin >> userSelect;

            switch (userSelect) {
                {
                    case 1:
                        srand(time(NULL));
                        // All animals increase in hunger by 1
                        for (int i=0;i<z.allAnimals.size();i++){
                            z.allAnimals[i]->increaseHunger();
                        }

                        // Create visitors
                        int visitorAmount = rand() % 5 + z.getFacilities().size();
                        Visitor* visitors[visitorAmount];

                        // Visitors enter the gate
                        for (int i=0;i<visitorAmount;i++){
                            visitors[i] = new Visitor(names[rand() % 1000], rand() % 75);
                            cout << visitors[i]->getName() << ", " << visitors[i]->getAge() << " years old, has just entered our zoo!" << endl;
                            z.receiveMoney(visitors[i]->calculateTicketPrice());
                        }

                        // Visitors visit facility
                        for (int i=0;i<z.getFacilities().size();i++){
                            for (int j=0;j<visitorAmount;j++){
                                visitors[j]->visitFacility(&z);
                            }
                        }

                        // Feed animals
                        vector<Animal*> animalsToFeed = z.get_animals();
                        for (int i=0;i<zookeepers.size();i++){
                            for (int j=0;j<10;j++){
                                if (animalsToFeed.size() != 0){
                                    Animal* animalToFeed = animalsToFeed[rand() % animalsToFeed.size()];
                                    if (animalToFeed->getSpecies()=="Panda"){
                                        if (z.get_bamboo() > 0){
                                            zookeepers[i]->feed(animalToFeed, "Bamboo", 1);
                                            z.addBamboo(-1);
                                        } else {
                                            std::cout << "Zookeeper, " << zookeepers[i]->getName() << ", tried to feed " << animalToFeed->getName() << " but there was insufficient bamboo to do so!" << endl;
                                        }
                                    } else if (animalToFeed->getSpecies()=="Kiwi"){
                                        if (z.get_insects() > 0){
                                            zookeepers[i]->feed(animalToFeed, "Insects", 1);
                                            z.addInsects(-1);
                                        } else {
                                            std::cout << "Zookeeper, " << zookeepers[i]->getName() << ", tried to feed " << animalToFeed->getName() << " but there was insufficient " << animalToFeed->getFavouriteTreat() << " to do so!" << std::endl;
                                        }
                                    } else if (animalToFeed->getSpecies()=="Elephant"){
                                        if (z.get_fruit() > 0){
                                            zookeepers[i]->feed(animalToFeed, animalToFeed->getFavouriteTreat(), 1);
                                            z.addFruit(-1);
                                        } else {
                                            std::cout << "Zookeeper, " << zookeepers[i]->getName() << ", tried to feed " << animalToFeed->getName() << " but there was insufficient " << animalToFeed->getFavouriteTreat() << " to do so!" << std::endl;
                                        }
                                    } else if (animalToFeed->getSpecies()=="Tortoise"){
                                        if (z.get_leaves() > 0){
                                            zookeepers[i]->feed(animalToFeed, animalToFeed->getFavouriteTreat(), 1);
                                            z.addLeaves(-1);
                                        } else {
                                            std::cout << "Zookeeper, " << zookeepers[i]->getName() << ", tried to feed " << animalToFeed->getName() << " but there was insufficient " << animalToFeed->getFavouriteTreat() << " to do so!" << std::endl;
                                        }
                                    } else if (animalToFeed->getSpecies()=="Kangaroo"){
                                        if (z.get_Australian_grass() > 0){
                                            zookeepers[i]->feed(animalToFeed, animalToFeed->getFavouriteTreat(), 1);
                                            z.addAustralianGrass(-1);
                                        } else {
                                            std::cout << "Zookeeper, " << zookeepers[i]->getName() << ", tried to feed " << animalToFeed->getName() << " but there was insufficient " << animalToFeed->getFavouriteTreat() << " to do so!" << std::endl;
                                        }
                                    }
                                }
                            }
                            z.pay(COST_ZOOKEEPER * zookeepers.size());
                        }

                        break;
                }

                case 2:
                    while(true) {
                        std::cout << "From the shop, you can buy animal food, new animals, and new facilities such as enclosures." << std::endl;
                        std::cout << "Press 1 for the food menu" << std::endl;
                        std::cout << "Press 2 for the animals menu" << std::endl;
                        std::cout << "Press 3 for the facilities menu" << std::endl;
                        std::cout << "Press 4 for the workers menu" << std::endl;
                        std::cin >> userSelect;
                        switch (userSelect) {
                            case 1:
                                while(true) {
                                    // Food menu
                                    std::cout << "Animal food:" << std::endl;
                                    std::cout << "Press 1 to buy bamboo (For pandas) | Price: $" << COST_BAMBOO << " per kg" << std::endl;
                                    std::cout << "Press 2 to buy insects (For kiwi) | Price: $" << COST_INSECT << " per kg" << std::endl;
                                    std::cout << "Press 3 to buy fruit (For elephants) | Price: $" << COST_FRUIT << " per kg" << std::endl;
                                    std::cout << "Press 4 to buy leaves (For tortoises) | Price: $" << COST_LEAVES << " per kg" << std::endl;
                                    std::cout << "Press 5 to buy Australian grass (For kangaroos) | Price: $" << COST_AUSTRALIAN_GRASS << " per kg" << std::endl;
                                    std::cout << "Press 6 to exit the shop" << std::endl; 
                                    std::cin >> userSelect;
                                    switch(userSelect) {
                                        case 1:
                                            int amount_to_buy;
                                            std::cout << "How many kg of bamboo would you like to buy? " << std::endl;
                                            std::cin >> amount_to_buy;
                                            if (amount_to_buy * COST_BAMBOO <= z.get_money()){
                                                z.pay(amount_to_buy * COST_BAMBOO);
                                                z.addBamboo(amount_to_buy);
                                            } else {
                                                std::cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 2:
                                            int amount_to_buy;
                                            std::cout << "How many kg of insects would you like to buy? " << std::endl;
                                            std::cin >> amount_to_buy;
                                            if (amount_to_buy * COST_INSECT <= z.get_money()){
                                                z.pay(amount_to_buy * COST_INSECT);
                                                z.addInsects(amount_to_buy);
                                            } else {
                                                std::cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 3:
                                            int amount_to_buy;
                                            std::cout << "How many kg of fruit would you like to buy? " << std::endl;
                                            std::cin >> amount_to_buy;
                                            if (amount_to_buy * COST_FRUIT <= z.get_money()){
                                                z.pay(amount_to_buy * COST_FRUIT);
                                                z.addFruit(amount_to_buy);
                                            } else {
                                                std::cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 4:
                                            int amount_to_buy;
                                            std::cout << "How many kg of leaves would you like to buy? " << std::endl;
                                            std::cin >> amount_to_buy;
                                            if (amount_to_buy * COST_LEAVES <= z.get_money()){
                                                z.pay(amount_to_buy * COST_LEAVES);
                                                z.addLeaves(amount_to_buy);
                                            } else {
                                                std::cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 5:
                                            int amount_to_buy;
                                            std::cout << "How many kg of Australian Grass would you like to buy? " << std::endl;
                                            std::cin >> amount_to_buy;
                                            if (amount_to_buy * COST_AUSTRALIAN_GRASS <= z.get_money()){
                                                z.pay(amount_to_buy * COST_AUSTRALIAN_GRASS);
                                                z.addAustralianGrass(amount_to_buy);
                                            } else {
                                                std::cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 6:
                                            break;

                                        default:
                                            std::cout << "That's not an option." << std::endl;
                                    }
                                    break;
                                    
                                }
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                std::cout << "Press 1 to contract a new ZooKeeper for $" << COST_ZOOKEEPER << " a day." << std::endl;
                                std::cin >> userSelect;
                                switch (userSelect)
                                {
                                case 1:
                                    std::cout << "How many would you like to contract?" << std::endl;
                                    int amount_to_buy;
                                    std::cin >> amount_to_buy;
                                    for (int i=0;i<amount_to_buy;i++){
                                        zookeepers.push_back(new ZooKeeper(names[rand() % 1000], COST_ZOOKEEPER));
                                    }
                                    break;
                                
                                default:
                                    break;
                                }
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