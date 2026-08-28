#include "isNextCellFreeToGoWay.cpp"
//=>out

void MobileGroundUnit::orderOnWayControl()
{
    if (!this->orderOnWay.isComplite)
    {
        Cell *oCell = this->orderOnWay.cell;
        Cell *finishCell = this->way.length ? this->way.getItem(0) : nullptr;
        Unit *tarObj = this->targetObj.unit ? this->targetObj.unit : nullptr;
        if (!this->cell ||
            (oCell->plane != this->cell->plane) ||
            (oCell->groundUnit == this) ||
            (finishCell == oCell) ||
            (tarObj && tarObj == oCell->groundUnit && this->way.length) || this->isBlockedd(this))
        {

            this->orderOnWay.isComplite = true;
            return;
        }

        if (this->isPotentialWayComplite)
        {
            this->getCurrentTarget(oCell);
            this->orderOnWay.isComplite = true;
        }
        this->iNeedFreeWay = false;
       // console.log("here mmmmmm");
    }
};