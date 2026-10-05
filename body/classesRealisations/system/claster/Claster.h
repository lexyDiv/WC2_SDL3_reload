#include "in.h"
//=>getZones

Claster::Claster(Cell *cell, Game *game, int ver, int hor)
{
    this->ver = ver;
    this->hor = hor;
    this->game = game;
    this->gf = game->gf;
    this->cell = cell;
    this->gab = gf->clasterGabarit;
    this->size = this->gab * gf->cellSize;
    this->x = cell->x - gf->cellSize * ((this->gab - 1) / 2);
    this->y = cell->y - gf->cellSize * ((this->gab - 1) / 2);
}

void Claster::create()
{
    this->cell->clasterCells.forEach([this](Cell *c)
                                     {
                                         c->claster = this;
                                         this->cells.push(c);
                                     });
}
