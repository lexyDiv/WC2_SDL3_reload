#include "create.cpp"
//=>preDraw

void Game::draw()
{

    if (!this->isGFComplite)
    {
        return;
    }

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
                    } }); });

        dc->cellsOnDraw.forEach([drawDeltaY, &DA, &max](Array<Cell *> &drawLine)
                                { drawLine.forEach([drawDeltaY, &DA, &max](Cell *cell)
                                                   {
                                                       cell->ripUnits.forEach([](Unit *trup)
                                                                              { trup->drawTrup(); });
                                                   }); });

        DA.forEach([](Array<Unit *> &line)
                   { line.forEach([](Unit *unit)
                                  { unit->draw(); }); });

        Unit *u = this->gf->focusUnit;
        if (u && u->cell)
        {
            string m = u->targetData.isZones ? "M" : "";
            // console.log(to_string(u->needHolTimer));
            ctx.StrokeRect(u->x + drawDeltaX, u->y + drawDeltaY, u->cell->gabX, u->cell->gabY, "blue");

            u->way.forEach([this, &drawDeltaX, &drawDeltaY](Cell *c)
                           { ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabY, "violet", 100); });

            u->targetData.magistral.forEach([this, &drawDeltaX, &drawDeltaY, &m](Cell *c, int i)
                                            {
    ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabY, "black", 100);

        
    ctx.DrawText(c->x +drawDeltaX + 5, c->y + drawDeltaY + 5, 10, m);
});

            TargetData &td = u->targetData;

            // if (td.prevCell)
            // {
            //     ctx.FillRect(td.prevCell->x + drawDeltaX, td.prevCell->y + drawDeltaY, td.prevCell->gabX, td.prevCell->gabY, "red");
            //     ctx.DrawText(td.prevCell->x +drawDeltaX + 5, td.prevCell->y + drawDeltaY + 5, 10, m);
            // }

            // if (td.nextCell)
            // {
            //     ctx.FillRect(td.nextCell->x + drawDeltaX, td.nextCell->y + drawDeltaY, td.nextCell->gabX, td.nextCell->gabY, "blue");
            //     ctx.DrawText(td.nextCell->x +drawDeltaX + 5, td.nextCell->y + drawDeltaY + 5, 10, m);
            // }

            if (td.clicckedCell)
            {
                ctx.FillRect(td.clicckedCell->x + drawDeltaX, td.clicckedCell->y + drawDeltaY, td.clicckedCell->gabX, td.clicckedCell->gabY, "yellow");
            }
        }

//////////////////////////////////////////////////////////////////////////// => focusClaster





// if (this->gf->focusClaster) {
//     Claster *cl = this->gf->focusClaster;


//         cl->zones.forEach([&drawDeltaX, &drawDeltaY](Zone *z, int i)
//                           {
//                               string color = "";
//                               if (!i)
//                               {
//                                   color = "red";
//                               }
//                               else if (i == 1)
//                               {
//                                   color = "violet";
//                               }
//                               else if (i == 2)
//                               {
//                                   color = "yellow";
//                               }
//                               else if (i == 3)
//                               {
//                                   color = "blue";
//                               }
//               ctx.DrawText(z->cell->x + drawDeltaX, z->cell->y + drawDeltaY, 20, to_string(i)); // index of zone
//               //ctx.FillRect(z->cell->x + drawDeltaX, z->cell->y + drawDeltaY, z->cell->gabX, z->cell->gabX, "black");
//                               z->cells.forEach([&drawDeltaX, &drawDeltaY, &color](Cell *c, int i)
//                                                { 
//             ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100); 
//            // ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(i));
//                                             });

//                               z->contactZones.forEach([&drawDeltaX, &drawDeltaY, &color](Zone *cz, int i)
//                                                       {

                                                        
//            cz->cells.forEach([&drawDeltaX, &drawDeltaY, &i, &color](Cell *c, int k){
//             //ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(k));
//             ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100);
//            });
//     //ctx.FillRect(cz->cell->x + drawDeltaX, cz->cell->y + drawDeltaY, cz->cell->gabX, cz->cell->gabX, "black"); 
//   // ctx.DrawText(cz->cell->x + drawDeltaX, cz->cell->y + drawDeltaY, 20, to_string(i));
//        string isActive = cz->isTeesNear ? "have tree" : "NO trees ! ";
//     ctx.DrawText(cz->cell->x + drawDeltaX, cz->cell->y + drawDeltaY, 20, isActive + to_string(cz->num));
// });

//     string isActive = z->isTeesNear ? "have tree " : "NO trees ! ";
//     ctx.DrawText(z->cell->x + drawDeltaX, z->cell->y + drawDeltaY, 20, isActive + to_string(z->num));
//                           });

// ctx.StrokeRect(cl->x + drawDeltaX, cl->y + drawDeltaY, cl->size, cl->size, "black"); // contur
// ctx.DrawText(cl->x + drawDeltaX, cl->y + drawDeltaY + 30, 20, "num = " + to_string(cl->num));
// }


//////////////////////////////////////////////////////////////////////////// <= focusClaster


// dc->cellsOnDraw.forEach([&drawDeltaX, &drawDeltaY](Array<Cell *> &line){
//     line.forEach([&drawDeltaX, &drawDeltaY](Cell *c){

//        if (!c->groundUnit || c->groundUnit->type == "life") {
//          if (!c->zone) {
//            // ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, "red", 150);
//             ctx.StrokeRect(c->claster->x + drawDeltaX, c->claster->y + drawDeltaY, c->claster->size, c->claster->size, "blue", 150);
//             Claster *cl = c->claster;
//                     cl->zones.forEach([&drawDeltaX, &drawDeltaY](Zone *z, int i)
//                           {
//                               string color = "";
//                               if (!i)
//                               {
//                                   color = "red";
//                               }
//                               else if (i == 1)
//                               {
//                                   color = "violet";
//                               }
//                               else if (i == 2)
//                               {
//                                   color = "yellow";
//                               }
//                               else if (i == 3)
//                               {
//                                   color = "blue";
//                               }
//                               else if (i == 4)
//                               {
//                                   color = "black";
//                               }

//                               z->cells.forEach([&drawDeltaX, &drawDeltaY, &color](Cell *c)
//                                                { ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100); });

//                               z->contactZones.forEach([&drawDeltaX, &drawDeltaY, &color](Zone *cz, int i)
//                                                       {
//             //console.log(cz->cells.length);
//            // ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(i));
//            cz->cells.forEach([&drawDeltaX, &drawDeltaY, &i, &color](Cell *c, int k){
//            // ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(k));
//             ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100);
//            });
//     ctx.FillRect(cz->cell->x + drawDeltaX, cz->cell->y + drawDeltaY, cz->cell->gabX, cz->cell->gabX, "black"); });
//                               // console.log("----------------------------------");
//                           });

//          ctx.DrawText(c->x + drawDeltaX + 5, c->y + drawDeltaY + 5, 15, "NO!");  
//          ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, "black");               
//          }
//        }

//     });
// });



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

    //     this->gf->clasters.forEach([drawDeltaX, drawDeltaY](Array<Claster *> &line)
    //                                { line.forEach([drawDeltaX, drawDeltaY](Claster *cl)
    //                                               {
    //  ctx.StrokeRect(cl->x + drawDeltaX, cl->y + drawDeltaY, cl->size, cl->size, "violet");

    // cl->zones.forEach([&drawDeltaX, &drawDeltaY](Zone *z, int i){
    //     string color = "";
    //     if (!i) {
    //         color = "red";
    //     } else if (i == 1) {
    //         color = "violet";
    //     } else if (i == 2) {
    //         color = "yellow";
    //     } else if (i == 3) {
    //         color = "blue";
    //     } else if (i == 4) {
    //         color = "black";
    //     }

    //     z->cells.forEach([&drawDeltaX, &drawDeltaY, &color](Cell *c){
    //         ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100);
    //     });

    //     z->contactZones.forEach([&drawDeltaX, &drawDeltaY, &color](Zone *cz, int i){
    //         //console.log(cz->cells.length);
    //        // ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(i));
    //        cz->cells.forEach([&drawDeltaX, &drawDeltaY, &i, &color](Cell *c, int k){
    //        // ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(k));
    //         ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100);
    //        });
    // ctx.FillRect(cz->cell->x + drawDeltaX, cz->cell->y + drawDeltaY, cz->cell->gabX, cz->cell->gabX, "black");
    //     });
    //    // console.log("----------------------------------");
    // }); }); });

        // Claster *cl = this->gf->clasters.getItemLnk(1).getItemPtr(3);


         
        //  //console.log(cl->aroundClasters.length);
        //  cl->aroundClasters.forEach([&drawDeltaX, &drawDeltaY, cl](Claster *acl, int i){
        //     ctx.StrokeRect(acl->x + drawDeltaX, acl->y + drawDeltaY, acl->size, acl->size, "red");
        //     int G = cl->aroundClasters_G.getItem(i);
        //     ctx.DrawText(acl->cell->x + drawDeltaX, acl->cell->y + drawDeltaY, 20, to_string(G));
        //  });

        //  ctx.StrokeRect(cl->x + drawDeltaX, cl->y + drawDeltaY, cl->size, cl->size, "black");

    //     cl->zones.forEach([&drawDeltaX, &drawDeltaY](Zone *z, int i)
    //                       {
    //                           string color = "";
    //                           if (!i)
    //                           {
    //                               color = "red";
    //                           }
    //                           else if (i == 1)
    //                           {
    //                               color = "violet";
    //                           }
    //                           else if (i == 2)
    //                           {
    //                               color = "yellow";
    //                           }
    //                           else if (i == 3)
    //                           {
    //                               color = "blue";
    //                           }
    //                           else if (i == 4)
    //                           {
    //                               color = "black";
    //                           }

    //                           z->cells.forEach([&drawDeltaX, &drawDeltaY, &color](Cell *c)
    //                                            { ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100); });

    //                           z->contactZones.forEach([&drawDeltaX, &drawDeltaY, &color](Zone *cz, int i)
    //                                                   {
    //         //console.log(cz->cells.length);
    //        // ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(i));
    //        cz->cells.forEach([&drawDeltaX, &drawDeltaY, &i, &color](Cell *c, int k){
    //         ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(k));
    //         ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gabX, c->gabX, color, 100);
    //        });
    // ctx.FillRect(cz->cell->x + drawDeltaX, cz->cell->y + drawDeltaY, cz->cell->gabX, cz->cell->gabX, "black"); });
    //                           // console.log("----------------------------------");
    //                       });

        // console.log(cl->zones.getItem(0).contactZones.length);
        // cl->zones.getItemPtr(0)->contactZones.forEach([&drawDeltaX, &drawDeltaY](Zone *z, int i){
        //     if (!z) {
        //         console.log("no");
        //     }
        // //   z->cells.forEach([&drawDeltaX, &drawDeltaY, i](Cell *c){
        // //    // ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY, 20, to_string(i));
        // //   });
        // });

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