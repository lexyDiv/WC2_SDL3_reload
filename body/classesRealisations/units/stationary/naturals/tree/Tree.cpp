#include "tree_in.h"

BlockedData Tree::blockedCheck(Unit *unit)
{
    BlockedData bd;

    this->cell->aroundCells.forEach([unit, &bd, this](Cell *ac)
                                    {
    Unit *acu = ac->groundUnit;
    if (ac->plane == this->cell->plane &&  (!acu || acu == unit)) {
        bd.isBlocked = false;
    } });

    return bd;
}
