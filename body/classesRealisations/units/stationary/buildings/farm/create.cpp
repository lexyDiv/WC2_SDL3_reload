#include "in.h"
//=>draw

bool Farm::create(Cell *c, bool isComplite = false, bool isNew = false)
{

    this->myCells.forEach([this](Cell *c)
                          { c->groundUnit = this; });

    this->name = "farm";

    this->cell = c;
    this->game = c->game;
    this->gf = this->game->gf;

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
    this->image2 = imager.big_fire;
    this->animGabX_2 = 256;
    this->animGabY_2 = 256;
    this->drawGabaritX_2 = 0;
    this->drawGabaritY_2 = 0;
    this->animCorrectionX_2 = 0;
    this->animCorrectionY_2 = 0;
    this->animX_2 = 0;
    this->animY_2 = 0;
    this->centerDrawX = this->cell->x + cell->gabX;     //+ this->getGabX / 2;
    this->centerDrawY = this->cell->y + cell->gabY; //+ this->getGabY / 2;

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
        this->isComplite = true;
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