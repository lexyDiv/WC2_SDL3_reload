#include "Cell.h"
//=>Imager

// class PreOrder
// {
// public:
//     PreOrder() {};
//     ~PreOrder() {};
//     Cell *cell = nullptr;
//     Unit *unit = nullptr;
//     int unitPersNum = 0;
//     string profession = "";
//    // bool isComplite = true;
// };

class Order
{
public:
    Order(Unit *unit);
    ~Order() {};
    Cell *cell = nullptr;
    Unit *unit = nullptr;
    Unit *myUnit = nullptr;
    int unitPersNum = 0;
    string profession = "";
    bool isComplite = true;
    void go(Cell *cell, int pcd = 0, bool specialFreeG0 = false);
    void go(string profession, int pcd = 0, bool specialFreeG0 = false);
    void go();
    int pcd = 0;
    bool stop = false;
    bool specialFreeG0 = false;
    mutex mt;
};

