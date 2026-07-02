#include "getContactAndExitCells.cpp"
//=>out

void Unit::getWellComeCells()
{
    this->contactCells.forEach([this](Cell *cell)
                               {
                                   MinData md = this->myCells.getMinData([this, cell](Cell *item)
                                                                         {
                                                        PointF pointThis = {x : cell->x, y : cell->y};
                                                        PointF pointLM = {x : item->x, y : item->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        return dis; });
                                    this->wellComeCells.push(md); });
};