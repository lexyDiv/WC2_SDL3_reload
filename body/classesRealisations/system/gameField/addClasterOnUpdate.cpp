#include "createClasters.cpp"
//=>updateClastyers

void GameField::addClasterOnUpdate(Claster *claster) {
    mutex mt;
    mt.lock();

    if (!claster->addOnUpdate) {
        claster->addOnUpdate = true;
        this->clastersOnUpdate.push(claster);
    }

    mt.unlock();
}