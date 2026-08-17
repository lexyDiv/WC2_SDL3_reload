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

            Cell *nextCell = this->way.getItem(this->wayIndex - 1);

            bool isNeedHold = this->isNeedHoldGoWay(nextCell);
            if (this->isNextCellFreeToGoWay(nextCell) && !isNeedHold)
            {
                this->holdWayCount = 0;
                this->wayIndex--;
                this->x = this->cell->x;
                this->y = this->cell->y;
                double saveSpeedTale = this->speedTale;
                this->getDeltasXY(nextCell);
                this->cell->groundUnit = nullptr;
                this->cell = nextCell;
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
                this->stendOnCellWait();
            }
            else
            {
                if (this->preTargetCell)
                {

                    if (this->iNeedFreeWay)
                    {
                        // console.log("poshel na huy!");
                        this->stendOnCellWait();
                    }
                    else
                    {
                        this->stendOnCell();
                        this->targetObj.unit = nullptr;
                        if (this->profession != "")
                        {
                            this->updateCurrentTarget();
                            return;
                        }
                        this->orderOnWay.cell = this->preTargetCell;
                        this->orderOnWay.isComplite = false;
                    }
                }
            }
        }
        else
        {
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
    }
};