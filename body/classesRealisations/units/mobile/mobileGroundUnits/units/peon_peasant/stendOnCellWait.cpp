#include "fightControl.cpp"
//=>getCurrentTarget

void Peon_peasant::stendOnCellWait()
{
    this->x = this->cell->x;
    this->y = this->cell->y;
    this->drawIndexY = this->y;
    this->speedTale = 0;
    this->isGetMyCell = true;
    this->animTimer = 0;
    this->animY = 0;
    this->holdWayCount ++;
};