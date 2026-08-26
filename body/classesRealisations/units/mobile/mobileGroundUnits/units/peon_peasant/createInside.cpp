#include "preDraw.cpp"
//=>stendOnCell

void Peon_peasant::createInside(Cell *c)
{

    this->persNum = this->fraction->unitCount;
    this->cell = nullptr;
    this->gf = c->gf;
    this->game = c->game;
    this->name = "peon";
    this->type = "life";
    this->mapColor = this->fraction->mapColor;
    this->image = this->fraction->peon.img_1;
    this->x = c->x;
    this->y = c->y;
    this->getGabX = c->gabX;
    this->getGabY = this->getGabX;
    this->drawIndexY = c->y + c->gabX / 2;

    this->animGabX = 100;
    this->animGabY = 100;
    this->animStepX = 100;
    this->animStepY = 100;

    this->animX = intRand(0, 8) * 100;
    this->animY = 0;
    this->hpMax = 50;
    this->hp = 50;

    this->inOutTimer = 0;
    this->inSave = true;
    this->animMashtab = this->startAnimMashtab;
    c->game->AllUnitsPtr.push(this);
    c->game->allLifeUnitsPtr.push(this);
    this->fraction->peons.push(this);
    this->fraction->AllLifeUnits.push(this);
}