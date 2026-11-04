#include "in.h"
//=>draw

bool Farm::create(Cell *c, bool isComplite = false, bool isNew = false)
{

    this->myCells.forEach([this](Cell *c)
                          { c->groundUnit = this; });

    this->name = "farm";

    this->cell = c;

    for (int i = 0; i < thDatas.length; i++)
    {
        Td_xploredData tapd;
        this->thwd.push(tapd);
    }

    if (this->cell->claster)
    {
        this->myCells.forEach([this](Cell *c)
                              { this->gf->addClasterOnUpdate(c->claster); });
    }

    this->x = cell->x;
    this->y = cell->y;
    this->getGabX = cell->gabX * 2;
    this->getGabY = this->getGabX;
    this->drawIndexY = cell->y + 30;

    this->canGiveMeal = true;
    this->canStandStill = true;
    this->canGiveTree = false;

    this->getGabX = cell->gabX * 2;
    this->getGabY = this->getGabX;
    this->gf = c->gf;
    this->isComplite = false;
    this->maxDeleteTimer = 3000;
    this->hpMax = 500;

    if (isComplite)
    {
        this->image = this->fraction->farm.img_1;
        this->animGabX = 100;
        this->animGabY = 100;
        this->animStepX = 100;
        this->animStepY = 100;
        this->animCorrectionX = 0;
        this->animCorrectionY = 0;
        this->drawGabaritX = 100;
        this->drawGabaritY = 100;
        this->deleteTimer = 0;
        this->animY = 0;
        this->hp = this->hpMax;
    }
    else
    {
        this->image = this->fraction->farm.construction;
        this->animGabX = 64;
        this->animGabY = 64;
        this->animStepX = 64;
        this->animStepY = 64;
        this->animCorrectionX = 0;
        this->animCorrectionY = 0;
        this->drawGabaritX = 100;
        this->drawGabaritY = 100;
        this->deleteTimer = 0;
        this->animY = 0;
        this->hp = (10 * this->hpMax) / 100;
    }

    this->isActive = true;

    this->fraction->allUnits.push(this);

    return true;
}