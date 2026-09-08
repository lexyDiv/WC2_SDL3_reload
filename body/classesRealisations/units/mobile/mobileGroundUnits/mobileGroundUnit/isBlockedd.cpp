#include "iAmHere.cpp"
//=>getConor

bool MobileGroundUnit::isBlockedd(Unit *unit)
{
    for (int i = 0; i < this->cell->aroundCells.length; i++)
    {
        Cell *ac = this->cell->aroundCells.getItem(i);
        if (!ac->groundUnit //||
           // (ac->groundUnit->wayIndex && !ac->groundUnit->needHolTimer && !ac->groundUnit->outHoldTimer) ||
           || ac->groundUnit == unit)
        {
            return false;
        }
    }
    return true;
};