#include "potentialWayCreate.cpp"
//=>exploreNewMagistral

void veer(Unit *unit, ThData *td)
{

    MagistralClaster *mc = unit->cell->mc;
    Td_way_data_magistral *thwdMc = mc->thwd_mag.getItemPtr(td->num);

    Array<Cell *> cells;
    cells.push(unit->cell);

    cells.forEach([td, mc, thwdMc, unit, &cells](Cell *c)
                  {
        Td_way_data *thwdC = c->thwd.getItemPtr(td->num);
        Td_way_data_magistral *thwdMcC = c->mc->thwd_mag.getItemPtr(td->num);
          c->aroundCells.forEach([td, mc, thwdMc, unit, &cells](Cell *ac){
        Td_way_data *thwdAc = ac->thwd.getItemPtr(td->num);
        Td_way_data_magistral *thwdMcAc = ac->mc->thwd_mag.getItemPtr(td->num);
        if (unit->isOnGetPotentialWayGetTarget(ac)) {
                td->magOK = true;
                console.log("clear finish");
               }
          if (thwdAc->createCountData != td->createCount &&
              ac->mc == mc &&
              unit->isNewCellOnGetWayValide(ac, td->iter)) {
                thwdAc->createCountData = td->createCount;
                cells.push(ac);
              }
          }); });
    mc->validCellsToFather.clear();
    mc->validCellsToFather.copy(cells);
}

void addToSonValidCellsToFather(Unit *unit, ThData *td, MagistralClaster *son)
{
    son->validCellsToFather.forEach([td, son, unit](Cell *cell)
                                    { cell->aroundCells.forEach([td, son, unit](Cell *ac)
                                                                {
                    Td_way_data *thwd_ac = ac->thwd.getItemPtr(td->num);
                if (unit->isOnGetPotentialWayGetTarget(ac)) {
                td->magOK = true;
                console.log("finish bliat !!!");
               }
        if (thwd_ac->createCountData != td->createCount &&
            ac->mc == son &&
            unit->isNewCellOnGetWayValide(ac, 0)) {
               thwd_ac->createCountData = td->createCount;
               son->validCellsToFather.push(ac);
        } }); });
}

void ThData::createMagistralWay(Unit *unit)
{

    // if (this->frash)
    // {
        // console.log("frash");
        this->frash = false;
        unit->targetData.magistralWay.clear();
        int currentDeep = 30000;
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
        this->cam.clear();

        this->min_F_mc = unit->cell->mc;
        this->min_F_mc->thwd_mag.getItemPtr(this->num)->wayFather = nullptr;
        this->min_F_mc->thwd_mag.getItemPtr(this->num)->F = 0;
        this->min_F_mc->thwd_mag.getItemPtr(this->num)->H = 0;
        this->min_F_mc->thwd_mag.getItemPtr(this->num)->G = 0;
        this->globalMin_F_mc = nullptr;
        this->openArrMag.push(this->min_F_mc);

        veer(unit, this);

        if (this->magOK)
        {
            console.log("special create");
            this->magOK = false;
            unit->targetData.magistralWay.push(unit->targetData.clicckedCell);
            unit->targetData.magistralWay.push(unit->cell);
           // this->magistrallWayCreate(unit, this->min_F_mc);
            unit->isPotentialWayComplite = true;
            // console.log("good iter = " + to_string(iter));
            return;
        }
  //  }

    while (true)
    {

    // if (this->nextStap)
    // {
         //console.log("step");
        this->nextStap = false;

        //////////////////////////////////////////////////////////////////////////////
        MinDataMag md;


        if (this->openArrMag.length
             && this->iter < 1500
        )
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
                }
            }

            this->min_F_mc = md.mc;
            this->cam.push(this->min_F_mc);
            this->min_F_mc->thwd_mag.getItemPtr(this->num)->explored = this->createCount;
            this->openArrMag.splice(md.index, 1);
           // this->min_F_mc->thwd_mag.getItemPtr(this->num)->explored = this->createCount;

            if (iter && ((!this->globalMin_F_mc )
                || (this->globalMin_F_mc->thwd_mag.getItemPtr(this->num)->F > this->min_F_mc->thwd_mag.getItemPtr(this->num)->F)))
            {
                
                this->globalMin_F_mc = this->min_F_mc;
            }
        }
        else
        {
           // if (!this->globalMin_H_mc)
           // {
                       

                this->magistrallWayCreate(unit, this->globalMin_F_mc);
               // console.log("bad iter = " + to_string(iter));
          //  }
            return;
        }


        // this->exploreNewMagClasterAndAddToOpenArr(unit, this->min_F_mc);
        this->min_F_mc->aroundMc.forEach([unit, this](MagistralClaster *mc)
                                         {
                                             this->exploreNewMagClasterAndAddToOpenArr(unit, mc);
                                             this->min_F_mc->thwd_mag.getItemPtr(this->num)->explored = this->createCount;
                                         });


            this->openArrMag.filterSelf([this](MagistralClaster *mc)
                                        {
            if (mc->thwd_mag.getItemPtr(this->num)->explored == this->createCount) {
                this->cam.push(mc);
                return true;
            }
            return false; });


        ////////////////////////////////////////////////////
         /// wose here
        ///////////////////////////////////////////////////

       // MagistralClaster *mcTarget = unit->targetData.clicckedCell->mc;

        if (this->magOK)
        {
            ;
            this->magistrallWayCreate(unit, this->min_F_mc);
            this->magOK = false;
            unit->isPotentialWayComplite = true;
            // console.log("good iter = " + to_string(iter));
            return;
        }

        this->iter++;
    }
    //  }
};