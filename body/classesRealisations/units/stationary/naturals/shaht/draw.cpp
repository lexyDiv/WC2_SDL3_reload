#include "create.cpp"
//=>out

void Shaht::draw() {
    this->isAddOnDraw = false;
  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;
int animY = !this->clients.length ? 0 : this->animStepY;
   
   ctx.DrawImage(this->image,
   this->animX, animY,
   this->animGabX, this->animGabY,
   this->x + drawDeltaX - 8, this->y + drawDeltaY - 30,
   160, 195);

  //  this->contactCells.forEach([drawDeltaX, drawDeltaY](ProtoObj* cell, int i){
  //   ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY);
  //   ctx.DrawText(cell->x + drawDeltaX, cell->y + drawDeltaY, 20, to_string(i));
  //  });
  //   this->exitCells.forEach([drawDeltaX, drawDeltaY](ProtoObj* cell, int i){
  //   ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY);
  //   ctx.DrawText(cell->x + drawDeltaX, cell->y + drawDeltaY, 20, to_string(i));
  //  });

  //  this->myCells.forEach([drawDeltaX, drawDeltaY](ProtoObj *cell){
  //   ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY);
  //  });

}