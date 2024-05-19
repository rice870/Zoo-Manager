#ifndef DRINKSHOP_H
#define DRINKSHOP_H

#include "Facility.h"
#include <vector>
#include <string>

class DrinkShop : public Facility {
private:
    std::vector<std::string> menu; // List of drinks available in the shop
    double totalSales;             // Total sales of the shop

public:
    // Constructor to initialize a DrinkShop object
    DrinkShop(std::string name);

    // Default constructor
    DrinkShop();

    // Method to add a drink to the menu
    void addDrink(std::string drink);

    // Method to make a sale
    void makeSale(double amount);

    // Getter method for total sales
    double getTotalSales() const;

    // Getter method for menu
    std::vector<std::string> getMenu() const;
};

#endif // DRINKSHOP_H

