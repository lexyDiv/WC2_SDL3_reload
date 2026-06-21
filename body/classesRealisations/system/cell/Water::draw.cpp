#include "Cell.cpp"
//=> draw

void Water::draw(Cell *cell, int i)
{
    float drawDeltaX = cell->gf->drawDeltaX;
    float drawDeltaY = cell->gf->drawDeltaY;

    ctx.DrawImage(
        cell->cellImage, this->animX, this->animY,
        cell->animGabX, cell->animGabY,
        cell->x + drawDeltaX - 40, cell->y + drawDeltaY - 40,
        cell->drawGabaritX + this->drawGabPro, cell->drawGabaritY + this->drawGabPro,
        SDL_FLIP_NONE, this->conor, this->alpha);
}