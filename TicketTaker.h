#ifndef TICKETTAKER_H
#define TICKETTAKER_H
#include "Staff.h"


class TicketTaker : public Staff {
    public:
        TicketTaker();
        TicketTaker(std::string name, double salary);
        void get_status() override;
};

#endif