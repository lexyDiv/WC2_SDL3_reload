#include "takeDamage.cpp"
//=>out

void Peon_peasant::drawTrup()
{
    this->isAddOnDraw = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    ctx.DrawImage(this->image,
                  this->animX, this->animY,
                  this->animGabX, this->animGabY,
                  this->x + drawDeltaX - 25,
                  this->y + drawDeltaY - 25,
                  100, 100, SDL_FLIP_NONE, 0, this->alpha);

    // if (this->focus) {
    //     ctx.StrokeRect(this->x + drawDeltaX, this->y + drawDeltaY, this->cell->gabX, this->cell->gabX, "red");
    // }
}