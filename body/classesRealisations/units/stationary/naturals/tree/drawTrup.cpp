#include "trupCreate.cpp"
//=>out

void Tree::drawTrup()
{
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    ctx.DrawImage(this->image2,
                  this->animX, this->animY,
                  this->animGabX, this->animGabY,
                  (this->x - this->drawGabaritX / 2) + drawDeltaX,
                  (this->y - this->drawGabaritY) + 13 + drawDeltaY,
                  this->drawGabaritX, this->drawGabaritY);
};