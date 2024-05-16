#include "Staff.h"

Staff::Staff(double posX, double posY, double speed, string role):Person(posX, posY, speed, role){}

Staff::Staff():Staff(0, 0, 0, ""){}