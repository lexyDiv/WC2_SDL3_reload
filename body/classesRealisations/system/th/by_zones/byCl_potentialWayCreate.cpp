#include "byCl_get_H.cpp"
//=>getSuccessLambda

void ThData::byCl_potentialWayCreate(Unit *unit, Zone *finalZone) {
    

        //Cell *nextCell = finalCell;
        Zone *nextZone = finalZone;
        TargetData &td = unit->targetData;
       // unit->way.push(nextCell);
        int tt = 0;
        while (true)
        {
          tt++;
          if (tt >= 3000) {
             console.log("create LOOP, iter = ", iter);
            // console.log("wayFather->isActive = ", nextZone->thwd.getItemPtr(this->num)->wayFather->isActive);
            // console.log("wayFather num = ", nextZone->thwd.getItemPtr(this->num)->wayFather->num);
            // console.log("wayFather claster num = ", nextZone->thwd.getItemPtr(this->num)->wayFather->cl->num);
            // console.log("wayFather cl isUpdated = ", nextZone->thwd.getItemPtr(this->num)->wayFather->cl->isUpdated);
            // console.log("wayFather cl isTouch = ", nextZone->thwd.getItemPtr(this->num)->wayFather->cl->isTouchUpdated);
            // console.log("------------------------------------------------------------------");

            // this->game->gf->focusClaster = nextZone->thwd.getItemPtr(this->num)->wayFather->cl;

            return;
          }
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
           // td.isNeedClasterMagistral = false;
           // console.log("Create Claster = ", iter);
          } else {
            td.magistral.clear();
          }


            //unit->way.push(unit->cell->aroundCells.getItem(0));
          //  console.log("iter = ", iter);
            
}