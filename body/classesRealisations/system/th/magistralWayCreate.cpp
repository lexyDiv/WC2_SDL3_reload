#include "get_HMagistral.cpp"
//=>out

void ThData::magistrallWayCreate(Unit *unit, MagistralClaster *finalMc)
{
    // console.log("CREATE");
    // Cell *uc = unit->cell;
    MagistralClaster *umc = unit->cell->mc;

    if (this->magOK)
    {
        unit->targetData.magistralWay.push(unit->targetData.clicckedCell);
    }
    else
    {
        unit->targetData.magistralWay.push(finalMc->centralCell);
    }

    // console.log(to_string(umc->centralCell->persNum) + " " + to_string(finalMc->centralCell->persNum));
    if (umc &&
        umc != finalMc)
    {
        // console.log("CREATE");
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
                    Cell *validCell = nullptr;
                    if (unit->isNewCellOnGetWayValide(nextMc->centralCell, 0))
                    {
                        validCell = nextMc->centralCell;
                    }
                    else
                    {
                        for (int i = 0; i < nextMc->centralCell->aroundCells.length; i++)
                        {
                            Cell *c = nextMc->centralCell->aroundCells.getItem(i);
                            if (unit->isNewCellOnGetWayValide(c, 0))
                            {
                                validCell = c;
                                break;
                            }
                        }
                    }

                    unit->targetData.magistralWay.push(validCell);
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

    unit->targetData.magistralWay.push(unit->cell);
    console.log(to_string(iter));
    // unit->targetData.magistralWay.push(unit->targetData.clicckedCell);
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