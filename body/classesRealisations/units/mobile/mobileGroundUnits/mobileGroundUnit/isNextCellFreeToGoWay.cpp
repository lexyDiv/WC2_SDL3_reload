#include "isNeedHoldGoWay.cpp"
//=>orderOnWayCotrol

bool MobileGroundUnit::isNextCellFreeToGoWay(Cell *nextCell)
{
    if (!nextCell->groundUnit && nextCell->zone)
    {
        return true;
    }
    return false;
};