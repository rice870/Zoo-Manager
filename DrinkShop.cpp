
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>


#include "DrinkShop.h"
#include "Facility.h"

using namespace std;

DrinkShop::DrinkShop() {
    name = "";
    totalSales = 0.0;
}

DrinkShop::DrinkShop(string name) {
    this->name = name;
    totalSales = 0.0;

}


// Method to add a drink to the menu
void DrinkShop::addDrink(string drink) {
    menu.push_back(drink);
    // Logic to animate adding a drink to the menu (if needed)
}


int DrinkShop::getVisited() {
    cout << "Your drink shop was visited!" << endl;
    srand(time(NULL));
    int selectedDrink;
    selectedDrink = rand() % menu.size();
    totalSales += prices[selectedDrink];

}


/*Method to make a sale
void DrinkShop::makeSale(double amount) {
    totalSales += amount;
    // Logic to animate making a sale (if needed)
}*/

// Getter method for total sales
double DrinkShop::getTotalSales() const {
    return totalSales;
}

// Getter method for menu
vector<string> DrinkShop::getMenu() const {
    return menu;
}

// Getter method for prices
vector<string> DrinkShop::getPrices() const {
    return prices;
}
