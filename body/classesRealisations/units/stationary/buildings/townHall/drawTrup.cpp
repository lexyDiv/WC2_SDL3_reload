#include "trupCreate.cpp"
//=>checkCompliteState

void TownHall::drawTrup()
{
   // console.log("draw trup");
    this->isAddOnDrawTrup = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    ctx.DrawImage(this->image,
                  this->animX, this->animY,
                  this->animGabX, this->animGabY,
                  (this->cell->x - this->animCorrectionX) + drawDeltaX, // 90
                  (this->cell->y - this->animCorrectionY) + drawDeltaY, // 120
                  this->drawGabaritX, this->drawGabaritY, SDL_FLIP_NONE, 0, this->alpha);
}