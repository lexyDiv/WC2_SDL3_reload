#include "byCl_get_H.cpp"
//=>getSuccessLambda

void ThData::byCl_potentialWayCreate(Unit *unit, Zone *finalZone) {
    

        //Cell *nextCell = finalCell;
        Zone *nextZone = finalZone;
        TargetData &td = unit->targetData;
       // unit->way.push(nextCell);

        while (true)
        {
            //  iter++;
            if (nextZone->thwd.getItemPtr(this->num)->wayFather &&
                nextZone->thwd.getItemPtr(this->num)->wayFather != unit->cell->zone)
            {
                nextZone = nextZone->thwd.getItemPtr(this->num)->wayFather;
               // unit->way.push(nextCell);
               td.magistral.push(nextZone->cell);
            }
            else
            {
                unit->isPotentialWayComplite = true;
                break;
            }
        } 

          if (td.magistral.length >= 2) {
            td.prevCell = td.magistral.getItem(td.magistral.length - 1);
            td.nextCell = td.magistral.getItem(td.magistral.length - 2);
            td.nextCellIndex = td.magistral.length - 2;
          } else {
            td.magistral.clear();
          }


            unit->way.push(unit->cell->aroundCells.getItem(0));
            console.log("Create Claster = ", iter);
}