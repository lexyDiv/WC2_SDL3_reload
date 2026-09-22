#include "PWProcess.cpp"
//=>eploreNewCellAnd........

void ThData::createPotentialWay(Unit *unit)
{

    unit->way.clear();
    int currentDeep = unit->personalCaseDeep ? unit->personalCaseDeep : this->deep;
    // if (unit->iNeedFreeWay) {
    //     currentDeep = 100;
    // }
    this->iter = 0;

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

    if (!unit->iNeedFreeWay)
    {
        unit->cell->aroundCells.forEach([this, unit](Cell *cell)
                                        {
            Unit *gu = cell->groundUnit;
            if (gu
            && gu != unit->targetData.unit //unit->targetCell->groundUnit
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

                if (iter < currentDeep && unit->personalCaseDeep != 3)
                {
                    unit->iNeedFreeWay = true; /////////////// <<<<<<<<<<<<<<<<<<<<<<<<<<<< ON 3/3
                    unit->frashWayCheckNeed = true;
                }

                // console.log("MAXIMUM !!! = " + to_string(this->iter));
                // bool nextUnitIsNoActive = false;
                // for (int i = unit->way.length - 1; i >= 0; i--) {
                //      Cell *c = unit->way.getItem(i);
                //      if (c->groundUnit) {
                //         if (c->groundUnit->type == "life" && !c->groundUnit->isActive) {
                //             nextUnitIsNoActive = true;
                //         }
                //         break;
                //      }
                // }

                // if (unit->personalCaseDeep != 3
                //     && unit->way.length && unit->way.getItem(unit->wayIndex - 1)->groundUnit
                //     && !unit->way.getItem(unit->wayIndex - 1)->groundUnit->isActive
                // )
                // {
                //      unit->iNeedFreeWay = true; /////////////// <<<<<<<<<<<<<<<<<<<<<<<<<<<< ON
                //      unit->frashWayCheckNeed = true;
                //      console.log("here");
                // }
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