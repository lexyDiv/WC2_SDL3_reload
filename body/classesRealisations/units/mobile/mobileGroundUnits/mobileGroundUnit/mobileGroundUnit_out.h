#include "stepToTheSide.cpp"
//=>units

void MobileGroundUnit::checkNextMagistralCell()
{
    TargetData &td = this->targetData;
    int prevCellDis = this->thd->get_H(td.prevCell, this->cell);
    int nextCellDis = this->thd->get_H(td.nextCell, this->cell);
    if (
        nextCellDis < prevCellDis && td.nextCellIndex &&
        td.nextCell //&&
        //((td.nextCell->claster != td.prevCell->claster))
        )
    {
        td.nextCellIndex--;
        td.prevCell = td.nextCell;
        td.nextCell = td.magistral.getItem(td.nextCellIndex);
        td.magistrlLoop = 0;
    }
    else if (
             (td.nextCell && !td.nextCellIndex && nextCellDis < prevCellDis) || 
             (td.magistrlLoop >= 20 && !this->blockedData.isBlocked)
            )
    {

        if (td.nextCell && !td.nextCellIndex)
        {
           // td.isNeedClasterMagistral = false;
        }

        td.magistrlLoop = 0;
        td.nextCell = nullptr;
        td.prevCell = nullptr;
        td.nextCellIndex = 0;
        td.magistral.clear();
        td.isNeedMagistralFinish = true;
    }
}