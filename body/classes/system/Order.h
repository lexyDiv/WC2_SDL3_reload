#include "Cell.h"
//=>Imager

class Order
{
public:
    Order() {};
    ~Order() {};
    Cell *cell = nullptr;
    Unit *unit = nullptr;
    string profession = "";
    bool isComplite = true;
};