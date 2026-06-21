#include "Water::draw.cpp"
//=> out

void Cell::draw()
{
console.log("cell.draw()");
  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;

  // ctx.FillRect(
  //     this->x + drawDeltaX,
  //     this->y + drawDeltaY,
  //     this->gabX,
  //     this->gabY,
  //     this->getMapColor().R,
  //     this->getMapColor().G,
  //     this->getMapColor().B,
  //     255);

  if (this->plane)
  {

    if (this->cellImage)
    {
           if (this->litera != 'w') {
                  ctx.DrawImage(this->cellImage,
                    this->animX,
                    this->animY,
                    this->animGabX,
                    this->animGabY,
                    this->x + drawDeltaX - 35,
                    this->y + drawDeltaY - 35,
                    this->drawGabaritX, this->drawGabaritY);

           } else {
                this->waters.forEach([this](Water* water, int i){
                  water->drawControlBasic(i);
                  water->draw(this, i);
                });
           }

    }

    //     string str = "K: " + to_string(this->plane->number);
    //     if (this->plane->type == "sea") {
    //       str = "S: " + to_string(this->plane->number);
    //     }
    //    ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 5, 10,  str, 255);
    // if (this->lineToOtherPlaneNumber && this->plane->type == "ground") {
    //           ctx.StrokeRect(
    //     this->x + drawDeltaX,
    //     this->y + drawDeltaY,
    //     this->gabX,
    //     this->gabY,
    //     "red");
    // }

    //     if (this->lineToOtherPlaneNumber && this->plane->type == "sea") {
    //           ctx.StrokeRect(
    //     this->x + drawDeltaX,
    //     this->y + drawDeltaY,
    //     this->gabX,
    //     this->gabY,
    //     "green");
    // }
    //   if (this->plane->type == "sea" && this->lineToOtherPlaneNumber) {
    //         string str = "K: " + to_string(this->lineToOtherPlaneNumber);
    //        ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 5, 10,  str, 255);
    //   }
    //     if (this->plane->type == "ground" && this->lineToDarckGround) {
    //       string str = "K: " + to_string(this->lineToDarckGround);
    //      ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 5, 10,  str, 255);
    // }
  }

  // ctx.StrokeRect(
  //     this->x + drawDeltaX,
  //     this->y + drawDeltaY,
  //     this->gabX,
  //     this->gabY,
  //     "yellow");
}