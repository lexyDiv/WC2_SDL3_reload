#include "in.h"
//=>draw

bool Farm::create(Cell *c, bool isComplite = false, bool isNew = false)
{

    this->myCells.forEach([this](Cell *c)
                          { c->groundUnit = this; });

    this->cell = c;
    this->canGiveMeal = true;
    this->image = this->fraction->farm.construction; // this->fraction->farm.img_1;
    //  console.log(this->fraction->farm.construction);
    // this->image2 = this->fraction->farm.construction;
    this->getGabX = cell->gabX * 2;
    this->getGabY = this->getGabX;
    this->gf = c->gf;
    this->isComplite = false;

    if (this->isComplite)
    {
    }
    else
    {
        this->animGabX = 64;
        this->animGabY = 64;
        this->animStepX = 64;
        this->animStepY = 64;
        this->animCorrectionX = 0;
        this->animCorrectionY = 0;
        this->drawGabaritX = 100;
        this->drawGabaritY = 100;
        this->deleteTimer = 0;
        this->maxDeleteTimer = 3000;
        this->animY = 64;
    }

    this->fraction->allUnits.push(this);

    return true;
}