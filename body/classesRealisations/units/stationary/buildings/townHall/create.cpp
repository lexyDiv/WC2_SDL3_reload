#include "in.h"
//=>draw

void TownHall::create(Cell *cell)
{
   // console.log("townHall created !!!");
   // this->createUnitMenu();
    //////////////////

     this->get4x4myCells(cell);

     Cell *exitCell = cell->bottom_right->bottom_right->bottom_right->bottom_right;
     Cell *centerCell = cell->bottom_right;
     this->cell = centerCell;
     this->game = this->cell->game;
     this->game->AllUnitsPtr.push(this);
     this->fraction->allBuildings.push(this);

     this->getContactAndExitCells(cell, exitCell, centerCell);
     this->getWellComeCells();
     this->getTrees();
     this->getShahts();
     this->name = "greatHall";
     this->type = "building";
     this->mapColor = this->fraction->mapColor;
     this->image = this->fraction->townHall.img_1;
     this->gf = this->cell->gf;
     this->x = cell->x;
     this->y = cell->y;
     this->getGabX = cell->gabX * 4;
     this->getGabY = this->getGabX;
     this->drawIndexY = cell->y + 30;

     this->animGabX = 128;
     this->animGabY = 128;
     this->animStepX = 128;
     this->animStepY = 128;

     this->animX = 0;
     this->animY = 0;
     this->hpMax = 1200;
     this->hp = 1200;
}

