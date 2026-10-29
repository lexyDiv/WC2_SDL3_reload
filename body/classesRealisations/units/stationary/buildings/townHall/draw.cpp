#include "create.cpp"
//=>activeProg

void TownHall::draw()
{
    // console.log("draw");

    if (!this->isDelete)
    {
        this->isAddOnDraw = false;
        float drawDeltaX = this->gf->drawDeltaX;
        float drawDeltaY = this->gf->drawDeltaY;
        ctx.DrawImage(this->image,
                      this->animX, this->animY,
                      this->animGabX, this->animGabY,
                      (this->cell->x - this->animCorrectionX) + drawDeltaX,
                      (this->cell->y - this->animCorrectionY) + drawDeltaY,
                      this->drawGabaritX, this->drawGabaritY);

        if (this->isComplite && this->hp < this->hpMax)
        {

            double y = ((double)this->centerDrawY - this->drawGabaritY_2 + (this->drawGabaritY_2 / 10)) + drawDeltaY;

            ctx.DrawImage(this->image2,
                          this->animX_2 + 1, this->animY_2 + 1,
                          this->animGabX_2 - 1, this->animGabY_2 - 1,
                          (this->centerDrawX - this->drawGabaritX_2 / 2) + drawDeltaX,
                          y,
                          this->drawGabaritX_2, this->drawGabaritY_2);

            if (this->animTimer % 2 == 0)
            {

                int percent = (this->hp * 100) / this->hpMax;
                int delta = 100 - percent;
                int gab = (delta * 220) / 100;
                this->drawGabaritX_2 = gab;
                this->drawGabaritY_2 = gab;

                this->animX_2 += 48;
                if (this->animX_2 == 240)
                {
                    this->animX_2 = 0;
                    this->animY_2 += 48;
                    if (this->animY_2 == 96)
                    {
                        this->animY_2 = 0;
                    }
                }
            }

            this->animTimer++;

            if (this->animTimer == 10)
            {
                this->animTimer = 0;
            }
        }

        // this->myCells.forEach([drawDeltaX, drawDeltaY](Cell *cell)
        //                       { ctx.StrokeRect(
        //                             cell->x + drawDeltaX,
        //                             cell->y + drawDeltaY,
        //                             cell->gabX,
        //                             cell->gabY,
        //                             "violet"); });

        // ctx.FillRect(this->centerDrawX + drawDeltaX, this->centerDrawY + drawDeltaY, 5, 5);
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
