#include <vector>
#include "Animal.h"

using namespace std;


class Enclosure {
    private:
        vector<Animal*> animals;
        int enclosure_capacity;
        int posX;
        int posY;
    public:
        Enclosure();
        Enclosure(Animal* animals);

    
};