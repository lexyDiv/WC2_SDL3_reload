#include "basicActionCheck.cpp"
//=>out

void Peon_peasant::startedCheckAroundCells(ThData *th)
{
    if (
        this->badNCU ||
        this->needResetAround)
    {

        this->cell->aroundCells.forEach([th, this](Cell *cell)
                                        {
            Unit *gu = cell->groundUnit;

            if ( 
                cell->plane != this->cell->plane ||
                (gu &&
                    (this->needResetAround ||
                     !gu->way.length ||
                     !gu->nextCell ||
                     gu == this->badNCU ||
                     !gu->targetData.unit ||
                     (gu->targetData.unit != this->targetData.unit)
                    )
                )
               
            ) {
                cell->thwd.getItemPtr(th->num)->explored = th->createCount;
                cell->thwd.getItemPtr(th->num)->createCountData = th->createCount;
            } else {
                th->exploreNewCellAndAddToOpenArr(this, this->cell, cell);
            } });

        this->badNCU = nullptr;
        this->needResetAround = false;
    }
}