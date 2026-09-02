#include "orderOnWayControl.cpp"
//=>out

bool isLoop(Unit *self)
{

Unit *unit1 = self;
Unit *unit2 = unit1->nextCell && unit1->nextCell->groundUnit ? unit1->nextCell->groundUnit : nullptr;
Unit *unit3 = unit2 && unit2->nextCell && unit2->nextCell->groundUnit ? unit2->nextCell->groundUnit : nullptr;
Unit *unit4 = unit3 && unit3->nextCell && unit3->nextCell->groundUnit ? unit3->nextCell->groundUnit : nullptr;
Unit *unit5 = unit4 && unit4->nextCell && unit4->nextCell->groundUnit ? unit4->nextCell->groundUnit : nullptr;

if (unit3 != self && unit4 != self && unit5 != self) {
    return false;
}
return true;
};



bool Peon_peasant::isNeedHoldGoWay()
{
   Cell *nc = this->nextCell; 

    Unit *gu = nc ? nc->groundUnit : nullptr;
    Cell *guNextCell = gu ? gu->nextCell : nullptr;
    Unit *gutdu = gu ? gu->targetData.unit : nullptr;

    if (this->needHolTimer >= this->needHoldTimerMax)
    {
        this->needHolTimer = 0;
        return false;
    }

    if (
        gu
        && (this->wayTakts > 7 || gu->inSave)
        && !isLoop(this)
    )
    {
        return true;
    }




    return false;
}