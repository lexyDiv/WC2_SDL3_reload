#include "in.h"
//=>explore

void ThData::byCl_createPW(Unit *unit)
{

    if (!unit->cell->zone) {
        console.log("no unit cell zone");
        return;
    } else if (!unit->targetData.clicckedCell->zone && !unit->targetData.unit) {
        console.log("!unit->targetData.clicckedCell->zone");
    }

TargetData &utd = unit->targetData;

    if (//!utd.isNeedClasterMagistral ||
        (utd.clicckedCell && utd.clicckedCell->zone == unit->cell->zone) ||
        (!unit->cell->zone->contactZones.length)
    ) {
        return;
    }

    this->getSuccessLambda(unit);

    this->createCount += 0.001;
    if (this->createCount >= 100000000)
    {
        this->createCount = 0;
        console.log("default");
    }
    

    // if (utd.unit && utd.unit->type == "building" &&
    //     !unit->isIexplored && !utd.nextCell)
    // {
    //     unit->iNeedFreeWay = utd.unit->isBlockedBuilding(unit, this);
    //     // utd.saveTargetIsBlocked = unit->iNeedFreeWay;
    // }

    unit->way.clear();
    utd.magistral.clear();

    int currentDeep = 30000; // unit->personalCaseDeep ? unit->personalCaseDeep : this->deep;
    this->targetCell = utd.clicckedCell; //utd.nextCell ? utd.nextCell : utd.clicckedCell;


    this->iter = 0;

    // bool tryChecked = false;

   // Td_way_data *td_way_data = unit->cell->thwd.length ? unit->cell->thwd.getItemPtr(this->num) : nullptr;
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
//////////////////////////////////////////////
        if (this->openArr_z.length && this->iter < currentDeep)
        {
            int index = this->openArr_z.length - 1;
            md.zone = this->openArr_z.getItem(this->openArr_z.length - 1);
            md.index = index;
          //  for (int i = index; i >= 0; i--)
          //  {
              this->openArr_z.forEach([this, &md](Zone *z, int i){
               // Cell *cell = this->openArr.getItem(i);
                if (md.zone->thwd.getItemPtr(this->num)->F >= z->thwd.getItemPtr(this->num)->F)
                {
                    md.zone = z;
                    md.index = i;
                    // if (cell->thwd.getItemPtr(this->num)->F < this->min_F_cell->thwd.getItemPtr(this->num)->F)
                    // {
                    //     break;
                    // }
                }
                });
           // }
            this->openArr_z.splice(md.index, 1);

            this->min_F_zone = md.zone;
            this->min_F_zone->thwd.getItemPtr(this->num)->explored = this->createCount;
            if (!this->globalMin_H_zone || this->globalMin_H_zone->thwd.getItemPtr(this->num)->H > this->min_F_zone->thwd.getItemPtr(this->num)->H)
            {
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

                // if (iter == 30000 && unit->targetData.unit) {
                //     console.log("================================================================");
                //     //console.log("MAX = " + unit->targetData.unit->name + " free " + to_string(unit->iNeedFreeWay) + " nextC = " + to_string((bool)utd.nextCell));
                //     console.log("NAME = " + unit->targetData.unit->name);
                //     console.log("wayIndex = " + to_string(unit->wayIndex));
                //     console.log("wayTakts = " + to_string(unit->wayTakts));
                //     console.log("iNeedFreeWay = " + to_string(unit->iNeedFreeWay));
                //     console.log("isBlocked = " + to_string(unit->blockedData.isBlocked));
                //     console.log("utd.nextCell = " + to_string((bool)utd.nextCell));
                //     console.log("unitIsLoopNextCellUnit = " + to_string(unit->isLoopNextCellUnit));

                //     unit->targetData.unit->deepMetka = true;
                // } else if (iter == 30000) {
                //     console.log("MAX no target unit");
                // }

                this->byCl_potentialWayCreate(unit, this->globalMin_H_zone);

                // console.log("open.length = " + to_string(openArr.length) + " iter = " + to_string(iter));

                // if ( // iter < 30 &&
                //     (currentDeep != 7
                //      //|| (utd.nextCell && iter < 5)
                //      ) &&
                //     unit->personalCaseDeep != 3 && (currentDeep != this->lowDeep || iter < this->lowDeep))
                // {
                //     unit->iNeedFreeWay = true; /////////////// <<<<<<<<<<<<<<<<<<<<<<<<<<<< ON 3/3
                //     unit->frashWayCheckNeed = true;
                //     // if (unit->focus) {
                //     //     console.log("way ON");
                //     // }
                // }
                // else if (currentDeep == 7)
                // {
                //     utd.magistrlLoop++;
                // }

                // if (currentDeep == 3)
                // {
                //     utd.clicckedCell = this->globalMin_H_cell;
                // }
            }
            return;
        }

        ///////////////////////////////////////////////////////

        if (
            this->min_F_zone == unit->targetData.clicckedCell->zone ||
            this->successWay(this->min_F_zone)
        )
        {
            this->byCl_potentialWayCreate(unit, this->min_F_zone);
            unit->isPotentialWayComplite = true;
            break;
        }
    }
}