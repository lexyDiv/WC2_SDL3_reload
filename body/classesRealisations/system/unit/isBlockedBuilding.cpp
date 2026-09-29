#include "getNeedRefactorCell.cpp"
//=>out

bool Unit::isBlockedBuilding(Unit *u, ThData *td)
{

    if (this->cell && this->hp)
    {

        int freeContactCellsCount = 0;
        bool isNear = false;

        this->contactCells.forEach([u, &freeContactCellsCount, &isNear, this](Cell *cc)
                                   {
        Unit *ccu = cc->groundUnit;
        if (!ccu && cc->plane == this->cell->plane) {
            freeContactCellsCount++;
        } else if (ccu == u) {
           isNear = true;
        } });

        if (isNear)
        {
          //  console.log("here");
            return false;
        }

        if (!freeContactCellsCount)
        {

           // console.log("here 2");
            return true;
        }

        int freeMaxCellsCount = 0;

        MinData md;
        Peon_peasant ng(this->fraction);
        Unit *ngu = &ng; //new Peon_peasant(this->fraction);

        this->cell->maxAroundCells.forEach([&md, this, &freeMaxCellsCount, ngu](Cell *mac, int i)
                                           {
        Unit *macu = mac->groundUnit;
        ngu->cell = mac;
        if (!macu && !ngu->blockedCheck(ngu).isBlocked) {
            freeMaxCellsCount++;
            double currentDis = this->cell->maxAroundCellsDis.getItem(i);
            if (!md.cell) {
                md.cell = mac;
                md.dis = currentDis;
            } else if (md.dis < currentDis) {
                md.cell = mac;
                md.dis = currentDis;
            }
        } });

        if (freeMaxCellsCount == freeContactCellsCount)
        {
           // console.log("here 3");
            return true;
        }

        Cell *exploredCell = md.cell;

        this->tt = exploredCell;
        ngu->isIexplored = true;
        ngu->cell = exploredCell;
        ngu->targetData.clicckedCell = this->cell;
        ngu->targetData.unit = this;
        ngu->personalCaseDeep = 100;

        ngu->isNewCellOnGetWayValide = [ngu](Cell *c, int iter)
        {
            if (!c->groundUnit || c->groundUnit == ngu->targetData.unit)
            {
                return true;
            }
            return false;
        };

        ngu->isOnGetPotentialWayGetTarget = [ngu](Cell *c)
        {
            if (c->groundUnit == ngu->targetData.unit)
            {
                return true;
            }
            return false;
        };

        td->createPotentialWay(ngu);
       // console.log("length = " + to_string(ngu->way.length));
        if (ngu->way.length)
        {
            if (ngu->way.getItem(0)->groundUnit == this)
            {
  
                //console.log("here 4");
                return false;
            }
        }
       // console.log("here 5"); //here
        return true;
    }
   //console.log("here 6");
    return false;
}