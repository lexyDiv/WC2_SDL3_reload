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
    Order() {};
    ~Order() {};
    Cell *cell = nullptr;
    Unit *unit = nullptr;
    int unitPersNum = 0;
    string profession = "";
    bool isComplite = true;
    void go(Cell *cell);
    void go(string profession);

    mutex mt;
};

void Order::go(Cell *cell) {
    this->mt.lock();
    this->cell = cell;
    this->isComplite = false;
    this->mt.unlock();
}

void Order::go(string profession) {
    this->mt.lock();
    this->profession = profession;
    this->isComplite = false;
    this->mt.unlock();
}