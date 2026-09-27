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
    this->way.clear();
    this->wayIndex = 0;
    this->animTimer = 0;
    this->animY = 0;
    this->needHolTimer = 0;

    ///////////////////////////////

    // if (this->targetUnit &&
    //     !this->targetUnit->inSave &&
    //     this->targetUnit->isActive &&
    //     this->targetUnit->hp &&
    //     this->targetUnit->cell &&
    //     this->targetUnit->targetData.clicckedCell == this->freeCell)
    // {
    //     this->targetUnit->orderOnWay.go();
    //     this->targetData.blockedFreeWayHoldTimer = 0;
    // }
    //     this->targetUnit = nullptr;
    //     this->freeCell = nullptr;
};