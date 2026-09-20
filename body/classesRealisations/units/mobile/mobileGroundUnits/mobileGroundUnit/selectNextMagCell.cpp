#include "stepToTheSide.cpp"
//=>goToNextMagCell

void MobileGroundUnit::selectNextMagCell()
{
    TargetData &td = this->targetData;
    if (//this->wayIndex <= 1 &&
        td.magistralWay.length &&
        td.nextMagCellIndex && this->orderOnWay.isComplite)
    {
       // console.log("here");
        if (this->nextCell->mc == td.nextMagCell->mc)
        {
            td.nextMagCellIndex--;
            td.prevMagCell = td.nextMagCell;
            td.nextMagCell = td.magistralWay.getItem(td.nextMagCellIndex);
            td.clicckedCell = td.nextMagCell;
           // console.log("select ok");
            this->goToNextMagCell();
        }
        else
        {

            float prevXCat = td.prevMagCell->x - this->cell->x;
            float prevYCat = td.prevMagCell->y - this->cell->y;
            float disToPrev = sqrt(prevXCat * prevXCat + prevYCat * prevYCat);

            float nextXCat = td.nextMagCell->x - this->cell->x;
            float nextYCat = td.nextMagCell->y - this->cell->y;
            float disToNext = sqrt(nextXCat * nextXCat + nextYCat * nextYCat);

            if (disToPrev > disToNext)
            {
                td.nextMagCellIndex--;
                td.prevMagCell = td.nextMagCell;
                td.nextMagCell = td.magistralWay.getItem(td.nextMagCellIndex);
                td.clicckedCell = td.nextMagCell;
                //console.log("select ok");
                this->goToNextMagCell();
            }
        }
    }
}