#include "get_H.cpp"
//=>createMagistralWay

void ThData::potentialWayCreate(Unit *unit, Cell *finalCell) {
    Cell *uc = unit->cell;
    if (uc &&
        uc != finalCell)
    {
        Cell *nextCell = finalCell;
        unit->way.push(nextCell);

        while (true)
        {
          //  iter++;
            if (nextCell->thwd.getItemPtr(this->num)->wayFather &&
                nextCell->thwd.getItemPtr(this->num)->wayFather != uc)
            {
                nextCell = nextCell->thwd.getItemPtr(this->num)->wayFather;
                unit->way.push(nextCell);
            }
            else
            {
                unit->isPotentialWayComplite = true;
                break;
            }
        }
    }
      unit->wayIndex = unit->way.length;
      unit->isPotentialWayComplite = true;
      unit->isIgetMyTarget = false;
};