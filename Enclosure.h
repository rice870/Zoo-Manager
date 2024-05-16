#include <vector>
#include "Animal.h"

using namespace std;


class Enclosure {
    private:
        vector<Animal*> Animals;
        int enclosure_capacity;
        int posX;
        int posY;
};