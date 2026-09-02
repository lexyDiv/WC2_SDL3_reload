#include "getConor.cpp"
//=>isNeedHoldGoWay

void MobileGroundUnit::goWay()
{
    if (!this->wayTakts)
    {
        if (this->isPotentialWayComplite &&
            this->way.length &&
            this->wayIndex > 0)
        {

            Cell *nc = this->way.getItem(this->wayIndex - 1);
            this->nextCell = nc;
            int flipCellIndex = this->wayIndex - 2;
            this->flipCell =flipCellIndex >= 0 ? this->way.getItem(flipCellIndex) : nullptr;
            bool isNeedHold = this->isNeedHoldGoWay(nc);
            if (this->isNextCellFreeToGoWay(nc) && !isNeedHold)
            {
                this->holdWayCount = 0;
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
                    this->x += cos(this->conor) * saveSpeedTale;
                    this->y += sin(this->conor) * saveSpeedTale;
                }

                this->drawIndexY = this->y;
            }
            else if (isNeedHold)
            {
                this->needHolTimer++;
                this->stendOnCellWait();
                if (this->needHolTimer % 10 == 0 && !isTargetObjValide()) {
                    updateCurrentTarget();
                }
            }
            else
            {
                   
                if (
                   // this->preTargetCell
                   this->targetData.clicckedCell
                )
                {

                    if (this->iNeedFreeWay)
                    {
                        // console.log("poshel na huy!");
                        this->stendOnCellWait();
                    }
                    else
                    {
                        this->stendOnCell();
                        this->targetData.unit = nullptr;
                        if (this->profession != "")
                        {

                            return;
                        }
                        this->orderOnWay.cell = this->targetData.clicckedCell; //this->preTargetCell;
                        this->orderOnWay.isComplite = false;
                       
                    }
                }
            }
        }
        else
        {
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
        this->holdWayCount = 0;
    } else {
        this->flipCell = nullptr;
    }
};