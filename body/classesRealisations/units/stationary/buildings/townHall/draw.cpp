#include "create.cpp"
//=>activeProg

void TownHall::draw()
{
    // console.log("draw");

    if (this->hp)
    {
        this->isAddOnDraw = false;
        float drawDeltaX = this->gf->drawDeltaX;
        float drawDeltaY = this->gf->drawDeltaY;
        ctx.DrawImage(this->image,
                      this->animX, this->animY,
                      this->animGabX, this->animGabY,
                      (this->cell->x - this->animCorrectionX) + drawDeltaX, // 90
                      (this->cell->y - this->animCorrectionY) + drawDeltaY, // 120
                      this->drawGabaritX, this->drawGabaritY);              // x 285, y 290

        this->myCells.forEach([drawDeltaX, drawDeltaY](Cell *cell)
                              { ctx.StrokeRect(
                                    cell->x + drawDeltaX,
                                    cell->y + drawDeltaY,
                                    cell->gabX,
                                    cell->gabY,
                                    "violet"); });
    }
    // else
    // {
    //             ctx.DrawImage(this->image,
    //                   this->animX, this->animY,
    //                   this->animGabX, this->animGabY,
    //                   (this->cell->x - this->animCorrectionX) + drawDeltaX, // 90
    //                   (this->cell->y - this->animCorrectionY) + drawDeltaY, // 120
    //                   this->drawGabaritX, this->drawGabaritY, SDL_FLIP_NONE, 0, this->alpha);
    // }
};
