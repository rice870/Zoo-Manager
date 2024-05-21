#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Zoo.h"
#include "Animal.h"
//#include "Drinkshop.h"
#include "Elephant.h"
#include "Enclosure.h"
#include "Facility.h"
#include "Kangaroo.h"
#include "Kiwi.h"
#include "Panda.h"
//#include "Person.h"
#include "Staff.h"
#include "Tortoise.h"
#include "Visitor.h"
#include "Zookeeper.h"

using namespace std;


int main() {
    ifstream inputFile("Names.txt");
    vector<string> names;
    std::string line;
    while (getline(inputFile, line)) {
        names.push_back(line);
    }

    int day=0;
    const int COST_PANDA = 200;
    const int COST_PANDA_ENCLOSURE = 2500;
    const int COST_BAMBOO = 5;
    const int COST_KIWI = 85;
    const int COST_KIWI_ENCLOSURE = 1250;
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
    Zoo z(userName, userLocation, 300, 0, 10);
    std::cout << "Your zoo " << z.get_name() << " has been created in " << z.get_location() << "." << std::endl;
    std::cout << "You have a starting budget of " << z.get_money() << ", spend it wisely to grow your zoo." << std::endl;
    std::cout << "You have been gifted a panda enclosure to begin. Enter the name of your starting enclosure: ";
    std::cin >> startingEnclosureName;
    z.addEnclosure(new Enclosure(startingEnclosureName, z.generateUniqueID(), 5, "Panda"));
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
            std::cout << "Press 3 to view zoo" << std::endl;
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
                                    animalsToFeed.erase(find(animalsToFeed.begin(),animalsToFeed.end(),animalToFeed));
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
                                        int amount_to_buy;
                                        case 1:
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
                                            continue;
                                    }
                                    break;
                                    
                                }
                                break;
                            case 2:
                                while (true){
                                    srand(time(nullptr));

                                    std::cout << "Animals Menu:" << std::endl;
                                    std::cout << "Press 1 to buy a panda | Price: $" << COST_PANDA << std::endl;
                                    std::cout << "Press 2 to buy a kiwi | Price: $" << COST_KIWI << std::endl;
                                    std::cout << "Press 3 to buy an elephant | Price: $" << COST_ELEPHANT << std::endl;
                                    std::cout << "Press 4 to buy a tortoise | Price: $" << COST_TORTOISE  << std::endl;
                                    std::cout << "Press 5 to buy a kangaroo | Price: $" << COST_KANGAROO  << std::endl;
                                    std::cout << "Press 6 to exit the shop" << std::endl;
                                    std::cin >> userSelect;
                                    switch (userSelect)
                                    {
                                    case 1:
                                        if (z.get_money() >= COST_PANDA){
                                            std::string enclosure_choice;
                                            std::cout << "Which enclosure do you want to put the panda in?" << std::endl;
                                            cin >> enclosure_choice;
                                            bool real_choice = false;
                                            for (int i=0;i<z.enclosures.size();i++){
                                                if (enclosure_choice==z.enclosures[i]->get_name() && z.enclosures[i]->get_species_type() == "Panda"){
                                                    real_choice = true;
                                                    if (z.enclosures[i]->get_animals().size() < z.enclosures[i]->get_enclosure_capacity()){
                                                        std::string animal_name;
                                                        std::cout << "What would you like to name your panda?" << std::endl;
                                                        std::cin >> animal_name;
                                                        z.enclosures[i]->addAnimal(new Panda(70 + rand() % 40, animal_name));
                                                        z.pay(COST_PANDA);
                                                    } else {
                                                        std::cout << "That enclosure's full!" << std::endl;
                                                    }
                                                }
                                            }
                                            if (!real_choice){
                                                std::cout << "You've entered an invalid enclosure. Make sure you've entered the correct name and the name you've entered is for a panda enclosure" << std::endl;
                                            }
                                        } else {
                                            std::cout << "You can't afford one." << std::endl;
                                            continue;
                                        }
                                        break;

                                    case 2:
                                        if (z.get_money() >= COST_KIWI){
                                            std::string enclosure_choice;
                                            std::cout << "Which enclosure do you want to put the kiwi in?" << std::endl;
                                            cin >> enclosure_choice;
                                            bool real_choice = false;
                                            for (int i=0;i<z.enclosures.size();i++){
                                                if (enclosure_choice==z.enclosures[i]->get_name() && z.enclosures[i]->get_species_type() == "Kiwi"){
                                                    real_choice = true;
                                                    if (z.enclosures[i]->get_animals().size() < z.enclosures[i]->get_enclosure_capacity()){
                                                        std::string animal_name;
                                                        std::cout << "What would you like to name your kiwi?" << std::endl;
                                                        std::cin >> animal_name;
                                                        z.enclosures[i]->addAnimal(new Kiwi(2 + rand() % 2, animal_name));
                                                        z.pay(COST_KIWI);
                                                    } else {
                                                        std::cout << "That enclosure's full!" << std::endl;
                                                    }
                                                }
                                            }
                                            if (!real_choice){
                                                std::cout << "You've entered an invalid enclosure. Make sure you've entered the correct name and the name you've entered is for a kiwi enclosure" << std::endl;
                                            }
                                        } else {
                                            std::cout << "You can't afford one." << std::endl;
                                            continue;
                                        }
                                        break;

                                    case 3:
                                        if (z.get_money() >= COST_ELEPHANT){
                                            std::string enclosure_choice;
                                            std::cout << "Which enclosure do you want to put the elephant in?" << std::endl;
                                            cin >> enclosure_choice;
                                            bool real_choice = false;
                                            for (int i=0;i<z.enclosures.size();i++){
                                                if (enclosure_choice==z.enclosures[i]->get_name() && z.enclosures[i]->get_species_type() == "Elephant"){
                                                    real_choice = true;
                                                    if (z.enclosures[i]->get_animals().size() < z.enclosures[i]->get_enclosure_capacity()){
                                                        std::string animal_name;
                                                        std::cout << "What would you like to name your elephant?" << std::endl;
                                                        std::cin >> animal_name;
                                                        z.enclosures[i]->addAnimal(new Elephant(3000 + rand() % 2000, animal_name));
                                                        z.pay(COST_ELEPHANT);
                                                    } else {
                                                        std::cout << "That enclosure's full!" << std::endl;
                                                    }
                                                }
                                            }
                                            if (!real_choice){
                                                std::cout << "You've entered an invalid enclosure. Make sure you've entered the correct name and the name you've entered is for a elephant enclosure" << std::endl;
                                            }
                                        } else {
                                            std::cout << "You can't afford one." << std::endl;
                                            continue;
                                        }
                                        break;

                                    case 4:
                                        if (z.get_money() >= COST_TORTOISE){
                                            std::string enclosure_choice;
                                            std::cout << "Which enclosure do you want to put the tortoise in?" << std::endl;
                                            cin >> enclosure_choice;
                                            bool real_choice = false;
                                            for (int i=0;i<z.enclosures.size();i++){
                                                if (enclosure_choice==z.enclosures[i]->get_name() && z.enclosures[i]->get_species_type() == "Tortoise"){
                                                    real_choice = true;
                                                    if (z.enclosures[i]->get_animals().size() < z.enclosures[i]->get_enclosure_capacity()){
                                                        std::string animal_name;
                                                        std::cout << "What would you like to name your tortoise?" << std::endl;
                                                        std::cin >> animal_name;
                                                        z.enclosures[i]->addAnimal(new Tortoise(150 + rand() % 75, animal_name));
                                                        z.pay(COST_TORTOISE);
                                                    } else {
                                                        std::cout << "That enclosure's full!" << std::endl;
                                                    }
                                                }
                                            }
                                            if (!real_choice){
                                                std::cout << "You've entered an invalid enclosure. Make sure you've entered the correct name and the name you've entered is for a tortoise enclosure" << std::endl;
                                            }
                                        } else {
                                            std::cout << "You can't afford one." << std::endl;
                                            continue;
                                        }
                                        break;

                                    case 5:
                                        if (z.get_money() >= COST_KANGAROO){
                                            std::string enclosure_choice;
                                            std::cout << "Which enclosure do you want to put the kangaroo in?" << std::endl;
                                            cin >> enclosure_choice;
                                            bool real_choice = false;
                                            for (int i=0;i<z.enclosures.size();i++){
                                                if (enclosure_choice==z.enclosures[i]->get_name() && z.enclosures[i]->get_species_type() == "Kangaroo"){
                                                    real_choice = true;
                                                    if (z.enclosures[i]->get_animals().size() < z.enclosures[i]->get_enclosure_capacity()){
                                                        std::string animal_name;
                                                        std::cout << "What would you like to name your kangaroo?" << std::endl;
                                                        std::cin >> animal_name;
                                                        z.enclosures[i]->addAnimal(new Kangaroo(70 + rand() % 40, animal_name));
                                                        z.pay(COST_KANGAROO);
                                                    } else {
                                                        std::cout << "That enclosure's full!" << std::endl;
                                                    }
                                                }
                                            }
                                            if (!real_choice){
                                                std::cout << "You've entered an invalid enclosure. Make sure you've entered the correct name and the name you've entered is for a kangaroo enclosure" << std::endl;
                                            }
                                        } else {
                                            std::cout << "You can't afford one." << std::endl;
                                            continue;
                                        }
                                        break;
                                    case 6:
                                        break;
                                    
                                    default:
                                        break;
                                    }
                                }
                                break;
                            case 3:
                                while(true) {
                                    std::cout << "Enclosures Menu:" << std::endl;
                                    std::cout << "Buy enclosures for your animals (each enclosure can house 5 animals of the same type)" << std::endl;
                                    std::cout << "Press 1 to buy a panda enclosure | Price: $" << COST_PANDA_ENCLOSURE << std::endl;
                                    std::cout << "Press 2 to buy a kiwi enclosure | Price: $" << COST_KIWI_ENCLOSURE << std::endl;
                                    std::cout << "Press 3 to buy an elephant enclosure | Price: $" << COST_ELEPHANT_ENCLOSURE << std::endl;
                                    std::cout << "Press 4 to buy a tortoise enclosure | Price: $" << COST_TORTOISE_ENCLOSURE  << std::endl;
                                    std::cout << "Press 5 to buy a kangaroo enclosure | Price: $" << COST_KANGAROO_ENCLOSURE  << std::endl;
                                    std::cout << "Press 6 to exit the shop" << std::endl;
                                    std::cin >> userSelect;
                                    switch(userSelect) {
                                        case 1:
                                            if (COST_PANDA_ENCLOSURE <= z.get_money()){
                                                std::string enclosureName;
                                                std::cout << "Please name this enclosure: ";
                                                std::cin >> enclosureName;
                                                z.pay(COST_PANDA_ENCLOSURE);
                                                z.addEnclosure(new Enclosure(enclosureName, z.generateUniqueID(), 5, "Panda"));
                                            } else {
                                                cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 2:
                                            if (COST_KIWI_ENCLOSURE <= z.get_money()){
                                                std::string enclosureName;
                                                std::cout << "Please name this enclosure: ";
                                                std::cin >> enclosureName;
                                                z.pay(COST_KIWI_ENCLOSURE);
                                                z.addEnclosure(new Enclosure(enclosureName, z.generateUniqueID(), 5, "Kiwi"));
                                            } else {
                                                cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 3:
                                            if (COST_ELEPHANT_ENCLOSURE <= z.get_money()){
                                                std::string enclosureName;
                                                std::cout << "Please name this enclosure: ";
                                                std::cin >> enclosureName;
                                                z.pay(COST_ELEPHANT_ENCLOSURE);
                                                z.addEnclosure(new Enclosure(enclosureName, z.generateUniqueID(), 5, "Elephant"));
                                            } else {
                                                cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 4:
                                            if (COST_TORTOISE_ENCLOSURE <= z.get_money()){
                                                std::string enclosureName;
                                                std::cout << "Please name this enclosure: ";
                                                std::cin >> enclosureName;
                                                z.pay(COST_TORTOISE_ENCLOSURE);
                                                z.addEnclosure(new Enclosure(enclosureName, z.generateUniqueID(), 5, "Kiwi"));
                                            } else {
                                                cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 5:
                                            if (COST_KANGAROO_ENCLOSURE <= z.get_money()){
                                                std::string enclosureName;
                                                std::cout << "Please name this enclosure: ";
                                                std::cin >> enclosureName;
                                                z.pay(COST_KANGAROO_ENCLOSURE);
                                                z.addEnclosure(new Enclosure(enclosureName, z.generateUniqueID(), 5, "Kiwi"));
                                            } else {
                                                cout << "You can't afford that much.";
                                                continue;
                                            }
                                            break;
                                        case 6:
                                            break;

                                        default:
                                            cout << "That's not an option." << endl;
                                            continue;
                                    }
                                    break; 
                                    }
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
                                    z.pay(COST_ZOOKEEPER);
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
                    z.get_status();
                    for (int i=0;i<zookeepers.size();i++){
                        zookeepers[i]->get_status();
                    }
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