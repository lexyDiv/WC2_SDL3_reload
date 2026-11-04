#include "create.cpp"
//=>activeProg

void Farm::draw()
{
    if (!this->isDelete)
    {
        this->isAddOnDraw = false;
       // console.log("draw = ", this->image);
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

            double y = ((double)this->centerDrawY - this->drawGabaritY_2 + (this->drawGabaritY_2 / 5)) + drawDeltaY;

            ctx.DrawImage(this->image2,
                          this->animX_2, this->animY_2,
                          this->animGabX_2, this->animGabY_2,
                          (this->centerDrawX - this->drawGabaritX_2 / 2) + drawDeltaX,
                          y,
                          this->drawGabaritX_2, this->drawGabaritY_2);

            if (this->animTimer % 2 == 0)
            {

                int percent = (this->hp * 100) / this->hpMax;
                int delta = 100 - percent;
                int gabY = (delta * 300) / 100;
                int gabX = (delta * 220) / 100;
                this->drawGabaritX_2 = gabX;
                this->drawGabaritY_2 = gabY;
                // console.log(this->animX_2);
                this->animX_2 += 256;
                if (this->animX_2 == 1024)
                {
                    this->animX_2 = 0;
                    this->animY_2 += 256;
                    if (this->animY_2 == 1024)
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

        this->myCells.forEach([drawDeltaX, drawDeltaY](Cell *cell)
                              { ctx.StrokeRect(
                                    cell->x + drawDeltaX,
                                    cell->y + drawDeltaY,
                                    cell->gabX,
                                    cell->gabY,
                                    "violet"); });


    }
}