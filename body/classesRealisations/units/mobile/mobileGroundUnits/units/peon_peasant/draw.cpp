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

        if (this->focus && this->cell) {

                   this->way.forEach([&drawDeltaX, &drawDeltaY](Cell *c, int i){
                    ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->game->gf->cellSize, c->game->gf->cellSize, "violet", 100);
                   // ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, c->game->gf->cellSize, c->game->gf->cellSize, "black", 100);
                   // ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(i));
                   });

   // ctx.FillRect(this->cell->x + drawDeltaX, this->cell->y + drawDeltaY, this->cell->game->gf->cellSize, this->cell->game->gf->cellSize, "blue", 100);
        }

    // ctx.DrawText(this->x + drawDeltaX + 10,
    //              this->y + drawDeltaY + 20,
    //              14,
    //              to_string(this->persNum));

    // if (this->persNum == 1)
    // {
    //   this->way.forEach([&drawDeltaX, &drawDeltaY, this](Cell *c, int i)
    //                     {
    //                 ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->game->gf->cellSize, c->game->gf->cellSize, "green", 100);
    //                 ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, c->game->gf->cellSize, c->game->gf->cellSize, "black", 100); });

    //                 if (this->cell) {
    //                   ctx.FillRect(this->cell->x + drawDeltaX, this->cell->y + drawDeltaY, this->game->gf->cellSize, this->game->gf->cellSize, "violet", 100);
    //                 }

    //   //  this->rwd.dopWay.forEach([&drawDeltaX, &drawDeltaY](Cell *c, int i){
    //   //   ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, c->game->gf->cellSize, c->game->gf->cellSize, "blue", 100);
    //   //   ctx.DrawText(c->x + drawDeltaX + 30, c->y + drawDeltaY, 20, to_string(i));
    //   //  });
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
    // ctx.FillRect(cx, cy, 3, 3, "blue");
  }
};