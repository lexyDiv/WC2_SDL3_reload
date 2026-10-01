#include "isNeedFreeWay.cpp"
//=>out

void MobileGroundUnit::stepToTheSide()
{

    if (this->focus)
    {
        console.log("--------------------------------------------------------------------");
    }

    // if (
    //    // !this->isBlocked
    //    !this->blockedData.isBlocked
    // )
    // {

    // if (this->focus)
    // {
    //     console.log("easy");
    // }

    Unit *ncgu = this->nextCell->groundUnit;
    Unit *valU = nullptr;
    // valU = nullptr;

    if (ncgu &&
        // ncgu->profession == "" &&

        !ncgu->isActive &&
        ncgu->type == "life" &&
        !ncgu->inSave &&
        !ncgu->blockedCheck(ncgu).isBlocked // !ncgu->isBlockedd(ncgu)
    )
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
                if (cu &&
                    cu != this &&
                    // (cu->profession == "" || cu->blockedCheck(cu).isBlocked) &&
                    // ncgu->profession == "" &&
                    !cu->isActive &&
                    !cu->inSave &&
                    cu->type == "life" &&
                    !cu->blockedCheck(cu).isBlocked // !cu->isBlockedd(cu)
                )
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
        // if (this->focus)
        // {
        //     console.log("easy 2");
        // }
        // this->targetData.specialFreeG0 = false; // ?????????????????????????????????????????????
        int rand = intRand(0, validCells.length);

        if (valU->profession != "")
        {
            valU->orderOnWay.go(valU->profession, 200);
            // if (this->focus) {
            //     console.log("in step 1");
            // }
        }
        else
        {
            valU->orderOnWay.go(validCells.getItem(rand), 3);
            //             if (this->focus) {
            //     console.log("in step 2");
            // }
        }
        // valU->orderOnWay.go(validCells.getItem(rand), 3);
        valU->isActive = true;
    }
    //////////////////////////////////////////////////////////////////////////////////// => HARD
    else if (this->blockedData.isBlocked && this->blockedData.type == 'f' && this->orderOnWay.specialFreeG0 && this->needHolTimer)
    {
        // this->iNeedFreeWay = false;

        // if (this->focus)
        // {
        //     console.log("hard");
        // }

        // Unit *tu = nullptr;
        MinData md;
        this->cell->maxAroundCells.forEach([&md, this](Cell *c, int i)
                                           {
                Unit *cu = c->groundUnit;
   
                if (cu && c->plane == this->cell->plane) {
                Unit *tu = cu->type == "life" &&
                 !cu->isActive &&
                 !cu->inSave &&
                 cu->cell
                  ? cu : nullptr;
                if (tu) {

                     bool ok = false;

                     for (int i = 0; i < c->aroundCells.length; i++) {
                        Cell *cac = c->aroundCells.getItem(i);
                        if (!cac->groundUnit) {
                            ok = true;
                            break;
                        }
                     }

                if (ok) {
                   double dis = this->cell->maxAroundCellsDis.getItem(i);
                   if (!md.unit || md.dis > dis) {
                    md.unit = tu;
                    md.dis = dis;
                   }
                     }

                   }
                } });

        Unit *validU = md.unit;
        // this->valU = validU;
        if (validU)
        {
            for (int i = 0; i < validU->cell->panicCells.length; i++)
            {
                Cell *pc = validU->cell->panicCells.getItem(i);
                if (!pc->groundUnit)
                {
                    if (validU->profession != "")
                    {
                        validU->orderOnWay.go(validU->profession, 200);
                        //                         if (this->focus) {
                        //     console.log("in step 3");
                        // }
                    }
                    else
                    {
                        validU->orderOnWay.go(pc, 3);
                        //                         if (this->focus) {
                        //     console.log("in step 4");
                        // }
                    }
                    // validU->orderOnWay.go(pc, 3);
                    validU->isActive = true;
                    break;
                }
            }
            // if (this->focus)
            // {
            //     console.log("hard 2");
            // }
        }
        else
        {
            this->targetData.specialFreeG0 = false;
            this->iNeedFreeWay = false;
            this->orderOnWay.go(this->cell);
            // this->targetData.clear();
            // if (this->focus)
            // {
            //     console.log("hard 3");
            // }
        }
    }
    else if (!this->needHolTimer && !this->targetData.specialFreeG0)
    {
        this->iNeedFreeWay = false;
        this->orderOnWay.go(this->cell);

            //             if (this->focus) {
            //     console.log("hard final");
            // }
    }
}