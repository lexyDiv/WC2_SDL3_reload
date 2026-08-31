#include "holdTimerControl.cpp"
//=>out

void Peon_peasant::orderOnWayControl()
{

    //  if (!this->orderOnWay.isComplite) {
    //     if (this->orderOnWay.profession != "") {
    //         if (this->profession == this->orderOnWay.profession) {

    //         }
    //     }
    //  }

    if (!this->orderOnWay.isComplite)
    {
        Cell *oCell = this->orderOnWay.cell;
        Cell *finishCell = this->way.length ? this->way.getItem(0) : nullptr;
        Unit *tarObj = this->targetData.unit ? this->targetData.unit : nullptr;
        if (!this->cell ||
            (oCell->plane != this->cell->plane) ||
            (oCell->groundUnit == this) ||
            (finishCell == oCell) ||
            (tarObj && tarObj == oCell->groundUnit && this->way.length) || this->isBlockedd(this))
        {

            this->orderOnWay.isComplite = true;
            return;
        }

            this->getCurrentTarget(oCell);
            this->orderOnWay.isComplite = true;
    }
};