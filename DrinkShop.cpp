#include "DrinkShop.h"

// Constructor to initialize a DrinkShop object
DrinkShop::DrinkShop(std::string name) : Facility(name), totalSales(0.0) {}

// Default constructor
DrinkShop::DrinkShop() : Facility(), totalSales(0.0) {}

// Method to add a drink to the menu
void DrinkShop::addDrink(std::string drink) {
    menu.push_back(drink);
    // Logic to animate adding a drink to the menu (if needed)
}

// Method to make a sale
void DrinkShop::makeSale(double amount) {
    totalSales += amount;
    // Logic to animate making a sale (if needed)
}

// Getter method for total sales
double DrinkShop::getTotalSales() const {
    return totalSales;
}

// Getter method for menu
std::vector<std::string> DrinkShop::getMenu() const {
    return menu;
}

