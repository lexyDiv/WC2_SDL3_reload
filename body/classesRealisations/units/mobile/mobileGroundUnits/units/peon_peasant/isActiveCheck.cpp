#include "activeProg.cpp"
//=>updateCurrentTarget

bool Peon_peasant::isActiveCheck()
{

    if (
        this->cell && this->hp &&
        (this->potentialWay.length ||
         !this->isPotentialWayComplite ||
         !this->orderOnWay.isComplite ||
         !this->isGetMyCell ||
         this->inFight ||
         this->outHoldTimer || // => in activeProg
         this->way.length 
         || this->rwd.targetCell//||
        // this->profession != ""
        ))
    {
        this->isActive = true;
        return true;
    }
    this->isActive = false;
    return false;
};