#include "in.h"
//=>draw

void Mount::create(Cell *cell)
{
    this->get2x2myCells(cell);

    this->cell = cell->right->bottom;
    this->cell->game->allMountsPtr.push(this);
    this->getContactCells();

    this->x = cell->x + cell->gabX;
    this->y = cell->y + cell->gabY;
    this->drawIndexY = this->y;

    this->animX = 200 * intRand(0, 5);

    int rand = intRand(0, 3);
    this->image = !rand ? imager.gora1 : rand == 1 ? imager.gora4
                                                   : imager.gora3;
    this->animGabX = 200;
    this->animGabY = 200;
    this->gf = cell->gf;

    this->name = "mount";
    this->type = "building";
    this->mapColor = {R : 127, G : 0, B : 255};
}