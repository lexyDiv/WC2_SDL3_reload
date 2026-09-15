#include "get_HMagistral.cpp"
//=>out

void ThData::magistrallWayCreate(Unit *unit, MagistralClaster *finalMc)
{
       // Cell *uc = unit->cell;
       MagistralClaster *umc = unit->cell->mc;
    if (umc &&
        umc != finalMc)
    {
        //Cell *nextCell = finalCell;
        MagistralClaster *nextMc = finalMc;
       // unit->way.push(nextCell);
       unit->targetData.magistralWay.push(nextMc);

        while (true)
        {
          //  iter++;
            if (nextMc->thwd_mag.getItemPtr(this->num)->wayFather &&
                nextMc->thwd_mag.getItemPtr(this->num)->wayFather != umc)
            {
                nextMc = nextMc->thwd_mag.getItemPtr(this->num)->wayFather;
               // unit->way.push(nextCell);
               unit->targetData.magistralWay.push(nextMc);
            }
            else
            {
                unit->isPotentialWayComplite = true; // ????????????????????????????????????????????????????????
                break;
            }
        }
    }
    //   unit->wayIndex = unit->way.length;
    //   unit->isPotentialWayComplite = true;
    //   unit->isIgetMyTarget = false;
}