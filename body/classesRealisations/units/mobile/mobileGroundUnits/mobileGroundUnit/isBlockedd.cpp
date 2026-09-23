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

bool MobileGroundUnit::isBlockedd_full(Unit *unit)
{
    for (int i = 0; i < this->cell->aroundCells.length; i++)
    {
        Cell *ac = this->cell->aroundCells.getItem(i);
        if (!ac->groundUnit ||
           (
            // !ac->groundUnit->iNeedFreeWay && 
             (ac->groundUnit->wayIndex > 0 ||
            ac->groundUnit->way.length ||
            !ac->groundUnit->orderOnWay.isComplite ||
            ac->groundUnit == unit
            ))
        )
        {
            return false;
        }
    }
    return true;
};