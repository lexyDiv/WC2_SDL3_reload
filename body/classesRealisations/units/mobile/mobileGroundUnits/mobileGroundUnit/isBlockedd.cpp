#include "iAmHere.cpp"
//=>getConor

BlockedData MobileGroundUnit::blockedCheck(Unit *unit)
{
    BlockedData bd;

    if (this->cell)
    {

        for (int i = 0; i < this->cell->aroundCells.length; i++)
        {
            Cell *ac = this->cell->aroundCells.getItem(i);
            if ((!ac->groundUnit || ac->groundUnit == unit) &&
             ac->plane == this->cell->plane)
            {
                return bd;
            }
            if (ac->groundUnit &&
                ((ac->groundUnit->wayIndex > 0 ||
                  ac->groundUnit->way.length ||
                  !ac->groundUnit->orderOnWay.isComplite //||
                //  ac->groundUnit == unit
                )))
            {
                bd.type = 'c';
            }
        }
    }
    bd.isBlocked = true;
    return bd;
}

// bool MobileGroundUnit::isBlockedd(Unit *unit)
// {
//     for (int i = 0; i < this->cell->aroundCells.length; i++)
//     {
//         Cell *ac = this->cell->aroundCells.getItem(i);
//         if (!ac->groundUnit //||
//            // (ac->groundUnit->wayIndex && !ac->groundUnit->needHolTimer && !ac->groundUnit->outHoldTimer) ||
//            || ac->groundUnit == unit)
//         {
//             return false;
//         }
//     }
//     return true;
// };

// bool MobileGroundUnit::isBlockedd_full(Unit *unit)
// {
//     for (int i = 0; i < this->cell->aroundCells.length; i++)
//     {
//         Cell *ac = this->cell->aroundCells.getItem(i);
//         if (!ac->groundUnit ||
//            (
//             // !ac->groundUnit->iNeedFreeWay &&
//              (ac->groundUnit->wayIndex > 0 ||
//             ac->groundUnit->way.length ||
//             !ac->groundUnit->orderOnWay.isComplite ||
//             ac->groundUnit == unit
//             ))
//         )
//         {
//             return false;
//         }
//     }
//     return true;
// };