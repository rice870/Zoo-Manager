
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>


#include "DrinkShop.h"
#include "Facility.h"
#include "Zoo.h"

using namespace std;

DrinkShop::DrinkShop() {
    name = "";
    totalSales = 0;
}

DrinkShop::DrinkShop(string name) {
    this->name = name;
    totalSales = 0;

}


/* Method to add a drink to the menu
void DrinkShop::addDrink(string drink) {
    menu.push_back(drink);
    // Logic to animate adding a drink to the menu (if needed)
}*/


int DrinkShop::getVisited(std::vector<int> prices) {
    cout << "Your drink shop was visited!" << endl;
    srand(time(NULL));
    int selectedDrink = rand() % 5 + 1;
    std::cout << selectedDrink << std::endl;
    //std::vector<int>::iterator it;
    //it = find(prices.begin(), prices.end(), selectedDrink);
    int deductedAmount = prices.at(selectedDrink);
    totalSales += deductedAmount;
    return totalSales;

}


/*Method to make a sale
void DrinkShop::makeSale(double amount) {
    totalSales += amount;
    // Logic to animate making a sale (if needed)
}*/

// Getter method for total sales
int DrinkShop::getTotalSales() const {
    return totalSales;
}

/* Getter method for menu
vector<string> DrinkShop::getMenu() const {
    return menu;
}

// Getter method for prices
vector<int> DrinkShop::getPrices() const {
    return prices;
}*/
