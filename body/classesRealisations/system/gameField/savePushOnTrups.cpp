#include "updateClasters.cpp"
//=>activeShahtsControl

void GameField::savePushOnTrups(Unit *unit) {
   // pushOnTrups_mt.lock();
    unit->hp = 0;
    this->trupsOnDelete.push(unit);
   // pushOnTrups_mt.unlock();
}