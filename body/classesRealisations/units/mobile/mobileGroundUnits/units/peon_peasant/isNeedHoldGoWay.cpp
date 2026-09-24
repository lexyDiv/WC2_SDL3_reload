#include "orderOnWayControl.cpp"
//=>out

bool isLoop(Unit *self)
{

    Unit *unit1 = self;
    Unit *unit2 = unit1->nextCell && unit1->nextCell->groundUnit ? unit1->nextCell->groundUnit : nullptr;
    Unit *unit3 = unit2 && unit2->nextCell && unit2->nextCell->groundUnit ? unit2->nextCell->groundUnit : nullptr;
    Unit *unit4 = unit3 && unit3->nextCell && unit3->nextCell->groundUnit ? unit3->nextCell->groundUnit : nullptr;
    Unit *unit5 = unit4 && unit4->nextCell && unit4->nextCell->groundUnit ? unit4->nextCell->groundUnit : nullptr;

    if (unit3 != self && unit4 != self && unit5 != self)
    {
        return false;
    }
    return true;
};

////////////////////////////////////////////////////////////////////////////////

bool Peon_peasant::isNeedHoldGoWay()
{
    Cell *nc = this->nextCell;

    Unit *gu = nc ? nc->groundUnit : nullptr;
    Cell *guNextCell = gu ? gu->nextCell : nullptr;
    Unit *gutdu = gu ? gu->targetData.unit : nullptr;

    int needHoldIndex = !this->iNeedFreeWay ? 10 : 50;

    if ((!this->targetUnit) && this->needHolTimer >= this->wayIndex * needHoldIndex)
    {
        if (!this->isBlocked) {
            this->updateCurrentTarget();
        }
        this->needHolTimer = 0;
        return false;
    }

    if (gu && gu->type == "life" 
         && !gu->isActive && gu->profession == ""
        )
    {
       this->targetData.forNeedFreeWayCount ++;
       if (this->targetData.forNeedFreeWayCount >= 3) {
        this->iNeedFreeWay = this->personalCaseDeep != 3  ? true : false; // <<<<<<<<<<<<< ON 1/3
        this->targetData.forNeedFreeWayCount = 0;

       }
        if (this->iNeedFreeWay) {

            return true;
        }
    }

    if ((this->iNeedFreeWay &&
         gu &&
         gu->type == "life" &&
        !gu->inFight) && !isLoop(this)) {
        return true;
    }

    if (
        gu && gu->isActive && !gu->iNeedFreeWay && (this->wayIndex > 5) && (
             gu->inSave ||
              !this->isPotentialWayComplite 
              || this->isBlocked 
              || gu->way.length 
              || gu->wayIndex 
              || !gu->isPotentialWayComplite
              || !gu->orderOnWay.isComplite
             // || (iNeedFreeWay && gu && gu->type == "life")
              
                                               ) &&!isLoop(this))
    {
        return true;
    }

    return false;
}