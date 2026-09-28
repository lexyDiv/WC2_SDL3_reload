#include "stepToTheSide.cpp"
//=>units

void MobileGroundUnit::checkNextMagistralCell() {
    TargetData &td = this->targetData;
    int prevCellDis = this->thd->get_H(td.prevCell, this->cell);
    int nextCellDis = this->thd->get_H(td.nextCell, this->cell);
    if (nextCellDis < prevCellDis && td.nextCellIndex) {
        td.nextCellIndex--;
        td.prevCell = td.nextCell;
        td.nextCell = td.magistral.getItem(td.nextCellIndex);
    }
}