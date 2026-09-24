#include "getConor.cpp"
//=>isNeedHoldGoWay

void MobileGroundUnit::goWay()
{
    if (!this->wayTakts)
    {

        //  if (this->focus) {
        //     console.log("");
        //   }

        this->isBlocked = this->isBlockedd(this);

        if ( // this->isPotentialWayComplite &&
            this->wayIndex > 0)
        {

            Cell *nc = this->way.getItem(this->wayIndex - 1);
            this->nextCell = nc;
            int flipCellIndex = this->wayIndex - 2;
            this->flipCell = flipCellIndex >= 0 ? this->way.getItem(flipCellIndex) : nullptr;
            bool isNeedHold = this->isNeedHoldGoWay();
            bool isCrox = this->crox();
            if (this->isNextCellFreeToGoWay(nc) && !isNeedHold && !isCrox && !this->inSave)
            {
                this->needHolTimer = 0;
                this->wayIndex--;
                this->x = this->cell->x;
                this->y = this->cell->y;
                double saveSpeedTale = this->speedTale;
                this->getDeltasXY(nc);
                this->cell->groundUnit = nullptr;
                this->cell = nc;
                this->cell->groundUnit = this;
                this->isGetMyCell = false;
                this->iAmHere();

                if (saveSpeedTale)
                {
                    this->x += cos(this->conor) * saveSpeedTale; // => ZARANIE NEED !!!! (sin & cos)
                    this->y += sin(this->conor) * saveSpeedTale;
                }

                this->drawIndexY = this->y;
                this->freeGoWayTimer ++;
                if (this->freeGoWayTimer == 3) {
                    this->freeGoWayTimer = 0;
                    this->iNeedFreeWay = false;
                }
            }
            else if (isCrox)
            {
                this->stendOnCellWait();
            }
            else if (isNeedHold)
            {
  
                if (this->iNeedFreeWay && this->nextCell->groundUnit 
                    && !this->nextCell->groundUnit->isActive
                   // && this->nextCell->groundUnit->profession == ""
                )
                {
                    this->stepToTheSide();
                }

                this->needHolTimer++;
                this->freeGoWayTimer = 0;
                this->stendOnCellWait();
                if (this->needHolTimer % 200 == 0 && !isTargetObjValide())
                {
                    updateCurrentTarget();
                    this->iNeedFreeWay = false;
                }
            }
            else
            {
                this->stendOnCell();
                if (this->orderOnWay.isComplite)
                {
                    if (this->profession != "")
                    {
                        this->orderOnWay.go(this->profession, this->personalCaseDeep);
                    }
                    else if (this->targetData.clicckedCell)
                    {
                        this->orderOnWay.go(this->targetData.clicckedCell, this->personalCaseDeep);
                    }
                }
            }
        }
        else
        {

            if (!this->freeSpetial) {
                this->iNeedFreeWay = false;
                
            }
            this->freeSpetial = false;
            this->nextCell = nullptr;
            this->flipCell = nullptr;
            this->stendOnCell();
        }
    }
    else if (this->wayTakts)
    {
        this->x += this->wayDeltaX;
        this->y += this->wayDeltaY;
        this->drawIndexY = this->y;
        this->wayTakts--;
        this->needHolTimer = 0;
    }
    else
    {
        this->flipCell = nullptr;
    }
};