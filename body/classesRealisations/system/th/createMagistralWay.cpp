#include "potentialWayCreate.cpp"
//=>exploreNewMagistral

void veer(Cell *cell, double &createCount, int &thdIndex)
{

    Cell *c = cell;
    c->thwd.getItemPtr(thdIndex)->createCountData = createCount;
    Array<Cell *> cells;
    cells.push(c);

    for (int i = 0; i < cells.length; i++)
    {
        Cell *cl = cells.getItem(i);
        for (int k = 0; k < cl->aroundCells.length; k++)
        {
            Cell *ac = cl->aroundCells.getItem(k);

            if (c && ac &&
                ac->mc == c->mc &&
                !ac->groundUnit &&
                ac->plane == cell->plane &&
                ac->thwd.getItemPtr(thdIndex)->createCountData != createCount)
            {
                cells.push(ac);
                ac->thwd.getItemPtr(thdIndex)->createCountData = createCount;
            }
        }
    }
}

void veerArr(Array<Cell *> &myValidCellsToFather, double &createCount, int &thdIndex)
{

    //    myValidCellsToFather.forEach([&thdIndex, &createCount](Cell *c){
    //     c->thwd.getItemPtr(thdIndex)->createCountData = createCount;
    //    });

    Array<Cell *> cells;
    cells.copy(myValidCellsToFather);

    for (int i = 0; i < cells.length; i++)
    {
        Cell *cl = cells.getItem(i);
        for (int k = 0; k < cl->aroundCells.length; k++)
        {
            Cell *ac = cl->aroundCells.getItem(k);

            if (ac && cl &&
                ac->mc == cl->mc &&
                !ac->groundUnit &&
                ac->plane == cl->plane &&
                ac->thwd.getItemPtr(thdIndex)->createCountData != createCount)
            {
                cells.push(ac);
                ac->thwd.getItemPtr(thdIndex)->createCountData = createCount;
            }
        }
    }
}

void ThData::createMagistralWay(Unit *unit)
{

    unit->targetData.magistralWay.clear(); // unit->way.clear();
    int currentDeep = 30000;               // unit->personalCaseDeep ? unit->personalCaseDeep : this->deep;
    this->iter = 0;

    Td_way_data_magistral *td_way_data_mag = unit->cell->mc->thwd_mag.getItemPtr(this->num);

    this->createCount += 0.001;
    if (this->createCount >= 100000000)
    {
        this->createCount = 0;
        console.log("default");
    }
    td_way_data_mag->createCountData = this->createCount;

    this->openArrMag.clear();

    this->min_F_mc = unit->cell->mc;
    this->min_F_mc->father = nullptr;
    this->min_F_mc->thwd_mag.getItemPtr(this->num)->F = 0;
    this->min_F_mc->thwd_mag.getItemPtr(this->num)->H = 0;
    this->min_F_mc->thwd_mag.getItemPtr(this->num)->G = 0;
    this->globalMin_H_mc = nullptr;

    ///////////////////////// first crox haldler
    veer(unit->cell, createCount, this->num);

    while (true)
    {

        
        MinDataMag md;

        this->exploreNewMagClasterAndAddToOpenArr(unit, this->min_F_mc);

        ////////////////////////////////////////////////////
        if (this->openArrMag.length && this->iter < currentDeep)
        {
            int index = this->openArrMag.length - 1;
            md.mc = this->openArrMag.getItem(this->openArrMag.length - 1);
            md.index = index;
            for (int i = index; i >= 0; i--)
            {
                MagistralClaster *mc = this->openArrMag.getItem(i);
                if (md.mc->thwd_mag.getItemPtr(this->num)->F >= mc->thwd_mag.getItemPtr(this->num)->F)
                {
                    md.mc = mc;
                    md.index = i;
                    if (mc->thwd_mag.getItemPtr(this->num)->F < this->min_F_mc->thwd_mag.getItemPtr(this->num)->F)
                    {
                        break;
                    }
                }
            }
            this->openArrMag.splice(md.index, 1);

            this->min_F_mc = md.mc;
            this->min_F_mc->thwd_mag.getItemPtr(this->num)->explored = this->createCount;
            if (!this->globalMin_H_mc || this->globalMin_H_mc->thwd_mag.getItemPtr(this->num)->H > this->min_F_mc->thwd_mag.getItemPtr(this->num)->H)
            {
                this->globalMin_H_mc = this->min_F_mc;
            }
        }
        else
        {
            if (!this->globalMin_H_mc)
            {
            }
            else
            {
                this->magistrallWayCreate(unit, this->globalMin_H_mc);
                console.log("bad iter = " + to_string(iter));
            }
            return;
        }
        ///////////////////////////////////////////////////

        MagistralClaster *mcTarget = unit->targetData.clicckedCell->mc;

        if (this->min_F_mc == mcTarget ||
            this->min_F_mc->left == mcTarget ||
            this->min_F_mc->right == mcTarget ||
            this->min_F_mc->up == mcTarget ||
            this->min_F_mc->down == mcTarget)
        {
            this->magistrallWayCreate(unit, this->min_F_mc);
            unit->isPotentialWayComplite = true;
            console.log("good iter = " + to_string(iter));
            break;

            
        }

        // if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell))
        // {
        //     this->potentialWayCreate(unit, this->min_F_cell);
        //     unit->isPotentialWayComplite = true;
        //     break;
        // }

      //  console.log("wery bad iter = " + to_string(iter));

    //   if (iter == 2) {
    //     return;
    //   }

      this->iter++;
    }

    ////////////////////////

    // this->min_F_cell = unit->cell;
    // this->min_F_cell->thwd.getItemPtr(this->num)->F = 0;
    // this->min_F_cell->thwd.getItemPtr(this->num)->H = 0;
    // this->min_F_cell->thwd.getItemPtr(this->num)->G = 0;
    // this->globalMin_H_cell = nullptr;

    ///////////////////////////  poka tak!

    // unit->cell->aroundCells.forEach([this, unit](Cell *cell)
    //                                 {
    //         Unit *gu = cell->groundUnit;
    //         if (gu
    //         && gu != unit->targetData.unit //unit->targetCell->groundUnit
    //         ) {
    //             cell->thwd.getItemPtr(this->num)->explored = this->createCount;
    //         } });

    // while (true)
    // {

    //     this->iter++;

    //     MinData md;

    //     for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
    //     {
    //         Cell *pc = this->min_F_cell->aroundCells.getItem(i);
    //         this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc);
    //     }

    //     if (this->openArr.length && this->iter < currentDeep)
    //     {
    //         int index = this->openArr.length - 1;
    //         md.cell = this->openArr.getItem(this->openArr.length - 1);
    //         md.index = index;
    //         for (int i = index; i >= 0; i--)
    //         {
    //             Cell *cell = this->openArr.getItem(i);
    //             if (md.cell->thwd.getItemPtr(this->num)->F >= cell->thwd.getItemPtr(this->num)->F)
    //             {
    //                 md.cell = cell;
    //                 md.index = i;
    //                 if (cell->thwd.getItemPtr(this->num)->F < this->min_F_cell->thwd.getItemPtr(this->num)->F)
    //                 {
    //                     break;
    //                 }
    //             }
    //         }
    //         this->openArr.splice(md.index, 1);

    //         this->min_F_cell = md.cell;
    //         this->min_F_cell->thwd.getItemPtr(this->num)->explored = this->createCount;
    //         if (!this->globalMin_H_cell || this->globalMin_H_cell->thwd.getItemPtr(this->num)->H > this->min_F_cell->thwd.getItemPtr(this->num)->H)
    //         {
    //             this->globalMin_H_cell = this->min_F_cell;
    //         }
    //     }
    //     else
    //     {
    //         if (!this->globalMin_H_cell)
    //         {
    //         }
    //         else
    //         {
    //             this->potentialWayCreate(unit, this->globalMin_H_cell);
    //         }
    //         return;
    //     }

    //     ///////////////////////////////////////////////////////

    //     if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell))
    //     {
    //         this->potentialWayCreate(unit, this->min_F_cell);
    //         unit->isPotentialWayComplite = true;
    //         break;
    //     }
    // }
};