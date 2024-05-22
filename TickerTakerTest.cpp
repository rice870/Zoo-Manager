#include "Visitor.h"
#include "Zoo.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "ticketTaker.h"
#include <fstream>
using namespace std;

// Create visitors
int main() {
    vector<TicketTaker*> ticketTakers;
    ticketTakers.push_back(new TicketTaker("Bob", 100));

    ifstream inputFile("Names.txt");
    vector<string> names;
    std::string line;
    while (getline(inputFile, line)) {
        names.push_back(line);
    }

    Zoo z = Zoo("My zoo", "wee", 1000, 1000, 1000);
    z.addEnclosure(new Enclosure("Enclosure 1", 5, 5, "Panda"));
    for (int i=0;i<5;i++){
        z.enclosures[0]->addAnimal(new Panda(500, "jimmy"));
    }

    int visitorAmount = 10;
    vector<Visitor*> visitors;

    // Visitors enter the gate
    for (int i=0;i<visitorAmount;i++){
        visitors.push_back(new Visitor(names[rand() % 1000], rand() % 75));
        cout << visitors[i]->getName() << ", " << visitors[i]->getAge() << " years old, is at the gates of our zoo!" << endl;
        //z.receiveMoney(visitors[i]->calculateTicketPrice());
    }

    vector<Visitor*> visitorsToEnter = visitors;

    // Ticket taker takes tickets
    for (int i=0;i<ticketTakers.size();i++){
        for (int j=0;j<4;j++){
            if (visitorsToEnter.size() != 0){
                z.receiveMoney(visitors[0]->calculateTicketPrice());
                cout << visitorsToEnter[0]->getName() << " was admitted." << endl;
                visitorsToEnter.erase(visitorsToEnter.begin());
            }
        }
    }

    vector<Visitor*> visitorsAdmitted;

    sort(visitors.begin(), visitors.end());
    sort(visitorsToEnter.begin(), visitorsToEnter.end());

    std::set_difference(visitors.begin(), visitors.end(), visitorsToEnter.begin(), visitorsToEnter.end(), back_inserter(visitorsAdmitted));
    visitors = visitorsAdmitted;

    for (int i=0;i<visitors.size();i++){
        cout << visitors[i]->getName() << " is in the zoo." << endl;
    }
    return 0;
}