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
    void go();
    int pcd = 0;
    bool stop = false;
    mutex mt;
};

void Order::go(Cell *cell, int pcd) {
    this->mt.lock();
    this->cell = cell;
    this->isComplite = false;
    this->profession = "";
    this->pcd = pcd;
    stop = false;
    this->mt.unlock();
}

void Order::go(string profession, int pcd) {
    this->mt.lock();
    this->profession = profession;
    this->isComplite = false;
    this->cell = nullptr; //=> ???
    this->pcd = pcd;
    stop = false;
    this->mt.unlock();
}

void Order::go() {
   this->mt.lock();
   this->stop = true;
   this->isComplite = false;
   this->mt.unlock();
}