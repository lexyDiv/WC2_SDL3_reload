#include "in.h"
//=>out.h

Order::Order(Unit *unit) {
  this->myUnit = unit;
}

void Order::go(Cell *cell, int pcd, bool specialFreeG0)
{
    this->mt.lock();
    if (!myUnit->cell || myUnit->inSave || myUnit->hp <= 0)
    {
        this->mt.unlock();
        return;
    }
    this->cell = cell;
    this->isComplite = false;
    this->profession = "";
    this->pcd = pcd;
    stop = false;
    this->specialFreeG0 = specialFreeG0;
    this->mt.unlock();
}

void Order::go(string profession, int pcd, bool specialFreeG0)
{
    this->mt.lock();

    if (!myUnit->cell || myUnit->inSave || myUnit->hp <= 0)
    {
        this->mt.unlock();
        return;
    }
    this->profession = profession;
    this->isComplite = false;
    this->cell = nullptr; //=> ???
    this->pcd = pcd;
    stop = false;
    this->specialFreeG0 = specialFreeG0;
    this->mt.unlock();
}

void Order::go()
{
    this->mt.lock();
    if (!myUnit->cell || myUnit->inSave || myUnit->hp <= 0)
    {
        this->mt.unlock();
        return;
    }
    this->stop = true;
    this->isComplite = false;
    this->mt.unlock();
}