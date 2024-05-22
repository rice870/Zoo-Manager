#ifndef DRINKSHOP_H
#define DRINKSHOP_H

#include "Facility.h"
#include "Zoo.h"
#include <vector>
#include <string>

class DrinkShop : public Facility {
private:
    double totalSales;             // Total sales of the shop

public:

    // Constructor to initialize a DrinkShop object
    // Default constructor
    DrinkShop();

    DrinkShop(std::string name);


    int getVisited(std::vector<int> prices);

    // Method to make a sale
    //void makeSale(double amount);

    // Getter method for total sales
    int getTotalSales() const;

    /* Getter method for menu
    std::vector<std::string> getMenu() const;
    std::vector<int> getPrices() const;
    // Method to add a drink to the menu
    void addDrink(std::string _drink);
    void addPrice(int _drinkPrice);*/
};

#endif // DRINKSHOP_H

