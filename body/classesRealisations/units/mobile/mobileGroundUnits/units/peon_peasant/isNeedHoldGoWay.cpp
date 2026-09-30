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

    this->isLoopNextCellUnit = isLoop(this);

    int needHoldIndex = !this->iNeedFreeWay ? 5 : 5;

    if (this->needHolTimer >= this->wayIndex * needHoldIndex
        //&& (!this->targetData.specialFreeG0 || this->needHolTimer >= 2000)
    )
    {
        // if (

        //    //!this->blockedData.isBlocked //||
        //    //(this->blockedData.isBlocked && this->blockedData.type == 'c') //!this->isBlocked
        // )
        // {
        //     this->updateCurrentTarget();
        // }
        this->needHolTimer = 0;
        this->iNeedFreeWay = false;

        return false;
    }

    if (gu && gu->type == "life" && !gu->isActive //&& gu->profession == ""
    )
    {
        this->targetData.forNeedFreeWayCount++;
        if (this->targetData.forNeedFreeWayCount >= 3)
        {
            this->iNeedFreeWay = this->personalCaseDeep != 3 ? true : false; // <<<<<<<<<<<<< ON 1/3
            this->targetData.forNeedFreeWayCount = 0;
        }
    }

    if (this->iNeedFreeWay &&
        gu &&
        gu->type == "life" &&
        !gu->inFight
        // && !gu->iNeedFreeWay
        && !this->isLoopNextCellUnit)
    {
        return true;
    }

    if (
        gu &&
        gu->isActive &&
        ((this->wayIndex > 5 || this->targetData.nextCell) && this->way.length)

        && (gu->inSave ||
            (this->blockedData.isBlocked) ||
            ((gu->way.length || gu->wayIndex || !gu->isPotentialWayComplite || !gu->orderOnWay.isComplite)// &&
            //  (((this->wood || this->gold) && (gu->wood || gu->gold)) ||
            //   (!(this->wood || this->gold) && !(gu->wood || gu->gold)))
            )
            ) &&
        !this->isLoopNextCellUnit)
    {
        return true;
    }

    return false;
}