#include "Person.h"
#include <iostream>
using namespace std;

class PersonTest{
    private:
        void getToSpot(){
            {
                Person p;
                cout << "\ngetToSpot (10,10):" << endl;
                cout << "startX: " << p.getPosX() << "; startY: " << p.getPosY() << endl;
                for (int i=0;i<10;i++){
                    p.Go(10,10);
                    cout << "Iteration " << i << " of Go(10,10); posX: " << p.getPosX() << "; posY: " << p.getPosY() << endl;
                }
            }
            {
                Person p;
                cout << "\ngetToSpot (-10,-10):" << endl;
                cout << "startX: " << p.getPosX() << "; startY: " << p.getPosY() << endl;
                for (int i=0;i<10;i++){
                    p.Go(-10,-10);
                    cout << "Iteration " << i << " of Go(-10,-10); posX: " << p.getPosX() << "; posY: " << p.getPosY() << endl;
                }
            }
            {
                Person p;
                cout << "\ngetToSpot (10,-10):" << endl;
                cout << "startX: " << p.getPosX() << "; startY: " << p.getPosY() << endl;
                for (int i=0;i<10;i++){
                    p.Go(10,-10);
                    cout << "Iteration " << i << " of Go(10,-10); posX: " << p.getPosX() << "; posY: " << p.getPosY() << endl;
                }
            }
            {
                Person p;
                cout << "\ngetToSpot (-10,10):" << endl;
                cout << "startX: " << p.getPosX() << "; startY: " << p.getPosY() << endl;
                for (int i=0;i<10;i++){
                    p.Go(-10,10);
                    cout << "Iteration " << i << " of Go(-10,10); posX: " << p.getPosX() << "; posY: " << p.getPosY() << endl;
                }
            }
        }

        void boundaryCases(){
            {
            Person p;
            cout << "\nGo(0,10):" << endl;
            cout << "startX: " << p.getPosX() << "; startY: " << p.getPosY() << endl;
            cout << "call Go(0,10)" << endl;
            p.Go(0,10);
            cout << "endX: " << p.getPosX() << "; endY: " << p.getPosY() << endl;
            }

            {
            Person p;
            cout << "\nGo(10,0):" << endl;
            cout << "startX: " << p.getPosX() << "; startY: " << p.getPosY() << endl;
            cout << "call Go(10,0)" << endl;
            p.Go(10,0);
            cout << "endX: " << p.getPosX() << "; endY: " << p.getPosY() << endl;
            }
        }
    public:
        void runTests(){
            getToSpot();
            boundaryCases();
        }
};