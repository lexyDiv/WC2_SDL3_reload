#include "goWayAnimation.cpp"
//=>out

void MobileGroundUnit::iAmHere()
{
    this->cell->maxAroundCells.forEach([this](Cell *cell, int index)
                                       {
                                           Unit *gu = cell->groundUnit;
                                           Unit *fu = cell->flyUnit;
                                     if (gu) {
                                        gu->iSeeYou(this);
                                     }
                                     if (fu) {
                                        fu->iSeeYou(this);
                                     } });
}