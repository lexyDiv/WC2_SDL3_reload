#include "Cell.h"
//=>Imager


class PreOrder
{
public:
    PreOrder() {};
    ~PreOrder() {};
    Cell *cell = nullptr;
    Unit *unit = nullptr;
    int unitPersNum = 0;
    string profession = "";
   // bool isComplite = true;
};

class Order
{
public:
    Order() {};
    ~Order() {};
    Cell *cell = nullptr;
    Unit *unit = nullptr;
    int unitPersNum = 0;
    string profession = "";
    bool isComplite = true;
};