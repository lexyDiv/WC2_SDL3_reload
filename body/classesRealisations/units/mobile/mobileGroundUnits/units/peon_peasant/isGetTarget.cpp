#include "isTargetObjValide.cpp"
//=>selectAnAction

bool Peon_peasant::isGetTarget()
{
    //console.log("here");
    Unit *to = this->targetData.unit;
    if (                 ! this->holdWayCount &&
       // this->targetCell // &&
       this->targetData.clicckedCell
                         // !to &&
                         &&  !this->wayTakts &&
         this->way.length &&
         this->wayIndex <= 5 &&
         this->isPotentialWayComplite
    )
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
                   // this->targetData.bornCount = valideTree->bornCount;

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
                        // this->gettingTarget = cell->groundUnit;
                        return true;
                    }
                }
            }
        }
        else
        {
            if (this->cell == this->targetData.clicckedCell || //this->targetCell ||
                (this->wayIndex == 1 &&
                 this->potentialWay.getItem(0)->groundUnit))
            {
                this->iNeedFreeWay = false;
                this->isIgetMyTarget = true;
                return true;
            }
            else
            {
                this->orderOnWay.cell = this->targetData.clicckedCell; //this->targetCell;
              //  this->orderOnWay.isComplite = false;
               // console.log("papa loh");
            }
        }
    }
    return false;
};