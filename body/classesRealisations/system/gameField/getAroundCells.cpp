#include "getDefaultColor.cpp"
//=>cellsIteration

void GameField::getAroundCells(int wing, bool selfCell, function<void(Cell *focusCell, Cell *cellToPush)> fn)
{
    this->cellsIteration([this, wing, selfCell, fn](Cell *cell)
                         {
      int minVer = cell->ver - wing;
      int maxVer = cell->ver + wing;
      for (int ver = minVer; ver <= maxVer; ver++) {
        int minHor = cell->hor - wing;
        int maxHor = cell->hor + wing;
        for (int hor = minHor; hor <= maxHor; hor++) {
                    if (
            ver >= 0 && 
            ver < this->gabarit &&
            hor >= 0 &&
            hor < this->gabarit) {
                Cell *pushedCell = this->field.getItem(ver).getItem(hor);
                if (!selfCell) {
                    if (cell != pushedCell) {
                    fn(cell, pushedCell);
                    }
                } else {
                   fn(cell, pushedCell);
                }
            }
        }
      } });
}