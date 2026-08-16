#include "peon_peasant_in.h"
//=>draw


void Peon_peasant::create(Cell *cell)
{

  //this->unitMenu = unitMenuPack.peon;

  this->cell = cell;
  this->cell->game->AllUnitsPtr.push(this);
  this->myCells.push(cell);
  this->cell->groundUnit = this;
  this->gf = cell->gf;
  this->game = cell->game;
  this->name = "peon";
  this->type = "life";
  this->mapColor = this->fraction->mapColor;
  this->image = this->fraction->peon.img_1;
  this->x = cell->x;
  this->y = cell->y;
  this->getGabX = cell->gabX;
  this->getGabY = this->getGabX;
  this->drawIndexY = cell->y + cell->gabX / 2;
  this->animGabX = 100;
  this->animGabY = 100;
  this->animStepX = 100;
  this->animStepY = 100;
  this->animX = intRand(0, 8) * 100;
  this->animY = 0;
  this->hp = this->fraction->peon.hpMax;
};