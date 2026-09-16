#include "get_HMagistral.cpp"
//=>out

void ThData::magistrallWayCreate(Unit *unit, MagistralClaster *finalMc)
{
   // console.log("CREATE");
    // Cell *uc = unit->cell;
    MagistralClaster *umc = unit->cell->mc;

    unit->targetData.magistralWay.push(unit->cell);

    if (umc &&
        umc != finalMc)
    {
        // Cell *nextCell = finalCell;
        MagistralClaster *nextMc = finalMc;
        // unit->way.push(nextCell);
        // unit->targetData.magistralWay.push(nextMc);

        int index = 0;

        while (true)
        {
            //  iter++;
            if (nextMc->thwd_mag.getItemPtr(this->num)->wayFather &&
                nextMc->thwd_mag.getItemPtr(this->num)->wayFather != umc)
            {

                nextMc = nextMc->thwd_mag.getItemPtr(this->num)->wayFather;

                if (index % 4 == 0)
                {
                    unit->targetData.magistralWay.push(nextMc->centralCell);
                }

                index++;
            }
            else
            {
                // unit->targetData.magistralWay.push(unit->targetData.clicckedCell);
                // unit->isPotentialWayComplite = true; // ????????????????????????????????????????????????????????
                break;
            }
        }
    }

    unit->targetData.magistralWay.push(unit->targetData.clicckedCell);
    ////////////////////////////////////////////////////////////////////////////////////////

    // console.log("good iter HERE = " + to_string(iter));

    // Unit *u = new Unit;
    // u->isNewCellOnGetWayValide = [](Cell *c, int iter)
    // {
    //     if (!c->groundUnit)
    //     {
    //         return true;
    //     }
    //     return false;
    // };
    // u->isOnGetPotentialWayGetTarget = [u](Cell *c)
    // {
    //     if (c->mc == u->targetData.clicckedCell->mc)
    //     {
    //         return true;
    //     }
    //     return false;
    // };
    // for (int i = 1, k = 2; k < unit->targetData.magistralWay.length - 1; i++, k++)
    // {
    //     if (k - i == 1)
    //     {
    //         Cell *prev = !u->potentialWay.length ? unit->targetData.magistralWay.getItem(i) : u->potentialWay.getItem(u->potentialWay.length - 1);
    //         Cell *target = unit->targetData.magistralWay.getItem(k);
    //         u->cell = prev;
    //         u->targetData.clicckedCell = target;

    //         this->createPotentialWay(u);
    //     }

    // }
    // delete u;
    // u = nullptr;
}