#include "getToTreeCellLineNumber.cpp"
//=> getCellImageCellDrawIndexCellUnitInit

void GameField::getVectorCells(Cell *cell)
{
    cell->aroundCells.forEach([cell](Cell *ac)
                              {
      if (ac->ver < cell->ver && ac->hor == cell->hor) {
        cell->top = ac;
      } else if (ac->ver > cell->ver && ac->hor == cell->hor) {
        cell->bottom = ac;
      } else if (ac->ver == cell->ver && ac->hor < cell->hor) {
        cell->left = ac;
      } else if (ac->ver == cell->ver && ac->hor > cell->hor) {
        cell->right = ac;
      } else if (ac->ver < cell->ver && ac->hor < cell->hor) {
        cell->top_left = ac;
      } else if (ac->ver < cell->ver && ac->hor > cell->hor) {
        cell->top_right = ac;
      } else if (ac->ver > cell->ver && ac->hor < cell->hor) {
        cell->bottom_left = ac;
      } else if (ac->ver > cell->ver && ac->hor > cell->hor) {
        cell->bottom_right = ac;
      } });
}


