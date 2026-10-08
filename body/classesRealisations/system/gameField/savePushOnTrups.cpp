#include "updateClasters.cpp"
//=>out

void GameField::savePushOnTrups(Unit *unit) {
    mutex mt;
    mt.lock();
    unit->hp = 0;
    this->trupsOnDelete.push(unit);
    mt.unlock();
}