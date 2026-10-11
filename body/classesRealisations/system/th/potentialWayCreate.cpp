#include "get_H.cpp"
//=>out


void ThData::potentialWayCreate(Unit *unit, Cell *finalCell)
{
    Cell *uc = unit->cell;
    TargetData &td = unit->targetData;
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
               // td.magistral.push(unit->cell);
                unit->isPotentialWayComplite = true;
                break;
            }
        }
    }
    unit->wayIndex = unit->way.length;
    unit->isPotentialWayComplite = true;
    unit->isIgetMyTarget = false;



        
        
        if (unit->way.length >= 8 && !td.magistral.length && !this->isMagistral)
        {
            for (int i = 0; i < unit->way.length; i+= 4) {
                Cell *c = unit->way.getItem(i);
                td.magistral.push(c);
            }
            
            td.prevCell = td.magistral.getItem(td.magistral.length - 1);
            td.nextCell = td.magistral.getItem(td.magistral.length - 2);
            td.nextCellIndex = td.magistral.length - 2;
            td.isZones = false;
        }
    this->isMagistral = false;
   // console.log("create ", iter);
};