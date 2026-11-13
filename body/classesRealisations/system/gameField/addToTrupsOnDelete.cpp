#include "activeShahtsControl.cpp"
//=>out

void GameField::addToTrupsOnDelete(Unit *unit)
{
    damage_mt.lock();
    this->trupsOnDelete.push(unit);
    damage_mt.unlock();
}

// void GameField::addToTraces(Trace *t)
// {
//     // mutex mt;

//     // mt.lock();
//     //   this->traces.push(t);
//     // mt.unlock();
// }


