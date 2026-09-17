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

void addToSonValidCellsToFather(Unit *unit, ThData *td, MagistralClaster *father, MagistralClaster *son) {
    
}

void ThData::createMagistralWay(Unit *unit)
{

    if (this->frash)
    {
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
        this->min_F_mc->father = nullptr;
        this->min_F_mc->thwd_mag.getItemPtr(this->num)->F = 0;
        this->min_F_mc->thwd_mag.getItemPtr(this->num)->H = 0;
        this->min_F_mc->thwd_mag.getItemPtr(this->num)->G = 0;
        this->globalMin_H_mc = nullptr;
        this->openArrMag.push(this->min_F_mc);

        veer(unit, this);
    }

    // while (true)
    // {

    if (this->nextStap)
    {
        // console.log("step");
        this->nextStap = false;
        MinDataMag md;

       // this->exploreNewMagClasterAndAddToOpenArr(unit, this->min_F_mc);
       this->min_F_mc->aroundMc.forEach([unit, this](MagistralClaster *mc){
             this->exploreNewMagClasterAndAddToOpenArr(unit, mc);
       });

        ////////////////////////////////////////////////////
        if (this->openArrMag.length
            // && this->iter < currentDeep
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
                    // if (mc->thwd_mag.getItemPtr(this->num)->F < this->min_F_mc->thwd_mag.getItemPtr(this->num)->F)
                    // {
                    //     break;
                    // }
                }
            }

            // MagistralClaster *mc = this->openArrMag.getItem(md.index);
            // Array<MagistralClaster *> kuku;
            // kuku.push(mc);
            // mc->thwd_mag.getItemPtr(this->num)->explored = this->createCount;
            // this->cam.push(mc);
            // this->openArrMag.splice(md.index, 1);
            this->openArrMag.filterSelf([this](MagistralClaster *mc)
                                        {
            if (mc->thwd_mag.getItemPtr(this->num)->explored == this->createCount) {
                this->cam.push(mc);
                return true;
            }
            return false; });

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
                this->magistrallWayCreate(unit, this->globalMin_H_mc);
                console.log("bad iter = " + to_string(iter));
            }
            return;
        }
        ///////////////////////////////////////////////////

        MagistralClaster *mcTarget = unit->targetData.clicckedCell->mc;

        if (this->magOK ||
            ((unit->targetData.clicckedCell->thwd.getItemPtr(this->num)->createCountData == this->createCount ||
              iter >= 3) &&
             (this->min_F_mc == mcTarget ||
              this->min_F_mc->left == mcTarget ||
              this->min_F_mc->right == mcTarget ||
              this->min_F_mc->up == mcTarget ||
              this->min_F_mc->down == mcTarget)))
        {
            this->magOK = false;
            this->magistrallWayCreate(unit, this->min_F_mc);
            unit->isPotentialWayComplite = true;
            // console.log("good iter = " + to_string(iter));
            return;
        }

        this->iter++;
    }
    //  }
};