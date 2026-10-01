#include "getConor.cpp"
//=>isNeedHoldGoWay

void MobileGroundUnit::goWay()
{
    if (!this->wayTakts)
    {

        //  if (this->focus) {
        //     console.log("");
        //   }

       // this->blockedData = this->blockedCheck(this); // this->isBlocked = this->isBlockedd(this);
        // if (!this->blockedData.isBlocked || (this->blockedData.isBlocked && this->blockedData.type == 'c')) {
        //     this->targetData.specialFreeG0 = false;
        // }
        if ( // this->isPotentialWayComplite &&
            this->wayIndex > 0)
        {

            this->nextCell = this->way.getItem(this->wayIndex - 1);
            
            int flipCellIndex = this->wayIndex - 2;
            this->flipCell = flipCellIndex >= 0 ? this->way.getItem(flipCellIndex) : nullptr;
            bool isNeedHold = this->isNeedHoldGoWay();
            bool isCrox = this->crox();
            if (this->isNextCellFreeToGoWay(this->nextCell) && !isNeedHold && !isCrox && !this->inSave)
            {
                this->targetData.specialFreeG0 = false;
                this->needHolTimer = 0;
                this->wayIndex--;
                this->x = this->cell->x;
                this->y = this->cell->y;
                double saveSpeedTale = this->speedTale;
                this->getDeltasXY(this->nextCell);
                this->cell->groundUnit = nullptr;
                this->cell = this->nextCell;
                this->nextCell = this->wayIndex ? this->way.getItem(this->wayIndex - 1) : nullptr;
                this->cell->groundUnit = this;
                this->isGetMyCell = false;
                this->iAmHere();

                if (saveSpeedTale)
                {
                    this->x += cos(this->conor) * saveSpeedTale; // => ZARANIE NEED !!!! (sin & cos)
                    this->y += sin(this->conor) * saveSpeedTale;
                }

                this->drawIndexY = this->y;
                this->freeGoWayTimer++;
                if (this->freeGoWayTimer == 3)  //<= ///////////////////////??????????????????????????????????????????????????
                {
                    this->freeGoWayTimer = 0;
                    this->iNeedFreeWay = false;
                }

                if (this->targetData.nextCell)
                {
                    this->checkNextMagistralCell();
                   // console.log("here");
                }

                if (!this->wayIndex && this->targetData.nextCell)
                {
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
            else if (isCrox)
            {
                this->stendOnCellWait();
    //                 if (this->persNum == 1) {
    //     console.log("i have crox");
    // }
            }
            else if (isNeedHold)
            {



                if (this->iNeedFreeWay)
                {
                   // this->stepToTheSide();
                }

                this->needHolTimer++;
                this->freeGoWayTimer = 0;
                this->stendOnCellWait();
                if (this->needHolTimer % 20 == 0 && !isTargetObjValide())
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

            if (!this->wayIndex && this->targetData.isNeedMagistralFinish)
            {
                this->targetData.isNeedMagistralFinish = false;
                if (this->profession != "")
                {
                    this->orderOnWay.go(this->profession, this->personalCaseDeep);
                }
                else if (this->targetData.clicckedCell)
                {
                    this->orderOnWay.go(this->targetData.clicckedCell, this->personalCaseDeep);
                }
            } else {


            this->iNeedFreeWay = false;
            this->nextCell = nullptr;
            this->flipCell = nullptr;
            this->stendOnCell();

        //    if (this->persNum == 2) {
              console.log("OFF in goWay");
        //    }

            }
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