#include "create.cpp"
//=>preDraw

void Peon_peasant::draw()
{

  if (this->cell)
  {
    this->preDraw();
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    if (!this->inSave)
    {
      ctx.DrawImage(
          this->image,
          this->animX,
          this->animY,
          this->animGabX,
          this->animGabY,
          this->x + drawDeltaX - this->animCorrectionX, // 25
          this->y + drawDeltaY - this->animCorrectionY, // 25
          this->drawGabaritX, this->drawGabaritY);

     // ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 10, 15, to_string(this->persNum));
      // if (this->iNeedFreeWay)
      // {
      //   ctx.DrawText(this->x + drawDeltaX + 10, this->y + drawDeltaY + 10, 25, "F");
      // }
    }
    else
    {
      double gabX = 100 * this->animMashtab;
      double gabY = 100 * this->animMashtab;
      double cx = this->x + drawDeltaX - 25 + 50;
      double cy = this->y + drawDeltaY - 25 + 50;
      double dx = this->x + drawDeltaX - 25;
      double dy = this->y + drawDeltaY - 25;

      ctx.DrawImage(
          this->image,
          this->animX,
          this->animY,
          this->animGabX,
          this->animGabY,
          cx - gabX / 2,
          cy - gabY / 2,
          gabX,
          gabY);
    }
  }
};