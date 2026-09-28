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


    if (unit->focus)
    {

        if (unit->way.length >= 10 && !unit->targetData.magistral.length && !this->isMagistral)
        {
            for (int i = 0; i < unit->way.length; i+= 5) {
                Cell *c = unit->way.getItem(i);
                unit->targetData.magistral.push(c);
            }
            // if (unit->focus)
            // {
            //     console.log("create magistral = " + to_string(unit->targetData.unit->persNum));
            // }
        }

        // if (unit->focus)
        // {
        //     console.log("iter = " + to_string(iter));
        // }
    }


    this->isMagistral = false;
};