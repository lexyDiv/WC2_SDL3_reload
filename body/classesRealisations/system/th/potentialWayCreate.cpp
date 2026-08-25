#include "get_H.cpp"
//=>out

void ThData::potentialWayCreate(Unit *unit, Cell *finalCell) {
    Cell *uc = unit->cell;
    if (uc &&
        uc != finalCell)
    {
        Cell *nextCell = finalCell;
        unit->potentialWay.push(nextCell);
       // int iter = 0;
        while (true)
        {
          //  iter++;
            if (nextCell->thwd.getItemPtr(this->num)->wayFather &&
                nextCell->thwd.getItemPtr(this->num)->wayFather != uc)
            {
                nextCell = nextCell->thwd.getItemPtr(this->num)->wayFather;
                unit->potentialWay.push(nextCell);
            }
            else
            {
                unit->isPotentialWayComplite = true;
                break;
            }
        }
    }

      unit->wayIndex = unit->potentialWay.length;
      unit->isPotentialWayComplite = true;
};