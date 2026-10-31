#include "getContactCells.cpp"
//=> tree stressControl

void Tree::draw()
{

  this->isAddOnDraw = false;

  if (this->deleteTimer < 50)
  {
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    if (!this->isAI)
    {
      ctx.DrawImage(this->image,
                    this->animX, this->animY,
                    this->animGabX, this->animGabY,
                    (this->x - this->drawGabaritX / 2) + drawDeltaX,
                    (this->y - this->drawGabaritY) + 13 + drawDeltaY,
                    this->drawGabaritX, this->drawGabaritY, SDL_FLIP_NONE, 0, this->alpha);

      this->animTakt++;

      if (this->animTakt == 15)
      {
        this->animX += this->animStepX;
        this->animTakt = 0;
        if (this->animX == 800)
        {
          this->animX = 0;
        }
      }
    }
    else
    {

      ctx.DrawImage(this->image,
                    this->animX, this->animY,
                    this->animGabX, this->animGabY,
                    (this->x - this->drawGabaritX / 2) + drawDeltaX,
                    (this->y - this->drawGabaritY) + 13 + drawDeltaY,
                    this->drawGabaritX, this->drawGabaritY, SDL_FLIP_NONE, 0, this->alpha);

      if (this->animTakt == 7)
      {
        this->animTakt = 0;
              this->animX += this->animStepX;
      if (this->animX >= 400)
      {
        this->animX = 0;
        this->animY += this->animStepX;
        if (this->animY >= 400)
        {
          this->animY = 0;
        }
      }
      }
      this->animTakt ++;
    }
  }
}