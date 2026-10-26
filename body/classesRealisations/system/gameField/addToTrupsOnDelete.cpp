#include "activeShahtsControl.cpp"
//=>out

void GameField::addToTrupsOnDelete(Unit *unit)
{
    mutex mt;
    mt.lock();
    this->trupsOnDelete.push(unit);
    mt.unlock();
}


void GameField::addToTraces(Trace *trace)
{
    mutex mt;
    mt.lock();
    this->traces.push(trace);
    mt.unlock();
}

