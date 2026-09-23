#include "isNeedFreeWay.cpp"
//=>out

void MobileGroundUnit::stepToTheSide()
{

    if (
        !this->isBlocked)
    {

        Unit *ncgu = this->nextCell->groundUnit;
        Unit *valU = nullptr;
        if (ncgu && ncgu->profession == "" && !ncgu->isActive && !ncgu->isBlockedd(ncgu) && ncgu->type == "life")
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
                        cu->profession == "" &&
                        !cu->isActive &&
                        cu->type == "life" &&
                        !cu->isBlockedd(cu))
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

            valU->orderOnWay.go(validCells.getItem(rand), 3);
            valU->isActive = true;


        }
    }

    /////////////////////////////////////////////////
    else
    {

        if (this->targetUnit &&
            this->targetUnit->hp &&
            this->targetUnit->cell &&
            this->targetUnit->iNeedFreeWay &&
            this->targetUnit->targetData.clicckedCell == this->freeCell)
        {
            return;
        }

        if (this->targetData.blockedFreeWayHoldTimer)
        {
            this->targetData.blockedFreeWayHoldTimer--;
            return;
        }

        Array<Cell *> scs;
        scs.push(this->cell);
        int count = 0;
        Unit *targetUnit = nullptr;

        for (int i = this->way.length - 1, k = this->way.length - 2; k >= 0; k--, i--)
        {
            Cell *currentCell = this->way.getItem(i);
            Unit *currentCellGU = currentCell->groundUnit;
            Cell *nextCell = this->way.getItem(k);
            Unit *nextCellGU = nextCell->groundUnit;

            if ((!nextCellGU ||
                 (nextCellGU->isActive && (!nextCellGU->orderOnWay.isComplite ||
                                           nextCellGU->way.length))) &&
                currentCellGU &&
                currentCellGU->type == "life" &&
                !currentCellGU->isActive &&
                currentCellGU->profession == "")
            {
                targetUnit = currentCellGU;
                break;
            }
        }

        if (targetUnit)
        {
            Array<Cell *> validCells;
            targetUnit->cell->panicCells.forEach([&validCells](Cell *c)
                                                 {
                if (!c->groundUnit) {
                    validCells.push(c);
                } });

            if (validCells.length)
            {
                count++;
                int rand = intRand(0, validCells.length);

                targetUnit->orderOnWay.go(validCells.getItem(rand), 3);
                targetUnit->isActive = true;
                this->targetData.blockedFreeWayHoldTimer = 15;
            }
        }
        else
        {

            this->thd->createCount += 0.001;
            Cell *freeCell = nullptr;
            Array<Cell *> expCells;
            expCells.push(this->cell);
            this->cell->thwd.getItemPtr(this->thd->num)->createCountData = this->thd->createCount;

            // targetUnit = nullptr;
            for (int i = 0; i < this->cell->aroundCells.length; i++)
            {
                Cell *c = this->cell->aroundCells.getItem(i);
                Unit *cgu = c->groundUnit;
                if (cgu->type == "life" && cgu->profession == "" && !cgu->isActive)
                {
                    targetUnit = cgu;
                    break;
                }
            }

            if (targetUnit)
            {
                while (!freeCell)
                {

                    MinDataC md;
                    expCells.forEach([&md, this](Cell *c, int i)
                                     {

                       PointF pointThis = {x : this->cell->x, y : this->cell->y};
                       PointF pointLM = {x : c->x, y : c->y};
                       Delta delta = getDeltas(&pointThis, &pointLM);
                       double dis = getDis(&delta);

                       if (!md.cell || md.dis < dis) {
                        md.cell = c;
                        md.i = i;
                        md.dis = dis;
                       } });

                    Cell *mdc = md.cell;

                    expCells.splice(md.index, 1);
                    mdc->thwd.getItemPtr(this->thd->num)->createCountData = this->thd->createCount;

                    if (!mdc->groundUnit)
                    {
                        freeCell = mdc;
                    }
                    else
                    {
                        mdc->aroundCells.forEach([&expCells, this](Cell *c)
                                                 {
             Unit *cgu = c->groundUnit;                                       
        if (c->thwd.getItemPtr(this->thd->num)->createCountData != this->thd->createCount &&
            (!cgu || (cgu->type == "life" && cgu->profession == ""))
        )
                {
                        c->thwd.getItemPtr(this->thd->num)->createCountData = this->thd->createCount;
                        expCells.push(c);
                                                    
                    } });
                    }
                }
                targetUnit->orderOnWay.go(freeCell);
                targetUnit->isActive = true;
                targetUnit->targetData.blockedFreeWayHoldTimer = 15;
                this->targetData.blockedFreeWayHoldTimer = 15;
                this->targetUnit = targetUnit;
                this->freeCell = freeCell;
            }
        }
    }
}