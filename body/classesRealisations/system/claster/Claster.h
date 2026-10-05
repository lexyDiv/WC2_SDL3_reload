#include "in.h"
//=>out

Claster::Claster(Cell *cell, Game *game)
{
    this->game = game;
    this->gf = game->gf;
    this->cell = cell;
    this->gab = gf->clasterGabarit;
    this->size = this->gab * gf->cellSize;
    this->x = cell->x - gf->cellSize * ((this->gab - 1) / 2);
    this->y = cell->y - gf->cellSize * ((this->gab - 1) / 2);

    this->cells.copy(this->cell->clasterCells);
    this->cell->clasterCells.clear();
}
