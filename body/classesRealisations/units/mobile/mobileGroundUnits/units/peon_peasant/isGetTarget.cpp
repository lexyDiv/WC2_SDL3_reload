#include "isTargetObjValide.cpp"
//=>selectAnAction

bool Peon_peasant::isGetTarget()
{

    if (this->targetData.unit ||
        (this->personalCaseDeep == 3 &&
         (this->wood ||
          this->gold)))
    {
        Array<Cell *> validUnitCells;
        for (int i = 0; i < this->cell->aroundCells.length; i++)
        {
            Cell *ac = this->cell->aroundCells.getItem(i);
            Unit *acgu = ac->groundUnit;
            if (this->isGetTargetLambda(ac))
            {
                if (acgu &&
                    acgu == this->targetData.unit)
                {
                    this->iNeedFreeWay = false;
                    this->isIgetMyTarget = true;
                    this->targetData.unit = acgu;
                    this->targetData.clicckedCell = ac;

                    return true;
                }
                else
                {
                    validUnitCells.push(ac);
                }
            }
        }

        if (validUnitCells.length)
        {
            int rand = intRand(0, validUnitCells.length);
            Cell *c = validUnitCells.getItem(rand);
            this->iNeedFreeWay = false;
            this->isIgetMyTarget = true;
            this->targetData.clicckedCell = c;
            this->targetData.unit = c->groundUnit;

            return true;
        }
    }

    if (!this->targetData.unit)
    {
        if (this->cell == this->targetData.clicckedCell ||
            // ( this->wayIndex == 1) ||
            (this->wayIndex == 1 && this->way.length &&
             this->way.getItem(0)->groundUnit && (!this->targetData.nextCell || this->personalCaseDeep == 3)))
        {
            this->iNeedFreeWay = false;
            this->isIgetMyTarget = true;
          //  console.log("get");
            return true;
        }
    }

    return false;

    ///////////////////////////////////////////////////////////////////////////////////////

    // Unit *to = this->targetData.unit;

    //     if (to)
    //     {
    //         if (to->canGiveTree)
    //         {
    //             Unit *valideTree = nullptr;
    //             for (int i = 0; i < this->cell->aroundCells.length; i++)
    //             {
    //                 Cell *cell = this->cell->aroundCells.getItem(i);
    //                 if (cell->groundUnit &&
    //                     cell->groundUnit->canGiveTree &&
    //                     !cell->groundUnit->lesorub)
    //                 {
    //                     if (cell->groundUnit == to)
    //                     {
    //                         this->iNeedFreeWay = false;
    //                         this->isIgetMyTarget = true;
    //                         return true;
    //                     }
    //                     else
    //                     {
    //                         valideTree = cell->groundUnit;
    //                     }
    //                 }
    //             }
    //             if (valideTree)
    //             {
    //                 this->targetData.unit = valideTree;
    //                 this->iNeedFreeWay = false;
    //                 this->isIgetMyTarget = true;
    //                 return true;
    //             }
    //         }
    //         else
    //         {
    //             for (int i = 0; i < this->cell->aroundCells.length; i++)
    //             {
    //                 Cell *cell = this->cell->aroundCells.getItem(i);
    //                 if (cell->groundUnit && cell->groundUnit == to)
    //                 {
    //                     this->iNeedFreeWay = false;
    //                     this->isIgetMyTarget = true;
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
    //     else
    //     {
    //         //                 if (this->focus) {
    //         //     console.log("-----------------------------");
    //         //     console.log("!this->wayIndex = " + to_string(this->wayIndex == 1));
    //         //     console.log("!this->targetData.unit = " + to_string(!this->targetData.unit));
    //         //     console.log("!this->targetData.nextCell = " + to_string(!this->targetData.nextCell));
    //         // }
    //         if (this->cell == this->targetData.clicckedCell ||
    //            // ( this->wayIndex == 1) ||
    //             (this->wayIndex == 1 && this->way.length &&
    //              this->way.getItem(0)->groundUnit) )
    //         {
    //             this->iNeedFreeWay = false;
    //             this->isIgetMyTarget = true;
    //             return true;
    //         }
    //     }

    // return false;
};