#include "isTargetObjValide.cpp"
//=>selectAnAction

bool Peon_peasant::isGetTarget()
{
    Unit *to = this->targetData.unit;
    if (!this->needHolTimer &&
        this->targetData.clicckedCell && !this->wayTakts &&
        this->way.length &&
        this->wayIndex <= 5 &&
        this->isPotentialWayComplite)
    {

        if (to)
        {
            if (to->name == "tree")
            {
                Unit *valideTree = nullptr;
                for (int i = 0; i < this->cell->aroundCells.length; i++)
                {
                    Cell *cell = this->cell->aroundCells.getItem(i);
                    if (cell->groundUnit &&
                        cell->groundUnit->name == "tree" &&
                        !cell->groundUnit->lesorub)
                    {
                        if (cell->groundUnit == to)
                        {
                            this->iNeedFreeWay = false;
                            this->isIgetMyTarget = true;
                            return true;
                        }
                        else
                        {
                            valideTree = cell->groundUnit;
                        }
                    }
                }
                if (valideTree)
                {
                    this->targetData.unit = valideTree;
                    this->iNeedFreeWay = false;
                    this->isIgetMyTarget = true;
                    return true;
                }
            }
            else
            {
                for (int i = 0; i < this->cell->aroundCells.length; i++)
                {
                    Cell *cell = this->cell->aroundCells.getItem(i);
                    if (cell->groundUnit && cell->groundUnit == to)
                    {
                        this->iNeedFreeWay = false;
                        this->isIgetMyTarget = true;
                        return true;
                    }
                }
            }
        }
        else
        {
            if (this->cell == this->targetData.clicckedCell || 
                (this->wayIndex == 1 &&
                 this->way.getItem(0)->groundUnit))
            {
                this->iNeedFreeWay = false;
                this->isIgetMyTarget = true;
                return true;
            }
        }
    }
    return false;
};