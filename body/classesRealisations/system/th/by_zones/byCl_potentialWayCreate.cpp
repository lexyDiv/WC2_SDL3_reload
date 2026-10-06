#include "byCl_get_H.cpp"
//=>out

void ThData::byCl_potentialWayCreate(Unit *unit, Zone *finalZone) {
    

        //Cell *nextCell = finalCell;
        Zone *nextZone = finalZone;

       // unit->way.push(nextCell);

        while (true)
        {
            //  iter++;
            if (nextZone->thwd.getItemPtr(this->num)->wayFather &&
                nextZone->thwd.getItemPtr(this->num)->wayFather != unit->cell->zone)
            {
                nextZone = nextZone->thwd.getItemPtr(this->num)->wayFather;
               // unit->way.push(nextCell);
               unit->targetData.magistral.push(nextZone->cell);
            }
            else
            {
                unit->isPotentialWayComplite = true;
                break;
            }
        } 
     unit->way.push(unit->cell->aroundCells.getItem(0));
}