#include "isNeedFreeWay.cpp"
//=>out

void MobileGroundUnit::stepToTheSide()
{
    if (!this->isBlocked)
    {
        Unit *ncgu = this->nextCell->groundUnit;
        // Array<Unit *> units;
        Unit *valU = nullptr;
        if (ncgu && !ncgu->isActive 
           // && ncgu->profession == ""
             && !ncgu->isBlockedd(ncgu))
        {
            valU = ncgu;
        }

        Array<Cell *> scs;
        scs.push(this->nextCell);
        scs.push(this->cell);

        // scs.forEach([&units, this](Cell *c)
        //             { c->aroundCells.forEach([&units, this](Cell *cell)
        //                                      {
        //     Unit *cgu = cell->groundUnit;
        //     if (cgu && !cgu->isActive && cgu != this && cgu->type == "life") {
        //          units.push(cgu);
        //     } }); });

        if (!valU)
        {
            for (int i = 0; i < scs.length; i++)
            {
                Cell *cell = scs.getItem(i);
                for (int k = 0; k < cell->aroundCells.length; k++)
                {
                    Cell *c = cell->aroundCells.getItem(k);
                    Unit *cu = c->groundUnit;
                    // if (this->focus && cu) {
                    //     console.log("c != t " + to_string(cu != this) + " !a " + to_string(!cu->isActive) + " p " + to_string(cu->profession == "") + " ib " + to_string(!cu->isBlockedd(cu)) + " p = " + to_string(cu->persNum));
                    // }
                    if (cu && cu != this && !cu->isActive && cu->profession == "" && !cu->isBlockedd(cu))
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
            // if (this->focus) {
            //     console.log("------------------------------------------------");
            // }
        }

        Array<Cell *> validCells;

        this->cell->panicCells.forEach([&validCells](Cell *c)
                                       {
                if (!c->groundUnit) {
                    validCells.push(c);
                } });

        // if (this->focus) {
        //     console.log("cells = " + to_string(validCells.length) + " valU = " + to_string((bool)valU));
        // }


        

        if (validCells.length && valU)
        {

            //  units.forEach([&validCells](Unit *u)
            //          {
            int rand = intRand(0, validCells.length);
            valU->orderOnWay.go(validCells.getItem(rand), 10);
            valU->metka = true;
            valU->isActive = true;
            // if (this->focus)
            // {
            //     console.log("go");
            // }
            // });
        }
    }
    else
    {
    }
}