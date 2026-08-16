#include "createInside.cpp"
//=>activeProg

void Peon_peasant::stendOnCell()
{
    this->x = this->cell->x;
    this->y = this->cell->y;
    this->wayTakts = 0;
    this->drawIndexY = this->y;
    this->speedTale = 0;
    this->isGetMyCell = true;
    this->potentialWay.clear();
    this->wayIndex = 0;
    this->animTimer = 0;
    this->animY = 0;
    this->holdWayCount = 0;
};