#include "activeProg.cpp"
//=>out

bool Peon_peasant::isActiveCheck()
{

    if (
        this->cell && this->hp &&
        (this->potentialWay.length ||
         !this->isPotentialWayComplite ||
         (!this->orderOnWay.isComplite) ||
         !this->isGetMyCell ||
         this->inFight ||
         this->outHoldTimer ||
         this->way.length
        ))
    {
        return true;
    }

    return false;
};