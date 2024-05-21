#include <iostream>
#include "Zoo.h"
#include "Visitor.h"

using namespace std;

class ZooTest{
    private:
        string names[10] = {"Wang Wang", "Funi", "Bao Bao", "Mei Mei", "Tofu", "Mochi", "Bamboo", "Ling Ling", "Yuki", "Oreo"};
        void TestAddingAnimalsAndEnclosures(){

            //cout << "1"<< endl;

            Zoo z = Zoo("MyZoo", "123 Anthal Road", 500, 0, 50);
            z.addEnclosure(new Enclosure("Enclosure 1", 1, 10, "Panda"));
            for (int i=0;i<10;i++){

                //cout << "2" << endl;

                z.addAnimal(z.get_enclosures()[0],new Panda(0, names[i]));

                //cout << "3" << endl;

                z.get_animals()[i]->setID(z.generateUniqueID());

                //cout << "4" << endl;
            }
            for (int i=0;i<10;i++){
                cout << i << " | Name: " << z.get_animals()[i]->getName() << " | ID: " << z.get_animals()[i]->getID() << endl;
            }
            for (int i=0; i<10; i++){
                z.releaseAnimal(z.get_animals()[0]->getID());
            }
            cout << z.get_animals().size() << endl;
        }

        void TestVisitors(){
            Zoo z = Zoo("MyZoo", "123 Anthal Road", 500, 0, 50);
            cout << "Z starting cash: " << z.get_money() << endl;
            z.addEnclosure(new Enclosure("Enclosure 1", 1, 10, "Panda"));

            for (int i=0;i<10;i++){
                z.addAnimal(z.get_enclosures()[0],new Panda(0, names[i]));
                z.get_animals()[i]->setID(z.generateUniqueID());
            }

            z.get_animals()[0]->getVisited();
            Visitor v = Visitor();
            v.chooseVisitSpots(&z);
            v.visitFacility(&z);
            cout << "Now Cash = " << z.get_money() << endl;
            v.chooseVisitSpots(&z);
            v.visitFacility(&z);
            cout << "Now Cash = " << z.get_money() << endl;
            v.chooseVisitSpots(&z);
            v.visitFacility(&z);
            cout << "Now Cash = " << z.get_money() << endl;
            v.chooseVisitSpots(&z);
            v.visitFacility(&z);
            cout << "Now Cash = " << z.get_money() << endl;
        }

    public:
        void runAll(){
            //TestAddingAnimalsAndEnclosures();
            TestVisitors();
        }
};