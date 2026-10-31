#include "trupCreate.cpp"
//=>takeDamage

void Tree::drawTrup()
{

   this->isAddOnDrawTrup = false;

   float drawDeltaX = this->gf->drawDeltaX;
   float drawDeltaY = this->gf->drawDeltaY;

   if (!this->isAI)
   {

      ctx.DrawImage(this->image2,
                    this->animX, this->animY,
                    this->animGabX, this->animGabY,
                    (this->x - this->drawGabaritX / 2) + drawDeltaX,
                    (this->y - this->drawGabaritY) + 13 + drawDeltaY,
                    this->drawGabaritX, this->drawGabaritY);
   }
   else
   {

      ctx.DrawImage(this->image2,
                    0, 0,
                    this->animGabX, this->animGabY,
                    (this->x - this->drawGabaritX / 2) + drawDeltaX,
                    (this->y - this->drawGabaritY) + 13 + drawDeltaY,
                    this->drawGabaritX, this->drawGabaritY);
   }
};