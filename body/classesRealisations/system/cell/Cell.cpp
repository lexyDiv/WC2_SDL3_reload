#include "in.h"

//=>Draw

void AnimLines::draw(Unit *oil)
{
    float drawDeltaX = oil->gf->drawDeltaX;
    float drawDeltaY = oil->gf->drawDeltaY;
    ctx.DrawImage(oil->image,
                  this->animX,
                  this->animY,
                  this->animGabX, this->animGabY,
                  oil->x + this->deltaX + drawDeltaX, oil->y + this->y + drawDeltaY,
                  oil->getGabX, this->gabY, SDL_FLIP_NONE, 0, this->alpha);
}
