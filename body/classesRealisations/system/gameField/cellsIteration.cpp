#include "getAroundCells.cpp"
//=>getContonents

void GameField::cellsIteration(function<void(Cell *cell)> fn)
{
    this->field.forEach([fn](Array<Cell *> &arr)
                        { arr.forEach([fn](Cell *cell)
                                      { fn(cell); }); });
}

// void GameField::clasterIteration(function<void(Claster &cl)> fn)
// {
//     this->clasters.forEach([fn](Array<Claster > &arr)
//                         { arr.forEach([fn](Claster &cl)
//                                       { fn(cl); }); });
// };