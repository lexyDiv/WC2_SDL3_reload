#include "in.h"
//=>explore

bool isMyBuildingNeare(Zone *z, TargetData *td)
{
    for (int i = 0; i < z->buildingsNear.length; i++)
    {
        Unit *zBuilding = z->buildingsNear.getItem(i);
        if (td->unit == zBuilding)
        {
            return true;
        }
    }
    return false;
}


bool isTreeNeare(Unit *u, TargetData &utd)
{
    Zone *z = u->cell->zone;
    for (int i = 0; i < z->cells.length; i++)
    {
        Cell *c = z->cells.getItem(i);
        for (int k = 0; k < c->aroundCells.length; k++)
        {
            Cell *ac = c->aroundCells.getItem(k);
            Unit *acu = ac->groundUnit;
            if (acu &&
                utd.unit->cell->claster == ac->claster &&
                acu->canGiveTree && 
                acu->hp > 0 &&
                !acu->lesorub)
            {
                return true;
            }
        }
    }
    return false;
}



void ThData::byCl_createPW(Unit *unit)
{

    TargetData &utd = unit->targetData;

    if (!unit->cell->zone)
    {
        console.log("no unit cell zone");
      
           // console.log("wayFather->isActive = ", nextZone->thwd.getItemPtr(this->num)->wayFather->isActive);
          //  console.log("wayFather num = ", nextZone->thwd.getItemPtr(this->num)->wayFather->num);
            // console.log("unit vell claster num = ", unit->cell->claster->num);
            // console.log("wayFather cl isUpdated = ", unit->cell->claster->isUpdated);
            // console.log("wayFather cl isTouch = ", unit->cell->claster->isTouchUpdated);
            // console.log("------------------------------------------------------------------");

            // this->game->gf->focusClaster = unit->cell->claster;
        return;
    }
    else if (unit->targetData.clicckedCell && !unit->targetData.clicckedCell->zone && !unit->targetData.unit)
    {
            // console.log("!unit->targetData.clicckedCell->zone");
            // console.log("unit vell claster num = ", utd.clicckedCell->claster->num);
            // console.log("wayFather cl isUpdated = ", utd.clicckedCell->claster->isUpdated);
            // console.log("wayFather cl isTouch = ", utd.clicckedCell->claster->isTouchUpdated);
            // console.log("------------------------------------------------------------------");
            // this->game->gf->focusClaster = utd.clicckedCell->claster;
            return;
    }



    if ( 
        (utd.clicckedCell && utd.clicckedCell->zone == unit->cell->zone) ||

        (utd.unit && utd.unit->name == "tree" && isTreeNeare(unit, utd)// && unit->cell->zone->isTeesNear
       ) ||


        (utd.unit && utd.unit->type == "building" && isMyBuildingNeare(unit->cell->zone, &utd)) ||

        (!unit->cell->zone->contactZones.length)
       )
    {
        if (unit->focus && utd.unit && utd.unit->name == "tree") {
            console.log("return by tree = ", isTreeNeare(unit, utd));
        }
        return;
    }

    this->getSuccessLambda(unit);

    this->createCount += 0.001;
    if (this->createCount >= 100000000)
    {
        this->createCount = 0;
        console.log("default");
    }



    unit->way.clear();
    utd.magistral.clear();

    int currentDeep = 30000;             
    this->targetCell = utd.clicckedCell; 

    this->iter = 0;


    Td_way_data_z *td_way_data_z = unit->cell->zone->thwd.getItemPtr(this->num);

    td_way_data_z->createCountData = this->createCount;
    td_way_data_z->explored = this->createCount;
    this->openArr_z.clear();
    this->min_F_zone = unit->cell->zone;
    this->min_F_zone->thwd.getItemPtr(this->num)->F = 0;
    this->min_F_zone->thwd.getItemPtr(this->num)->H = 0;
    this->min_F_zone->thwd.getItemPtr(this->num)->G = 0;
    this->globalMin_H_zone = nullptr;

    this->openArr_z.push(this->min_F_zone);
    while (true)
    {

        this->iter++;

        MinData_z md;

        for (int i = 0; i < this->min_F_zone->contactZones.length; i++)
        {
            Zone *z = this->min_F_zone->contactZones.getItem(i);
            this->byCl_exploreNewZone(unit, this->min_F_zone, z, i);
        }

        if (this->openArr_z.length && this->iter < currentDeep)
        {
            int index = this->openArr_z.length - 1;
            md.zone = this->openArr_z.getItem(this->openArr_z.length - 1);
            md.index = index;

            this->openArr_z.forEach([this, &md](Zone *z, int i)
                                    {
                if (md.zone->thwd.getItemPtr(this->num)->F >= z->thwd.getItemPtr(this->num)->F)
                {
                    md.zone = z;
                    md.index = i;
                } });
            
            this->openArr_z.splice(md.index, 1);

            this->min_F_zone = md.zone;
            this->min_F_zone->thwd.getItemPtr(this->num)->explored = this->createCount;

           // console.log("this->min_F_zone H = ", this->min_F_zone->thwd.getItemPtr(this->num)->H);
            if (this->min_F_zone &&
                (this->min_F_zone->thwd.getItemPtr(this->num)->H) &&
                (!this->globalMin_H_zone || this->globalMin_H_zone->thwd.getItemPtr(this->num)->H > this->min_F_zone->thwd.getItemPtr(this->num)->H)
               )
            {
               // console.log("here = ", this->min_F_zone->thwd.getItemPtr(this->num)->H);
                this->globalMin_H_zone = this->min_F_zone;
            }
        }
        else
        {
            if (!this->globalMin_H_zone)
            {
            }
            else
            {
               // console.log("deep");
                this->byCl_potentialWayCreate(unit, this->globalMin_H_zone);
            }
            return;
        }


        if (
            this->min_F_zone == unit->targetData.clicckedCell->zone ||
            this->successWay(this->min_F_zone))
        {
          // console.log("classic");
            this->byCl_potentialWayCreate(unit, this->min_F_zone);
            unit->isPotentialWayComplite = true;
            break;
        }
    }
}