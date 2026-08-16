#include "Cell.h"
//=>Imager

class Order
{
public:
    Order() {};
    ~Order() {};
    Cell *cell = nullptr;
    Unit *unit = nullptr;
    bool isComplite = true;
    int deleteTimer = 0;
    bool isRealClick = false;
};