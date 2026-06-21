#include "create.cpp"
//=>preDraw

void Game::draw()
{

    

   // ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
  //  ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "black");

    ctx.CreateDrawZone(this->gf->x, this->gf->y, this->gf->screenWidth, this->gf->screenHeight);


ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "green");
    if (this->gf->drawCell != nullptr)
    {
        float drawDeltaX = this->gf->drawDeltaX;
        float drawDeltaY = this->gf->drawDeltaY;

        Array<Array<Cell *>> DA;
        for (int i = 0; i < 230; i++)
        {
            Array<Cell *> a;
            DA.push(a);
        };

        Array<int> max;

        this->gf->drawCell->cellsOnDraw.forEach([drawDeltaY, &DA, &max](Array<Cell *> drawLine)
                                                { drawLine.forEach([drawDeltaY, &DA, &max](Cell *cell)
                                                                   {
                     cell->draw();
                    Unit *groundUnit = cell->groundUnit;
                    // if (groundUnit && !groundUnit->isAddOnDraw
                    // ) {
                    // int index = ceil((((groundUnit->drawIndexY) + drawDeltaY) / 10) + 30);

                    //     groundUnit->isAddOnDraw = true;
                    //    Array<ProtoObj *> &line = DA.getItem3(index);                    
                    //     line.push(groundUnit);
                    //    max.push(index);
                    // } 
                }); });

        this->gf->drawCell->cellsOnDraw.forEach([drawDeltaY, &DA, &max](Array<Cell *> drawLine)
                                                { drawLine.forEach([drawDeltaY, &DA, &max](Cell *cell)
                                                                   {
                    //   cell->ripUnits.forEach([](Unit* trup){
                    //     trup->drawTrup();
                    //   });
                     }); });

        // DA.forEach([](Array<ProtoObj *> line)
        //            { line.forEach([](ProtoObj *unit)
        //                           { unit->draw(); }); });

        /////////  setka
        // this->gf->drawCell->cellsOnDraw.forEach([drawDeltaX, drawDeltaY](Array<ProtoObj *> drawLine)
        //                                         { drawLine.forEach([drawDeltaX, drawDeltaY](ProtoObj *cell)
        //                                                            {
        //                                                             ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY, "yellow");
        //                                                           //  ctx.DrawText(cell->x + drawDeltaX, cell->y + drawDeltaY + 10, 10, "v= " + to_string((int)cell->ver));
        //                                                           //  ctx.DrawText(cell->x + drawDeltaX, cell->y + drawDeltaY + 20, 10, "h= " + to_string((int)cell->hor));
        //                                                             }); });


        // /////////////// zone
        // FieldClick *fcp = this->gf->fieldClickPoint;
        // if (fcp)
        // {
        //     ctx.StrokeRect(
        //         fcp->firstX + drawDeltaX,
        //         fcp->firstY + drawDeltaY,
        //         fcp->gabX, fcp->gabY, "red");
        // }
        // /////////////// zone
    } 

    ctx.CreateDrawZone(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight);
    ctx.FillRect(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight, "black");

    ctx.CreateDrawZone(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT);
    ctx.FillRect(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT, "black");

  //  this->fonMenuDraw();
   // this->gf->miniMapDraw();

   // this->objMenu->draw();

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
}