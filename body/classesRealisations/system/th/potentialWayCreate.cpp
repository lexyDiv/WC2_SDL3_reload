#include "get_H.cpp"
//=>out


void ThData::potentialWayCreate(Unit *unit, Cell *finalCell)
{
    Cell *uc = unit->cell;
    if (uc &&
        uc != finalCell)
    {
        Cell *nextCell = finalCell;
        unit->way.push(nextCell);

        while (true)
        {
            //  iter++;
            if (nextCell->thwd.getItemPtr(this->num)->wayFather &&
                nextCell->thwd.getItemPtr(this->num)->wayFather != uc)
            {
                nextCell = nextCell->thwd.getItemPtr(this->num)->wayFather;
                unit->way.push(nextCell);
            }
            else
            {
                unit->isPotentialWayComplite = true;
                break;
            }
        }
    }
    unit->wayIndex = unit->way.length;
    unit->isPotentialWayComplite = true;
    unit->isIgetMyTarget = false;


  //  if (unit->focus)
  //  {
        TargetData &td = unit->targetData;
        if (unit->way.length >= 10 && !td.magistral.length && !this->isMagistral)
        {
            for (int i = 0; i < unit->way.length; i+= 5) {
                Cell *c = unit->way.getItem(i);
                td.magistral.push(c);
            }
            td.prevCell = td.magistral.getItem(td.magistral.length - 1);
            td.nextCell = td.magistral.getItem(td.magistral.length - 2);
            td.nextCellIndex = td.magistral.length - 2;
            // if (unit->focus)
            // {
            //     console.log("create magistral = ");
            // }
        }

        //  if (unit->persNum == 1)
        //  {
        //      console.log("iter = " + to_string(iter));
        //  }
   // }


            // if (unit->focus)
            // {
            //     console.log("create = ", iter);
            // }

    this->isMagistral = false;


    Uint64 resTime = SDL_GetTicks();
   // int delta = resTime - this->timeBeforeUnitWay;
    Uint64 deltaU = resTime - this->timeBeforeUnitWay;
    Uint64 timePerIter = deltaU;

    double h = (deltaU * 1000000) / (Uint64)iter;

    if (this->num == 0 ) {
        // one = false;
        // console.log("iter = ", iter);
        // console.log(to_string(resTime));
        // console.log(to_string(this->timeBeforeUnitWay));
        // console.log("delta = ", delta);
        // console.log("? = ", (double)hz);
        // console.log("--------------------------");

        console.log("? = ", h / 1000000);
       
    }

};