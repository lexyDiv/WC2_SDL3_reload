#include "activeProg.cpp"
//=>getPeonExtreemOutCell

bool TownHall::isActiveCheck()
{
    // console.log("this->clients.length CHECK = ", this->clients.length);
    // console.log("this->potentialClients.length = ", this->potentialClients.length);
    // console.log("this->outClients.length = ", this->outClients.length);
    // console.log("================================================");
    if (this->clients.length ||
        this->potentialClients.length ||
        this->outClients.length ||
        !this->isComplite ||
        this->hp != this->hpMax ||
        this->createTimer ||
        this->updateTimer
    )
    {
        //console.log("active");
        return true;
    }
   // console.log("NO ACTIVE");
    return false;
}