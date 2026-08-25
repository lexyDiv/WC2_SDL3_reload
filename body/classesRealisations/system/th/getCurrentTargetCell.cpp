#include "exploreNewCellAndAddToOpenArr.cpp"
//=>isBlocked

void ThData::getCurrentTargetCell(Unit *unit) {
        this->procCurr += 0.0001;
        
    Array<Cell *> acs;
    Array<Cell *> freeCells;

    unit->preTargetCell->thwd.getItemPtr(this->num)->procCurr = this->procCurr;
    Unit *gu = unit->preTargetCell->groundUnit;
    if (!gu)
    {
        acs.push(unit->preTargetCell);
    }
    else
    {
        if (!gu->isBlockedd(unit))
        {
            //  console.log("here");
            unit->targetCell = gu->cell;
            return;
        }
        else
        {
            if (gu->contactCells.length)
            {
                gu->contactCells.forEach([this, &acs](Cell *cell)
                                                                      {
            //cell->procCurr2 = this->gf->procCurr2;
            cell->thwd.getItemPtr(this->num)->procCurr = this->procCurr;
            acs.push(cell); });
            }
            else
            {
                gu->cell->aroundCells.forEach([this, &acs](Cell *cell)
                                                                           {
           // cell->procCurr2 = this->gf->procCurr2;
           cell->thwd.getItemPtr(this->num)->procCurr = this->procCurr;
            acs.push(cell); });
            }
        }
    }
    int iter = 0;

    while (iter < 1000)
    {
        Array<Cell *> newAcs;
        for (int i = 0; i < acs.length; i++)
        {
            Cell *c = acs.getItem(i);
            Unit *cgu = c->groundUnit;
            if ((!cgu || cgu->way.length ||
                 (unit->profession == "lesorub" && cgu->name == "tree")) &&
                (!isBlocked(c, unit) || c == unit->preTargetCell))
            {
                freeCells.push(c);
            }
            c->aroundCells.forEach([this, &newAcs](Cell *cl)
                                   {
              if (//cl->procCurr2 != this->gf->procCurr2
                cl->thwd.getItemPtr(this->num)->procCurr != this->procCurr
            ) {
                cl->thwd.getItemPtr(this->num)->procCurr = this->procCurr;
                newAcs.push(cl);
              } });
        }
        acs.copy(newAcs);
        if (freeCells.length)
        {
            double dis = 10000000;
            int index = 0;
            Cell *tc = nullptr;
            if (gu)
            {
                tc = gu->cell;
            }
            else
            {
                tc = unit->preTargetCell;
            }
            for (int i = 0; i < freeCells.length; i++)
            {
                Cell *fc = freeCells.getItem(i);
                // console.log(to_string(freeCells.length));
                Delta delta = getDeltas(
                    {x : fc->x, y : fc->y},
                    {x : tc->x, y : tc->y});
                double currentDis = getDis(delta);
                if (dis > currentDis)
                {
                    dis = currentDis;
                    index = i;
                }
            }
            unit->targetCell = freeCells.getItem(index);
            return;
        }
    }
    unit->targetCell = unit->preTargetCell;
};