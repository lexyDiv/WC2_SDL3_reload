#include "isNeedHoldGoWay.cpp"
//=>orderOnWayCotrol

bool MobileGroundUnit::isNextCellFreeToGoWay(Cell *nextCell)
{
    if (!nextCell->groundUnit)
    {
        return true;
    }
    return false;
};