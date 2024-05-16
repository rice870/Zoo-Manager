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
<<<<<<< HEAD
        Enclosure(int posX, int posY, int enclosure_capacity);
        Enclosure();
        void add_animal();
        void get_visited();
=======
        Enclosure();
        Enclosure(Animal* animals);

    
>>>>>>> fa8296d2b0924b3b31e4c19957d17f1f6a0eff43
};