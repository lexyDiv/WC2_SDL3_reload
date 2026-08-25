#include "getCurrentTargetCell.cpp"
//=>get_G

bool ThData::isBlocked(Cell *cell, Unit *unit)
{
    for (int i = 0; i < cell->aroundCells.length; i++)
    {
        Cell *ac = cell->aroundCells.getItem(i);
        Unit *gu = ac->groundUnit;
        if (!gu || gu->way.length ||
            (unit->profession == "lesorub" && gu->name == "tree"))
        {
            return false;
        }
    }
    return true;
};