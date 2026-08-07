#include "activeProg.cpp"
//=>getPeonExtreemOutCell

bool TownHall::isActiveCheck()
{
    if (this->clients.length ||
        this->potentialClients.length ||
        this->outClients.length ||
        !this->isComplite ||
        this->hp != this->hpMax ||
        this->createTimer ||
        this->updateTimer)
    {
        return true;
    }
    return false;
}