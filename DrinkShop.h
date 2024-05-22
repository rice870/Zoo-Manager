#ifndef DRINKSHOP_H
#define DRINKSHOP_H

#include "Facility.h"
#include <vector>
#include <string>

class DrinkShop : public Facility {
private:
    double totalSales;             // Total sales of the shop

public:
    std::vector<std::string> menu; // List of drinks available in the shop
    std::vector<double> prices; // List of drink prices, note that prices[i] will be related to menu[i] and will be the price for that drink.
    // Constructor to initialize a DrinkShop object
    // Default constructor
    DrinkShop();

    DrinkShop(std::string name);


    int getVisited();

    // Method to make a sale
    //void makeSale(double amount);

    // Getter method for total sales
    double getTotalSales() const;

    // Getter method for menu
    std::vector<std::string> getMenu() const;
    std::vector<double> getPrices() const;
    // Method to add a drink to the menu
    void addDrink(std::string _drink);
    void addPrice(int _drinkPrice);
};

#endif // DRINKSHOP_H

