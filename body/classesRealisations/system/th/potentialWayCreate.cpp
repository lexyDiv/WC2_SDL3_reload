#include "get_H.cpp"
//=>out

void ThData::potentialWayCreate(Unit *unit, Cell *finalCell) {
        Cell *uc = unit->cell;
    if (uc &&
        uc != finalCell)
    {
        Cell *nextCell = finalCell;
        Td_way_data *nextCell_thwd = nextCell->thwd.getItemPtr(this->num);
        unit->potentialWay.push(nextCell);
        int large = 0;
        while (true)
        {
            if (nextCell_thwd->wayFather &&
                nextCell_thwd->wayFather != uc)
            {
                nextCell = nextCell_thwd->wayFather;
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