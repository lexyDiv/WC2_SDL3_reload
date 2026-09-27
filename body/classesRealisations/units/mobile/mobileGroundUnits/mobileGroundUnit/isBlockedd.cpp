#include "iAmHere.cpp"
//=>getConor

BlockedData MobileGroundUnit::blockedCheck(Unit *unit)
{
    BlockedData bd;
    Cell *tc = this->cell;
    if (tc)
    {

        for (int i = 0; i < tc->aroundCells.length; i++)
        {
            Cell *ac = tc->aroundCells.getItem(i);
            if ((!ac->groundUnit || ac->groundUnit == unit) &&
             ac->plane == tc->plane)
            {
                return bd;
            }
            if (ac->groundUnit &&
                ((ac->groundUnit->wayIndex > 0 ||
                  ac->groundUnit->way.length ||
                  !ac->groundUnit->orderOnWay.isComplite
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