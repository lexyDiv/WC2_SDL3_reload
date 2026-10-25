#include "create.cpp"
//=>activeProg

void TownHall::draw()
{
    // console.log("draw");
    this->isAddOnDraw = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    if (this->hp)
    {
        ctx.DrawImage(this->image,
                      this->animX, this->animY,
                      this->animGabX, this->animGabY,
                      (this->cell->x - this->animCorrectionX) + drawDeltaX, // 90
                      (this->cell->y - this->animCorrectionY) + drawDeltaY, // 120
                      this->drawGabaritX, this->drawGabaritY);              // x 285, y 290
    }
    else
    {
                ctx.DrawImage(this->image,
                      this->animX, this->animY,
                      this->animGabX, this->animGabY,
                      (this->cell->x - this->animCorrectionX) + drawDeltaX, // 90
                      (this->cell->y - this->animCorrectionY) + drawDeltaY, // 120
                      this->drawGabaritX, this->drawGabaritY, SDL_FLIP_NONE, 0, this->alpha); 
    }

    this->myCells.forEach([drawDeltaX, drawDeltaY](Cell *cell)
                          { ctx.StrokeRect(
                                cell->x + drawDeltaX,
                                cell->y + drawDeltaY,
                                cell->gabX,
                                cell->gabY,
                                "violet"); });
};
