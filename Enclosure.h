#include <vector>
#include "Animal.h"

using namespace std;


class Enclosure {
    private:
        vector<Animal*> Animals;
        int enclosure_capacity;
        int posX;
        int posY;
    public:
        Enclosure(int posX, int posY, int enclosure_capacity);
        Enclosure();
        void add_animal();
        void get_visited();
};