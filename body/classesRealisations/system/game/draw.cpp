#include "create.cpp"
//=>preDraw

void Game::draw()
{

    if (!this->isGFComplite) {return;}

   // ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
  //  ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "black");

    ctx.CreateDrawZone(this->gf->x, this->gf->y, this->gf->screenWidth, this->gf->screenHeight);


ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "green");
    if (this->gf->drawCell != nullptr)
    {
        float drawDeltaX = this->gf->drawDeltaX;
        float drawDeltaY = this->gf->drawDeltaY;

        Array<Array<Unit *>> DA;
        for (int i = 0; i < 230; i++)
        {
            Array<Unit *> a;
            DA.push(a);
        };

        Array<int> max;

        Cell *dc = this->gf->drawCell;

        dc->cellsOnDraw.forEach([drawDeltaY, &DA, &max](Array<Cell *> &drawLine)
                                                { drawLine.forEach([drawDeltaY, &DA, &max](Cell *cell)
                                                                   {
                    cell->draw();
                    Unit *groundUnit = cell->groundUnit;
                    if (groundUnit && !groundUnit->isAddOnDraw
                    ) {
                    int index = ceil((((groundUnit->drawIndexY) + drawDeltaY) / 10) + 30);

                        groundUnit->isAddOnDraw = true;
                       Array<Unit *> &line = DA.getItemLnk(index);                    
                        line.push(groundUnit);
                       max.push(index);
                    } 
                }); });

        dc->cellsOnDraw.forEach([drawDeltaY, &DA, &max](Array<Cell *> &drawLine)
                                                { drawLine.forEach([drawDeltaY, &DA, &max](Cell *cell)
                                                                   {
                      cell->ripUnits.forEach([](Unit* trup){
                        trup->drawTrup();
                      });
               
                     }); });

        DA.forEach([](Array<Unit *> &line)
                   { line.forEach([](Unit *unit)
                                  { 
                                    unit->draw(); 
                                }); });


       Unit *u = this->gf->focusUnit;                         
  if (u && u->cell) {
    // console.log(to_string(u->needHolTimer));
     ctx.StrokeRect(u->x + drawDeltaX, u->y + drawDeltaY, u->cell->gabX, u->cell->gabY, "blue");

    u->way.forEach([this, &drawDeltaX, &drawDeltaY](Cell *c){
    ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabY, "violet", 100);
    });

        u->targetData.magistral.forEach([this, &drawDeltaX, &drawDeltaY](Cell *c, int i){
    ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabY, "black", 100);
    ctx.DrawText(c->x +drawDeltaX + 5, c->y + drawDeltaY + 5, 10, to_string(i));
    });

    TargetData &td = u->targetData;

    if (td.prevCell) {
       ctx.FillRect(td.prevCell->x + drawDeltaX, td.prevCell->y + drawDeltaY, td.prevCell->gabX, td.prevCell->gabY, "red");
    }

    if (td.nextCell) {
        ctx.FillRect(td.nextCell->x + drawDeltaX, td.nextCell->y + drawDeltaY, td.nextCell->gabX, td.nextCell->gabY, "blue");
    }

     if (td.clicckedCell) {
        ctx.FillRect(td.clicckedCell->x + drawDeltaX, td.clicckedCell->y + drawDeltaY, td.clicckedCell->gabX, td.clicckedCell->gabY, "yellow");
     }

    }

                    //                     dc->cellsOnDraw.forEach([drawDeltaY, &DA, &max, this](Array<Cell *> &drawLine)
                    //                             { drawLine.forEach([drawDeltaY, &DA, &max, this](Cell *cell)
                    //                                                {

                    //   float drawDeltaX = this->gf->drawDeltaX;
                    //   float drawDeltaY = this->gf->drawDeltaY;
                    //   ctx.DrawText(cell->x +drawDeltaX, cell->y + drawDeltaY, 20, to_string(cell->activeZoneIndex));
                             
                    //  }); });

                             

        /////////  setka
        // this->gf->drawCell->cellsOnDraw.forEach([drawDeltaX, drawDeltaY](Array<ProtoObj *> drawLine)
        //                                         { drawLine.forEach([drawDeltaX, drawDeltaY](ProtoObj *cell)
        //                                                            {
        //                                                             ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY, "yellow");
        //                                                           //  ctx.DrawText(cell->x + drawDeltaX, cell->y + drawDeltaY + 10, 10, "v= " + to_string((int)cell->ver));
        //                                                           //  ctx.DrawText(cell->x + drawDeltaX, cell->y + drawDeltaY + 20, 10, "h= " + to_string((int)cell->hor));
        //                                                             }); });


    //    this->gf->clasters.forEach([drawDeltaX, drawDeltaY](Claster &cl){
    //        ctx.StrokeRect(cl.x + drawDeltaX, cl.y + drawDeltaY, cl.size, cl.size, "red");
    //    });

    // this->gf->clasters.forEach([drawDeltaX, drawDeltaY](Array<Claster> &line){
    //     line.forEach([drawDeltaX, drawDeltaY](Claster *cl){
    //         ctx.StrokeRect(cl->x + drawDeltaX, cl->y + drawDeltaY, cl->size, cl->size, "red");
    //         //console.log("cl.length = ", cl->zones.length);
    //             cl->zones.forEach([&drawDeltaX, &drawDeltaY](Zone *z, int i){
    //     string color = "";
    //     if (!i) {
    //         color = "red";
    //     } else if (i == 1) {
    //         color = "green";
    //     } else if (i == 2) {
    //         color = "yellow";
    //     } else if (i == 3) {
    //         color = "blie";
    //     } else if (i == 4) {
    //         color = "black";
    //     }
    //     z->cells.forEach([&drawDeltaX, &drawDeltaY, &color](Cell *c){
    //         ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100);
    //     });
    // });
    //     });
    // });


    
//      Claster *cl = this->gf->clasters.getItemLnk(1).getItemPtr(1);

// //    //  console.log("g = ", cl->aroundClasters_G.length);
// //     // console.log("length = ", cl->aroundClasters.length);

//     ctx.StrokeRect(cl->x + drawDeltaX, cl->y + drawDeltaY, cl->size, cl->size, "violet");

//    // console.log("z.length = ", cl->zones.length);
//     cl->zones.forEach([&drawDeltaX, &drawDeltaY](Zone *z, int i){
//         string color = "";
//         if (!i) {
//             color = "red";
//         } else if (i == 1) {
//             color = "green";
//         } else if (i == 2) {
//             color = "yellow";
//         } else if (i == 3) {
//             color = "blie";
//         } else if (i == 4) {
//             color = "black";
//         }
//         z->cells.forEach([&drawDeltaX, &drawDeltaY, &color](Cell *c){
//             ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100);
//         });
//     });

    // cl->cells.forEach([&drawDeltaX, &drawDeltaY](Cell *c, int i){
    //     if (c->ok) {
    //         ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, "black");
    //         ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(i));
    //     }
    // });

    // cl->aroundClasters.forEach([&drawDeltaX, &drawDeltaY, cl](Claster *acl, int i){
    //     ctx.StrokeRect(acl->x + drawDeltaX, acl->y + drawDeltaY, acl->size, acl->size, "red");
    //     int num = cl->aroundClasters_G.getItem(i);
    //     ctx.DrawText(acl->cell->x + drawDeltaX, acl->cell->y + drawDeltaY, 20, to_string(num));
    // });
     

    ctx.CreateDrawZone(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight);
    ctx.FillRect(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight, "black");

    ctx.CreateDrawZone(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT);
    ctx.FillRect(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT, "black");

  //  this->fonMenuDraw();
    this->gf->miniMapDraw();

   // this->objMenu->draw();

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
     
   // ctx.FillRect(gf->dx, gf->dy, 3, 3, "blue");
                            }
}