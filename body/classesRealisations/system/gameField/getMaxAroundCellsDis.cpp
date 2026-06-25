#include "getContinents.cpp"
//=>getToOtherPlaneCellsNumber

void GameField::getMaxAroundCellsDis()
{
    this->field.forEach([](Array<Cell *> &arr)
                        { arr.forEach([](Cell *cell)
                                      { cell->maxAroundCells.forEach([cell](Cell *ac)
                                                                     {
                Delta delta = getDeltas(
                {x: cell->x, y: cell->y}, 
                {x: ac->x, y: ac->y});
                double dis = getDis(delta);
                cell->maxAroundCellsDis.push(dis); }); }); });
};