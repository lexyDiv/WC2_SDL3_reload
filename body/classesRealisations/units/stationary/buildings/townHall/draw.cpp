#include "create.cpp"
//=>activeProg

void TownHall::draw()
{
    // console.log("draw");
    this->isAddOnDraw = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    ctx.DrawImage(this->image,
                  0, 0,
                  this->animGabX, this->animGabY,
                  (this->cell->x - 90) + drawDeltaX,
                  (this->cell->y - 120) + drawDeltaY,
                  285, 290);

    // this->myCells.forEach([drawDeltaX, drawDeltaY](ProtoObj *cell)
    //                       { ctx.StrokeRect(
    //                             cell->x + drawDeltaX,
    //                             cell->y + drawDeltaY,
    //                             cell->gabX,
    //                             cell->gabY,
    //                             "violet"); });
    //  ctx.FillRect(this->cell->x + drawDeltaX, this->cell->y + drawDeltaY, this->cell->gabX, this->cell->gabY, "blue");
};

