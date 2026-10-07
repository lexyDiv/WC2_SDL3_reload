#include "updateClasters.cpp"
//=>out

void GameField::savePushOnTrups(Unit *unit) {
    mutex mt;
    mt.lock();
    this->trupsOnDelete.push(unit);
    mt.unlock();
}