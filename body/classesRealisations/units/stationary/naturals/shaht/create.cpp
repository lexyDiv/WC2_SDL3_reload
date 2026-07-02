#include "Shaht.cpp"
//=>draw

void Shaht::create(Cell *cell)
{

   // this->createUnitMenu();
    //////////////////


    this->get3x3myCells(cell);

    Cell *exitCell = cell->bottom->bottom->bottom_left;
    Cell *centerCell = cell->bottom_right;
    this->cell = centerCell;
    this->cell->game->allShahtsPtr.push(this);

   // this->getContactAndExitCells(cell, exitCell, centerCell);
   // this->getWellComeCells();
    this->name = "shaht";
    this->type = "building";
    this->mapColor = {R : 255, G : 255, B : 0};
    this->image = imager.shaht;
    this->x = cell->x;
    this->y = cell->y;
    this->getGabX = cell->gabX * 3;
    this->getGabY = this->getGabX;
    this->drawIndexY = cell->y + 20;

    this->animGabX = 96;
    this->animGabY = 96;
    this->animStepX = 96;
    this->animStepY = 96;

    this->animX = 0;
    this->animY = 0;
    this->hpMax = 1000;
    this->hp = 1000;
    this->isComplite = true;
    cell->plane->shahts.push(this);
};