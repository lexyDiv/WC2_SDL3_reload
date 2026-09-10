#include "isNeedFreeWay.cpp"
//=>out

void MobileGroundUnit::stepToTheSide()
{
    if (!this->isBlocked)
    {
        Unit *ncgu = this->nextCell->groundUnit;
        Array<Unit *> units;
        if (ncgu && !ncgu->isActive && ncgu->profession == "")
        {
            units.push(ncgu);
        }
        Array<Cell *> scs;
        scs.push(this->nextCell);
        scs.push(this->cell);

        scs.forEach([&units, this](Cell *c)
                    { c->aroundCells.forEach([&units, this](Cell *cell)
                                             {
            Unit *cgu = cell->groundUnit;
            if (cgu && !cgu->isActive && cgu != this && cgu->type == "life") {
                 units.push(cgu);
            } }); });

        Array<Cell *> validCells;

        this->cell->panicCells.forEach([&validCells](Cell *c)
                                       {
                if (!c->groundUnit) {
                    validCells.push(c);
                } });

        if (validCells.length)
        {
            units.forEach([&validCells](Unit *u)
                          {
                int rand = intRand(0, validCells.length);
                u->orderOnWay.go(validCells.getItem(rand));
                u->metka = true;
                u->isActive = true; });
        }
    }
    else
    {
    }
}