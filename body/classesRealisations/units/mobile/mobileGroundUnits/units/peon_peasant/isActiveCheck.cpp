#include "activeProg.cpp"
//=>updateCurrentTarget

bool Peon_peasant::isActiveCheck()
{
                //                  if (this->persNum == 1) {
                //     console.log("orderOnWayIsCompl = " + to_string(this->way.length));
                // }

    if (
        this->cell && this->hp &&
        (//this->potentialWay.length ||
         !this->isPotentialWayComplite || // 0 <=
         !this->orderOnWay.isComplite ||  // 0
         !this->isGetMyCell ||            // 0
         this->inFight ||                 // 0
         this->outHoldTimer ||            // 0
         this->way.length                 // 0
        // || this->rwd.targetCell
        // || this->targetData.clicckedCell
         //||
        // this->profession != ""
        ))
    {
                //                          if (this->persNum == 1) {
                //     console.log("orderOnWayIsCompl = " + to_string(!this->isPotentialWayComplite));
                // }
        this->isActive = true;
        return true;
    }

    this->isActive = false;
    return false;
};