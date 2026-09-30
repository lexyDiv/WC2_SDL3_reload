#include "PWProcess.cpp"
//=>eploreNewCellAnd........

void ThData::createPotentialWay(Unit *unit)
{

    TargetData &utd = unit->targetData;

    if (utd.unit && utd.unit->type == "building" &&
        !unit->isIexplored && !utd.nextCell)
    {
        unit->iNeedFreeWay = utd.unit->isBlockedBuilding(unit, this);
        // utd.saveTargetIsBlocked = unit->iNeedFreeWay;
    }

    unit->way.clear();
    int currentDeep = unit->personalCaseDeep ? unit->personalCaseDeep : this->deep;
    this->targetCell = utd.nextCell ? utd.nextCell : utd.clicckedCell;

    if (utd.nextCell)
    {
        currentDeep = 5;
    }

    this->iter = 0;

    // bool tryChecked = false;

    Td_way_data *td_way_data = unit->cell->thwd.length ? unit->cell->thwd.getItemPtr(this->num) : nullptr;

    this->createCount += 0.001;
    if (this->createCount >= 100000000)
    {
        this->createCount = 0;
        console.log("default");
    }
    td_way_data->createCountData = this->createCount;
    this->openArr.clear();
    this->min_F_cell = unit->cell;
    this->min_F_cell->thwd.getItemPtr(this->num)->F = 0;
    this->min_F_cell->thwd.getItemPtr(this->num)->H = 0;
    this->min_F_cell->thwd.getItemPtr(this->num)->G = 0;
    this->globalMin_H_cell = nullptr;

    ///////////////////////////  poka tak!

    if ( //! unit->iNeedFreeWay &&
         !(unit->blockedData.isBlocked && unit->blockedData.type == 'f') &&
        (!utd.nextCell || unit->isLoopNextCellUnit))
    {
        unit->cell->aroundCells.forEach([this, unit, utd](Cell *cell)
                                        {
            Unit *gu = cell->groundUnit;
            if (gu &&
                 gu != utd.unit
            ) {
                cell->thwd.getItemPtr(this->num)->explored = this->createCount;
            } });
    }

    while (true)
    {

        this->iter++;

        MinData md;

        for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
        {
            Cell *pc = this->min_F_cell->aroundCells.getItem(i);
            this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc);
        }

        if (this->openArr.length && this->iter < currentDeep)
        {
            int index = this->openArr.length - 1;
            md.cell = this->openArr.getItem(this->openArr.length - 1);
            md.index = index;
            for (int i = index; i >= 0; i--)
            {
                Cell *cell = this->openArr.getItem(i);
                if (md.cell->thwd.getItemPtr(this->num)->F >= cell->thwd.getItemPtr(this->num)->F)
                {
                    md.cell = cell;
                    md.index = i;
                    if (cell->thwd.getItemPtr(this->num)->F < this->min_F_cell->thwd.getItemPtr(this->num)->F)
                    {
                        break;
                    }
                }
            }
            this->openArr.splice(md.index, 1);

            this->min_F_cell = md.cell;
            this->min_F_cell->thwd.getItemPtr(this->num)->explored = this->createCount;
            if (!this->globalMin_H_cell || this->globalMin_H_cell->thwd.getItemPtr(this->num)->H > this->min_F_cell->thwd.getItemPtr(this->num)->H)
            {
                this->globalMin_H_cell = this->min_F_cell;
            }
        }
        else
        {
            if (!this->globalMin_H_cell)
            {
            }
            else
            {

                this->potentialWayCreate(unit, this->globalMin_H_cell);

                // console.log("open.length = " + to_string(openArr.length) + " iter = " + to_string(iter));

                if ( // iter < 30 &&
                    (currentDeep != 5
                     //|| (utd.nextCell && iter < 5)
                     ) &&
                    unit->personalCaseDeep != 3 && (currentDeep != this->lowDeep || currentDeep < this->lowDeep)
                )
                {
                    unit->iNeedFreeWay = true; /////////////// <<<<<<<<<<<<<<<<<<<<<<<<<<<< ON 3/3
                    unit->frashWayCheckNeed = true;
                    // if (unit->focus) {
                    //     console.log("way ON");
                    // }
                }
                else if (currentDeep == 5)
                {
                    utd.magistrlLoop++;
                }

                if (currentDeep == 3)
                {
                    utd.clicckedCell = this->globalMin_H_cell;
                }
            }
            return;
        }

        ///////////////////////////////////////////////////////

        if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell))
        {
            this->potentialWayCreate(unit, this->min_F_cell);
            unit->isPotentialWayComplite = true;
            break;
        }
    }
};