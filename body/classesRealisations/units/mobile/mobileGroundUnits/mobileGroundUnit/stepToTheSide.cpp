#include "isNeedFreeWay.cpp"
//=>out

void MobileGroundUnit::stepToTheSide()
{

    // if (this->focus)
    // {
    //     console.log("--------------------------------------------------------------------");
    // }

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
        // this->targetData.specialFreeG0 = false; // ?????????????????????????????????????????????
        int rand = intRand(0, validCells.length);

        // if (valU->profession != "") {
        //     valU->orderOnWay.go(valU->profession);
        //     // if (this->focus) {
        //     //     console.log("in step 1");
        //     // }
        // } else {
        //     valU->orderOnWay.go(validCells.getItem(rand), 3);
        //     //             if (this->focus) {
        //     //     console.log("in step 2");
        //     // }
        // }
        valU->orderOnWay.go(validCells.getItem(rand), 3);
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
            //         if (validU->profession != "")
            //         {
            //             validU->orderOnWay.go(validU->profession);
            // //                         if (this->focus) {
            // //     console.log("in step 3");
            // // }
            //         }
            //         else
            //         {
            //             validU->orderOnWay.go(pc, 3);
            // //                         if (this->focus) {
            // //     console.log("in step 4");
            // // }
            //         }
                    validU->orderOnWay.go(pc, 3);
                    validU->isActive = true;
                    break;
                }
            }
        }
        else
        {
            this->targetData.specialFreeG0 = false;
           // this->iNeedFreeWay = false;
        }
    }

    else if (!this->orderOnWay.specialFreeG0)
    {
       // this->iNeedFreeWay = false;
        // this->stendOnCell();
        //             if (this->focus) {
        //     console.log("in hard");
        // }
    }
    // }
    // else if (
    //     this->blockedData.isBlocked //this->isBlocked
    //      && !this->targetData.specialFreeG0)
    // {
    //     this->iNeedFreeWay = false;
    // }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // else if (this->targetData.specialFreeG0
    //          //  && this->isBlocked
    // )
    // {

    //     if (this->focus)
    //     {
    //         console.log("hard");
    //     }

    //     int caseBlock = 0;

    //     // if (this->targetUnit &&
    //     //     this->targetUnit->hp &&
    //     //     this->targetUnit->cell &&
    //     //     this->targetUnit->iNeedFreeWay &&
    //     //     this->targetUnit->targetData.clicckedCell == this->freeCell)
    //     // {
    //     //     return;
    //     // }

    //     // if (this->focus)
    //     // {
    //     //     console.log("hard 2");
    //     // }

    //     // if (this->targetData.blockedFreeWayHoldTimer)
    //     // {
    //     //     this->targetData.blockedFreeWayHoldTimer--;
    //     //     return;
    //     // }

    //     // if (this->focus)
    //     // {
    //     //     console.log("hard 3");
    //     // }

    //     // Array<Cell *> scs;
    //     // scs.push(this->cell);
    //     // int count = 0;
    //     // Unit *targetUnit = nullptr;

    //     // for (int i = this->way.length - 1, k = this->way.length - 2; k >= 0; k--, i--)
    //     // {
    //     //     Cell *currentCell = this->way.getItem(i);
    //     //     Unit *currentCellGU = currentCell->groundUnit;
    //     //     Cell *nextCell = this->way.getItem(k);
    //     //     Unit *nextCellGU = nextCell->groundUnit;

    //     //     if ((!nextCellGU ||
    //     //          (nextCellGU->isActive && (!nextCellGU->orderOnWay.isComplite ||
    //     //                                    nextCellGU->way.length))) &&
    //     //         currentCellGU &&
    //     //         currentCellGU->type == "life" &&
    //     //         !currentCellGU->inSave &&
    //     //         !currentCellGU->isActive //&&
    //     //                                  //  currentCellGU->profession == ""
    //     //     )
    //     //     {
    //     //         targetUnit = currentCellGU;
    //     //         break;
    //     //     }
    //     // }

    //     // if (targetUnit)
    //     // {
    //     //     // if (this->focus)
    //     //     // {
    //     //     //     console.log("hard 4");
    //     //     // }
    //     //     Array<Cell *> validCells;
    //     //     targetUnit->cell->panicCells.forEach([&validCells](Cell *c)
    //     //                                          {
    //     //         if (!c->groundUnit) {
    //     //             validCells.push(c);
    //     //         } });

    //     //     if (validCells.length)
    //     //     {
    //     //         count++;
    //     //         int rand = intRand(0, validCells.length);

    //     //         targetUnit->orderOnWay.go(validCells.getItem(rand), 3);
    //     //         targetUnit->isActive = true;
    //     //         this->targetData.blockedFreeWayHoldTimer = 15;
    //     //     }
    //     //     else
    //     //     {
    //     //        // this->iNeedFreeWay = false;
    //     //     //                 if (this->focus)
    //     //     // {
    //     //     //     console.log("here 2");
    //     //     // }
    //     //     }
    //     // }
    //     // else
    //     // {

    //     //     // if (this->focus)
    //     //     // {
    //     //     //     console.log("hard 5");
    //     //     // }
    //     //     this->thd->createCount += 0.001;
    //     //     Cell *freeCell = nullptr;
    //     //     Array<Cell *> expCells;
    //     //     expCells.push(this->cell);
    //     //     this->cell->thwd.getItemPtr(this->thd->num)->createCountData = this->thd->createCount;

    //     //     // targetUnit = nullptr;
    //     //     for (int i = 0; i < this->cell->aroundCells.length; i++)
    //     //     {
    //     //         Cell *c = this->cell->aroundCells.getItem(i);
    //     //         Unit *cgu = c->groundUnit;
    //     //         if (cgu->type == "life"
    //     //             // && cgu->profession == ""
    //     //             &&
    //     //             !cgu->inSave &&
    //     //             !cgu->isActive)
    //     //         {
    //     //             targetUnit = cgu;
    //     //             break;
    //     //         }
    //     //     }

    //     //     if (targetUnit)
    //     //     {

    //     //         // if (this->focus)
    //     //         // {
    //     //         //     console.log("hard 6");
    //     //         // }

    //     //         while (!freeCell)
    //     //         {

    //     //             MinDataC md;
    //     //             expCells.forEach([&md, this](Cell *c, int i)
    //     //                              {

    //     //                PointF pointThis = {x : this->cell->x, y : this->cell->y};
    //     //                PointF pointLM = {x : c->x, y : c->y};
    //     //                Delta delta = getDeltas(&pointThis, &pointLM);
    //     //                double dis = getDis(&delta);

    //     //                if (!md.cell || md.dis < dis) {
    //     //                 md.cell = c;
    //     //                 md.i = i;
    //     //                 md.dis = dis;
    //     //                } });

    //     //             Cell *mdc = md.cell;

    //     //             if (mdc)
    //     //             {
    //     //                 expCells.splice(md.index, 1);
    //     //                 mdc->thwd.getItemPtr(this->thd->num)->createCountData = this->thd->createCount;

    //     //                 if (!mdc->groundUnit)
    //     //                 {
    //     //                     freeCell = mdc;
    //     //                 }
    //     //                 else
    //     //                 {
    //     //                     mdc->aroundCells.forEach([&expCells, this](Cell *c)
    //     //                                              {
    //     //      Unit *cgu = c->groundUnit;
    //     // if (c->thwd.getItemPtr(this->thd->num)->createCountData != this->thd->createCount &&
    //     //     (!cgu || (cgu->type == "life" && !cgu->isActive && !cgu->inSave //&&
    //     //       //  && cgu->profession == ""
    //     //     ))
    //     // )
    //     //         {
    //     //                 c->thwd.getItemPtr(this->thd->num)->createCountData = this->thd->createCount;
    //     //                 expCells.push(c);

    //     //             } });
    //     //                 }
    //     //             }
    //     //             else
    //     //             {
    //     //                 break;
    //     //             }
    //     //         }
    //     //         if (freeCell)
    //     //         {
    //     //             //                     if (this->focus) {
    //     //             //     console.log("hard 7");
    //     //             // }
    //     //             targetUnit->orderOnWay.go(freeCell, 0, true);
    //     //             targetUnit->isActive = true;
    //     //             targetUnit->iNeedFreeWay = true;
    //     //            // targetUnit->freeSpetial = true;
    //     //             targetUnit->targetData.blockedFreeWayHoldTimer = 15;
    //     //             this->targetData.blockedFreeWayHoldTimer = 15;
    //     //            // this->targetUnit = targetUnit;
    //     //             this->freeCell = freeCell;
    //     //         }
    //     //         else
    //     //         {
    //     //           //  this->iNeedFreeWay = false;
    //     //     //                     if (this->focus)
    //     //     // {
    //     //     //     console.log("here 3");
    //     //     // }
    //     //         }
    //     //     }
    //     //     else
    //     //     {
    //     //        // this->iNeedFreeWay = false;
    //     //     //                 if (this->focus)
    //     //     // {
    //     //     //     console.log("here 4");
    //     //     // }
    //     //     }
    //     // }
    // }
}