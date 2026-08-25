#include "PWProcess.cpp"
//=>eploreNewCellAnd........

void ThData::createPotentialWay(Unit *unit)
{
    // if (unit->focus)
    // {
    //     console.log("this 1 : " + to_string(this->deep));
    // }

    int iter = 0;

    this->getCurrentTargetCell(unit); // ok



    Td_way_data *td_way_data = unit->cell->thwd.length ? unit->cell->thwd.getItemPtr(this->num) : nullptr;



    if (
        unit->hp > 0 && td_way_data)
    {

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

        unit->cell->aroundCells.forEach([this, unit](Cell *cell)
                                        {
            Unit *gu = cell->groundUnit;
            if (gu
            && gu != unit->targetCell->groundUnit
            ) {
                cell->thwd.getItemPtr(this->num)->explored = this->createCount;
            } });

        while (true)
        {

            // Uint64 finishT = SDL_GetTicks();
            // Uint64 deltaT = finishT - startT;
            // if (deltaT > 20 && this->deep > this->minDeep)
            // {
            //     this->deep -= 10;
            // }
            // else if (this->deep < this->maxDeep)
            // {
            //     this->deep += 10;
            // }

            // if (needReturn)
            // {
            //     return;
            // }

            // if (iterationsPerSecond < targetFPS * 0.8)
            // {
            //     this->deep = 50;
            // }

            iter++;

            MinData md;

            if ((!unit->orderOnWay.isComplite))
            {
                unit->isPotentialWayComplite = true;
                return;
            }

            for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
            {
                Cell *pc = this->min_F_cell->aroundCells.getItem(i);
                this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc);
            }

            if (this->openArr.length && iter < this->deep)
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
                unit->isPotentialWayComplite = true;
                if (!this->globalMin_H_cell)
                {
                    unit->isPotentialWayComplite = true;
                    // if (unit->focus)
                    // {
                    //     console.log("69");
                    // }

                }
                else
                {

                    this->potentialWayCreate(unit, this->globalMin_H_cell);
                    // unit->targetCell = this->globalMin_H_cell;

                }

                return;
            }

            ///////////////////////////////////////////////////////

            if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell))
            {
                this->potentialWayCreate(unit, this->min_F_cell);
                break;
            }
        }
    }
};