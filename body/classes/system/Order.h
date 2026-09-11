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
    void go(Cell *cell, int pcd = 0);
    void go(string profession, int pcd = 0);
    int pcd = 0;
    mutex mt;
};

void Order::go(Cell *cell, int pcd) {
    this->mt.lock();
    this->cell = cell;
    this->isComplite = false;
    this->profession = "";
    this->pcd = pcd;
    this->mt.unlock();
}

void Order::go(string profession, int pcd) {
    this->mt.lock();
    this->profession = profession;
    this->isComplite = false;
    this->cell = nullptr; //=> ???
    this->pcd = pcd;
    this->mt.unlock();
}