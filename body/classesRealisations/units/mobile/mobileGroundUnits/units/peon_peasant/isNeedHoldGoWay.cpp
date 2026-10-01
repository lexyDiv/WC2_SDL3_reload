#include "orderOnWayControl.cpp"
//=>out

bool isLoop(Unit *self)
{

    Unit *unit1 = self;
    Unit *unit2 = unit1->nextCell && unit1->nextCell->groundUnit ? unit1->nextCell->groundUnit : nullptr;
    Unit *unit3 = unit2 && unit2->nextCell && unit2->nextCell->groundUnit ? unit2->nextCell->groundUnit : nullptr;
    Unit *unit4 = unit3 && unit3->nextCell && unit3->nextCell->groundUnit ? unit3->nextCell->groundUnit : nullptr;
    Unit *unit5 = unit4 && unit4->nextCell && unit4->nextCell->groundUnit ? unit4->nextCell->groundUnit : nullptr;

    if (unit3 != self && unit4 != self && unit5 != self)
    {
        return false;
    }
    return true;
};

////////////////////////////////////////////////////////////////////////////////

bool Peon_peasant::isNeedHoldGoWay()
{
    Cell *nc = this->nextCell;
    Unit *ncgu = nc ? nc->groundUnit : nullptr;

    if (ncgu)
    {

        //  console.log("------------------------------------------");
        // console.log("count th = ", this->thd->count);
        // console.log(this->persNum); // =>2

        TargetData &td = this->targetData;

        this->isLoopNextCellUnit = isLoop(this);

        int needHoldIndex = !this->iNeedFreeWay ? 5 : 5;

        if (this->needHolTimer >= this->wayIndex * needHoldIndex)
        {
            this->needHolTimer = 0;
            this->iNeedFreeWay = false;

            return false;
        }

        if (ncgu && ncgu->type == "life" && !ncgu->isActive //&& ncgu->profession == ""
        )
        {
            this->targetData.forNeedFreeWayCount++;
            if (this->targetData.forNeedFreeWayCount >= 3)
            {
                this->iNeedFreeWay = this->personalCaseDeep != 3 ? true : false; // <<<<<<<<<<<<< ON 1/3
                this->targetData.forNeedFreeWayCount = 0;
            }
        }

        //   if (this->iNeedFreeWay &&   // => down
        //      // ncgu &&
        //       ncgu->type == "life" &&
        //       !ncgu->inFight
        //       // && !ncgu->iNeedFreeWay
        //       && !this->isLoopNextCellUnit)
        //   {
        //       return true;
        //   }

        // if (
        //     gu &&
        //     ncgu->isActive &&
        //     ((this->wayIndex > 5 || this->targetData.nextCell) && this->way.length)

        //     && (ncgu->inSave ||
        //         (this->blockedData.isBlocked) ||
        //         ((ncgu->way.length || ncgu->wayIndex || !ncgu->isPotentialWayComplite || !ncgu->orderOnWay.isComplite)// &&

        //         )
        //         ) &&
        //     !this->isLoopNextCellUnit)
        // {
        //     return true;
        // }

        //  bool isMyFrontalCollision = ncgu->nextCell &&
        //  ncgu->nextCell->groundUnit &&
        //  ncgu->nextCell->groundUnit->persNum == this->persNum;

        //  bool isNcguFrontalCollision = ncgu->ncgu->nextCell &&
        //  ncgu->nextCell->groundUnit &&
        //  ncgu->nextCell->groundUnit->persNum == this->persNum;
        // bool isNcguFrontalCollision = ncgu->nextCell->groundUnit->persNum == this->persNum;

        //   console.log("ncgu->isActive = ", ncgu->isActive);
        //   console.log("this->wayIndex > 5 = ", this->wayIndex > 5);
        //   console.log("this->isLoopNextCellUnit = ", this->isLoopNextCellUnit);
        //   console.log("ncgu->orderOnWay.isComplite = ", ncgu->orderOnWay.isComplite);
        // console.log("isFrontalCollision = ", isMyFrontalCollision);

        //   if (thd->count == 212 && this->persNum == 2) {
        //       console.log("persNum = ", this->persNum);
        //       console.log("ncgu->isActive = ", ncgu->isActive);
        //       console.log("this->wayIndex > 5 = ", this->wayIndex > 5);
        //       console.log("this->isLoopNextCellUnit = ", this->isLoopNextCellUnit);
        //       console.log("ncgu->orderOnWay.isComplite = ", ncgu->orderOnWay.isComplite);
        //   }

        // 8 ok // 7 ok => without magistral & without free
        if (
            ncgu->type == "life" &&
            (
                (this->iNeedFreeWay && !this->isLoopNextCellUnit) ||

             (
                ncgu->isActive 
                &&
              (
                !this->isLoopNextCellUnit ||
               !ncgu->isPotentialWayComplite
              ) 
              &&
              (
                !ncgu->isPotentialWayComplite ||
               (ncgu->way.length && (td.nextCell || !ncgu->needHolTimer || this->wayTakts > 5))
              )
             )

            )

        )
        {
            //    if (thd->count == 212 && this->persNum == 2) {
            //     console.log("hold");
            //    }
            return true;
        }

        // if (this->persNum == 1) {
        //    if (thd->count == 212 && this->persNum == 2) {
        //     console.log("no hold");
        //    }
        // }
    }

    return false;
}