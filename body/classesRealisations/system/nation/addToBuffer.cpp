#include "in.h"
//=>addToAllTracesBuffers

void Nation::addToBuffer(Unit *u)
{
   // mutex mt;
   // mt.lock();
    if (u->name == "peon")
    {
        this->peonsBuffer.push(u);
    }
    else if (u->canTakeGold)
    {
        this->townHallsBuffer.push(u);
    }
    u->inBufer = true;
   // mt.unlock();
}