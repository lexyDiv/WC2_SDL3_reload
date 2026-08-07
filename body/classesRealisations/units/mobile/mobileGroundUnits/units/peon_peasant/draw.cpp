#include "create.cpp"
//=>preDraw

void Peon_peasant::draw()
{
  //  this->enemys.forEach([](UnitPack up)
  //                     { console.log(up.unit->name); });
  //    if (this->enemys.length) {
  //                            UnitPack up = this->enemys.pop2();
  //                    console.log("deleted " + up.unit->name);
  //    }
  this->preDraw();
  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;

  // if (this->targetCell)
  // {
  //   ctx.FillRect(this->targetCell->x + drawDeltaX,
  //                this->targetCell->y + drawDeltaY, 48, 48, "red");
  // }

  //   if (this->cell)
  // {
  //   ctx.FillRect(this->cell->x + drawDeltaX,
  //                this->cell->y + drawDeltaY, 48, 48, "red");
  // }

  if (!this->inSave)
  {
    ctx.DrawImage(
        this->image,
        this->animX,
        this->animY,
        this->animGabX,
        this->animGabY,
        this->x + drawDeltaX - 25,
        this->y + drawDeltaY - 25,
        100,
        100);

    // ctx.DrawText(this->x + drawDeltaX + 10,
    //              this->y + drawDeltaY + 20,
    //              14,
    //              to_string(this->persNum));
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
    // ctx.FillRect(cx, cy, 3, 3, "blue");
  }
};