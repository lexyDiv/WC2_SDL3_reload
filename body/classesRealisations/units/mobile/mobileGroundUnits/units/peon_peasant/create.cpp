#include "peon_peasant_in.h"
//=>draw


void Peon_peasant::create(Cell *cell, bool isComplite = false, bool isNew = false)
{

  //this->unitMenu = unitMenuPack.peon;

  this->cell = cell;
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
  this->orderOnWay.unit = this;
  this->animCorrectionX = 25;
  this->animCorrectionY = 25;
  this->drawGabaritX = 100;
  this->drawGabaritY = 100;

    canGiveTree = false;
    canGiveGold = false;
    canTakeWood = false;
    canTakeGold = false;
    canBuild = true;
    canMove = true;

    this->deleteTimer = 3000;

    this->game->addToAllUnitsPtr(this);
    this->fraction->allUnits.push(this);
   
};