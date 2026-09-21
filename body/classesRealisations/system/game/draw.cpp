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
                    cell->isDraw = true;                                                                   
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
                                                   { cell->ripUnits.forEach([](Unit *trup)
                                                                            { trup->drawTrup(); }); }); });

        DA.forEach([](Array<Unit *> &line)
                   { line.forEach([](Unit *unit)
                                  { unit->draw(); }); });

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

        // ThData *thd = thDatas.getItem(0);
        // thd->openArrMag.forEach([&drawDeltaX, &drawDeltaY, this](MagistralClaster *mc){
        //    ctx.StrokeRect(mc->x + drawDeltaX, mc->y + drawDeltaY, mc->gabarit, mc->gabarit, "red");
        //    mc->thwd_mag.getItemPtr(0)->validCellsForWayFather.forEach([&drawDeltaX, &drawDeltaY, this](Cell *c){
        //     ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "violet", 100);
        //    });
        // });

        ///////////////////////////////////////////////////////////////////////////////////// => magistral way

        if (this->gf->focusUnit)
        {
            Unit *u = this->gf->focusUnit;
            TargetData &td = u->targetData;
            // u->way
            td.magistralWay
                .forEach([&drawDeltaX, &drawDeltaY, this](Cell *c, int i)
                         {
                             ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "black", 50);
                             // ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "blue", 50);
                             //  ctx.DrawText(mc->x + 40 + i + drawDeltaX, mc->y + 40 + i + drawDeltaY, 20, to_string(i));
                         });

        if (td.prevMagCell) {
            Cell *c = td.prevMagCell;
            ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "red", 50);
        }

         if (td.nextMagCell) {
            Cell *c = td.nextMagCell;
            ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "blue", 50);
        }

        }

        // this->allMagistralClasters.forEach([&drawDeltaX, &drawDeltaY, this](Array<MagistralClaster> &mca)
        //                                    { mca.forEach([&drawDeltaX, &drawDeltaY, this](MagistralClaster &mc)
        //                                                  {
        //                      ctx.StrokeRect(mc.x + drawDeltaX, mc.y + drawDeltaY, mc.gabarit, mc.gabarit, "blue", 100);
        //     // ctx.DrawText(mc.x + drawDeltaX, mc.y + drawDeltaY, 20, to_string(mc.ver));
        //     }); });

        // ThData *td = thDatas.getItem(0);
        // td->openArrMag.forEach([&drawDeltaX, &drawDeltaY, this](MagistralClaster *mc)
        //                        {
        //                            ctx.FillRect(mc->x + drawDeltaX, mc->y + drawDeltaY, mc->gabarit, mc->gabarit, "green", 100);
        //                            Td_way_data_magistral *tdm = mc->thwd_mag.getItemPtr(0);
        //                            ctx.DrawText(mc->x + drawDeltaX + 20, mc->y + drawDeltaY + 20, 10, "F = " + to_string(tdm->F));
        //                            ctx.DrawText(mc->x + drawDeltaX + 20, mc->y + drawDeltaY + 50, 10, "G = " + to_string(tdm->G));
        //                            ctx.DrawText(mc->x + drawDeltaX + 20, mc->y + drawDeltaY + 80, 10, "H = " + to_string(tdm->H));
        //                            //  ctx.DrawText(mc->centralCell->x + drawDeltaX, mc->centralCell->y + drawDeltaY + 80, 10, "num = " + to_string(mc->centralCell->persNum));

        //                            // mc->validCellsToFather.forEach([&drawDeltaX, &drawDeltaY, this](Cell *c){
        //                            //     ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "yellow", 50);
        //                            //     ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "blue", 100);
        //                            // });

        //                            if (mc->father)
        //                            {
        //                            } });

        // td->cam.forEach([&drawDeltaX, &drawDeltaY, this](MagistralClaster *mc)
        //                 {
        //     ctx.FillRect(mc->x + drawDeltaX, mc->y + drawDeltaY, mc->gabarit, mc->gabarit, "red", 100);
        //      Td_way_data_magistral *tdm = mc->thwd_mag.getItemPtr(0);
        //     ctx.DrawText(mc->x + drawDeltaX + 20, mc->y + drawDeltaY + 20, 10, "F = " + to_string(tdm->F));
        //     ctx.DrawText(mc->x + drawDeltaX + 20, mc->y + drawDeltaY + 50, 10, "G = " + to_string(tdm->G));
        //     ctx.DrawText(mc->x + drawDeltaX + 20, mc->y + drawDeltaY + 80, 10, "H = " + to_string(tdm->H));
        //     ctx.DrawText(mc->centralCell->x + drawDeltaX, mc->centralCell->y + drawDeltaY + 80, 10, "num = " + to_string(mc->centralCell->persNum)); });

        // if (td->min_F_mc)
        // {
        //     ctx.StrokeRect(td->min_F_mc->x + drawDeltaX, td->min_F_mc->y + drawDeltaY, td->min_F_mc->gabarit, td->min_F_mc->gabarit, "violet");
        // }

        // if (this->gf->focusUnit)
        // {
        //     Unit *u = this->gf->focusUnit;
        //     Cell *c = u->targetData.clicckedCell;
        //     if (c)
        //     {
        //         ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "blue");
        //     }
        // }

        /////////////////////////////////////////////////////////////////////////////////// <== magistral way

        ///////////////////////////////////////////////////////////////////////////////////// => CLASSIC way

        if (this->gf->focusUnit)
        {
            Unit *u = this->gf->focusUnit;
            // u->way
           // u->way
           u->targetData.magistralWay
                .forEach([&drawDeltaX, &drawDeltaY, this](Cell *c, int i)
                         {
                             ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "black");
                             // ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "blue", 50);
                             //  ctx.DrawText(mc->x + 40 + i + drawDeltaX, mc->y + 40 + i + drawDeltaY, 20, to_string(i));
                         });
        }

//         // this->allMagistralClasters.forEach([&drawDeltaX, &drawDeltaY, this](Array<MagistralClaster> &mca)
//         //                                    { mca.forEach([&drawDeltaX, &drawDeltaY, this](MagistralClaster &mc)
//         //                                                  {
//         //                      ctx.StrokeRect(mc.x + drawDeltaX, mc.y + drawDeltaY, mc.gabarit, mc.gabarit, "blue", 100);
//         //     // ctx.DrawText(mc.x + drawDeltaX, mc.y + drawDeltaY, 20, to_string(mc.ver));
//         //     }); });

//         td = thDatas.getItem(0);
//         td->openArr.forEach([&drawDeltaX, &drawDeltaY, this](Cell *c)
//                             {

// if (c->isDraw) {
//     c->isDraw = false;
//     Td_way_data *tdm = c->thwd.getItemPtr(0);

// if (tdm->wayFather) {
//     Cell *f = tdm->wayFather;
//     float dx = 0.0F;
//     float dy = 0.0F;
//     if (f == c->top) {
//           dx = c->gf->cellSize / 2 - 2;
//     } else  if (f == c->bottom) {
//           dx = c->gf->cellSize / 2 - 2;
//           dy = c->gf->cellSize - 5;
//     } else  if (f == c->left) {
//           dx = 0; //c->gf->cellSize / 2 - 2;
//           dy = c->gf->cellSize / 2 - 2;
//     } else  if (f == c->right) {
//           dx = c->gf->cellSize - 4;
//           dy = c->gf->cellSize / 2 - 4;
//     } 
    
//     // else  if (f == c->top_left) {
//     //       dx = c->gf->cellSize - 4;
//     //       dy = c->gf->cellSize / 2 - 4;
//     // }
//      else  if (f == c->top_right ) {
//           dx = c->gf->cellSize - 4;
//           dy = 0; //c->gf->cellSize / 2 - 4;
//     } else  if (f == c->bottom_right ) {
//           dx = c->gf->cellSize - 4;
//           dy = c->gf->cellSize - 4;
//     } else  if (f == c->bottom_left ) {
//           dx = 0; //c->gf->cellSize - 4;
//           dy = c->gf->cellSize - 4;
//     }

// ctx.FillRect(c->x + drawDeltaX + dx, c->y + drawDeltaY + dy, 4, 4, "red");
   

// }
                                
//                                    ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gf->cellSize, c->gf->cellSize, "green", 100);
//                                    ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gf->cellSize, c->gf->cellSize, "blue", 50);
                                   
//                                    ctx.DrawText(c->x + drawDeltaX + 2, c->y + drawDeltaY + 2, 8, "F " + to_string(tdm->F));
//                                    ctx.DrawText(c->x + drawDeltaX + 2, c->y + drawDeltaY + 14, 8, "G " + to_string(tdm->G));
//                                    ctx.DrawText(c->x + drawDeltaX + 2, c->y + drawDeltaY + 30, 8, "H " + to_string(tdm->H));
//                                    //  ctx.DrawText(mc->centralCell->x + drawDeltaX, mc->centralCell->y + drawDeltaY + 80, 10, "num = " + to_string(mc->centralCell->persNum));

//                                    // mc->validCellsToFather.forEach([&drawDeltaX, &drawDeltaY, this](Cell *c){
//                                    //     ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "yellow", 50);
//                                    //     ctx.StrokeRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "blue", 100);
//                                    // });

// }
//                               });

//         td->bu.forEach([&drawDeltaX, &drawDeltaY, this](Cell *c)
//                        {
// if (c->isDraw) {
//     c->isDraw = false;
// Td_way_data *tdm = c->thwd.getItemPtr(0);

// if (tdm->wayFather) {
//     Cell *f = tdm->wayFather;
//     float dx = 0.0F;
//     float dy = 0.0F;
//     if (f == c->top) {
//           dx = c->gf->cellSize / 2 - 2;
//     } else  if (f == c->bottom) {
//           dx = c->gf->cellSize / 2 - 2;
//           dy = c->gf->cellSize - 5;
//     } else  if (f == c->left) {
//           dx = 0; //c->gf->cellSize / 2 - 2;
//           dy = c->gf->cellSize / 2 - 2;
//     } else  if (f == c->right) {
//           dx = c->gf->cellSize - 4;
//           dy = c->gf->cellSize / 2 - 4;
//     } 
    
//     // else  if (f == c->top_left) {
//     //       dx = c->gf->cellSize - 4;
//     //       dy = c->gf->cellSize / 2 - 4;
//     // }
//      else  if (f == c->top_right ) {
//           dx = c->gf->cellSize - 4;
//           dy = 0; //c->gf->cellSize / 2 - 4;
//     } else  if (f == c->bottom_right ) {
//           dx = c->gf->cellSize - 4;
//           dy = c->gf->cellSize - 4;
//     } else  if (f == c->bottom_left ) {
//           dx = 0; //c->gf->cellSize - 4;
//           dy = c->gf->cellSize - 4;
//     }

// ctx.FillRect(c->x + drawDeltaX + dx, c->y + drawDeltaY + dy, 4, 4, "red");
   

// }
    
//                 ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, c->gf->cellSize, c->gf->cellSize, "red", 100);
//             // Td_way_data *tdm = c->thwd.getItemPtr(0);
//                                    ctx.DrawText(c->x + drawDeltaX + 2, c->y + drawDeltaY + 2, 8, "F " + to_string(tdm->F));
//                                    ctx.DrawText(c->x + drawDeltaX + 2, c->y + drawDeltaY + 14, 8, "G " + to_string(tdm->G));
//                                    ctx.DrawText(c->x + drawDeltaX + 2, c->y + drawDeltaY + 30, 8, "H " + to_string(tdm->H));
// }
//            // ctx.DrawText(mc->centralCell->x + drawDeltaX, mc->centralCell->y + drawDeltaY + 80, 10, "num = " + to_string(mc->centralCell->persNum)); 
//         });

//         if (td->min_F_cell)
//         {
//             ctx.StrokeRect(td->min_F_cell->x + drawDeltaX, td->min_F_cell->y + drawDeltaY, td->min_F_cell->gf->cellSize, td->min_F_cell->gf->cellSize, "violet");
//         }

//         if (this->gf->focusUnit)
//         {
//             Unit *u = this->gf->focusUnit;
//             Cell *c = u->targetData.clicckedCell;
//             if (c)
//             {
//                 ctx.FillRect(c->x + drawDeltaX, c->y + drawDeltaY, this->gf->cellSize, this->gf->cellSize, "blue");
//             }
//         }

        /////////////////////////////////////////////////////////////////////////////////// <== CLASSIC way

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