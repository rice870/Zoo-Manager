#include "Person.h"
#include "Animal.h"
#include "Enclosure.h"
#include <vector>
using namespace std;

class Visitor : public Person {
    private:
        vector<Enclosure*> visiting;
    public:
        void visit(Enclosure * e){
            e->get_visited();
        }
};