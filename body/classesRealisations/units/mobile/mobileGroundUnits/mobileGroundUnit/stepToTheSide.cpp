#include "isNeedFreeWay.cpp"
//=>out

void MobileGroundUnit::stepToTheSide()
{
    if (!this->isBlocked)
    {
        Unit *ncgu = this->nextCell->groundUnit;
        Unit *valU = nullptr;
        if (ncgu && !ncgu->isActive 
             && !ncgu->isBlockedd(ncgu))
        {
            valU = ncgu;
        }

        Array<Cell *> scs;
        scs.push(this->nextCell);
        scs.push(this->cell);

        if (!valU)
        {
            for (int i = 0; i < scs.length; i++)
            {
                Cell *cell = scs.getItem(i);
                for (int k = 0; k < cell->aroundCells.length; k++)
                {
                    Cell *c = cell->aroundCells.getItem(k);
                    Unit *cu = c->groundUnit;
                    if (cu && cu != this && !cu->isActive && cu->type == "life"
                         && !cu->isBlockedd(cu))
                    {
                        valU = cu;
                        break;
                    }
                }
                if (valU)
                {
                    break;
                }
            }
        }

        Array<Cell *> validCells;

        this->cell->panicCells.forEach([&validCells](Cell *c)
                                       {
                if (!c->groundUnit) {
                    validCells.push(c);
                } });


        if (validCells.length && valU)
        {
            int rand = intRand(0, validCells.length);
            valU->orderOnWay.go(validCells.getItem(rand), 10);
            valU->metka = true;
            valU->isActive = true;
        }
    }
    else
    {
    }
}