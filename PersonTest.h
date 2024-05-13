#include "Person.h"

class PersonTest{
    private:
        void getToSpot(){
            {
                Person p;
                cout << "\ngetToSpot (10,10):" << endl;
                cout << "startX: " << p.get_posX() << "; startY: " << p.get_posY() << endl;
                for (int i=0;i<10;i++){
                    p.Go(10,10);
                    cout << "Iteration " << i << " of Go(10,10); posX: " << p.get_posX() << "; posY: " << p.get_posY() << endl;
                }
            }
            {
                Person p;
                cout << "\ngetToSpot (-10,-10):" << endl;
                cout << "startX: " << p.get_posX() << "; startY: " << p.get_posY() << endl;
                for (int i=0;i<10;i++){
                    p.Go(-10,-10);
                    cout << "Iteration " << i << " of Go(-10,-10); posX: " << p.get_posX() << "; posY: " << p.get_posY() << endl;
                }
            }
            {
                Person p;
                cout << "\ngetToSpot (10,-10):" << endl;
                cout << "startX: " << p.get_posX() << "; startY: " << p.get_posY() << endl;
                for (int i=0;i<10;i++){
                    p.Go(10,-10);
                    cout << "Iteration " << i << " of Go(10,-10); posX: " << p.get_posX() << "; posY: " << p.get_posY() << endl;
                }
            }
            {
                Person p;
                cout << "\ngetToSpot (-10,10):" << endl;
                cout << "startX: " << p.get_posX() << "; startY: " << p.get_posY() << endl;
                for (int i=0;i<10;i++){
                    p.Go(-10,10);
                    cout << "Iteration " << i << " of Go(-10,10); posX: " << p.get_posX() << "; posY: " << p.get_posY() << endl;
                }
            }
        }

        void boundaryCases(){
            {
            Person p;
            cout << "\nGo(0,10):" << endl;
            cout << "startX: " << p.get_posX() << "; startY: " << p.get_posY() << endl;
            cout << "call Go(0,10)" << endl;
            p.Go(0,10);
            cout << "endX: " << p.get_posX() << "; endY: " << p.get_posY() << endl;
            }

            {
            Person p;
            cout << "\nGo(10,0):" << endl;
            cout << "startX: " << p.get_posX() << "; startY: " << p.get_posY() << endl;
            cout << "call Go(10,0)" << endl;
            p.Go(10,0);
            cout << "endX: " << p.get_posX() << "; endY: " << p.get_posY() << endl;
            }
        }
    public:
        void runTests(){
            getToSpot();
            boundaryCases();
        }
};