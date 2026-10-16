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
   // console.log("go no prof");
    this->cell = cell;
    this->isComplite = false;
    this->profession = "";
    this->pcd = pcd;
    stop = false;
    this->specialFreeG0 = specialFreeG0;
    isUpdate = false;
    myUnit->isActive = true;
    this->mt.unlock();
}

void Order::go(string profession, int pcd, bool specialFreeG0)
{
    this->mt.lock();

    if (!myUnit->cell || myUnit->inSave || myUnit->hp <= 0)
    {
        isUpdate = false;
        this->mt.unlock();
        return;
    }
   // console.log("go prof");
    this->profession = profession;
    this->isComplite = false;
    this->cell = nullptr; //=> ???
    this->pcd = pcd;
    stop = false;
    this->specialFreeG0 = specialFreeG0;
    isUpdate = false;
    myUnit->isActive = true;
    this->mt.unlock();
}

void Order::go()
{
    this->mt.lock();
    if (!myUnit->cell || myUnit->inSave || myUnit->hp <= 0)
    {
        isUpdate = false;
        this->mt.unlock();
        return;
    }
    //console.log("go stop");
    isUpdate = false;
    this->stop = true;
    this->isComplite = false;
    myUnit->isActive = true;
    this->mt.unlock();
}