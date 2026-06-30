#include "getAroundCells.cpp"
//=>getContonents

void GameField::cellsIteration(function<void(Cell *cell)> fn)
{
    this->field.forEach([fn](Array<Cell *> &arr)
                        { arr.forEach([fn](Cell *cell)
                                      { fn(cell); }); });
}