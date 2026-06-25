#include "getVectorCells.cpp"
//=>miniMapMouseControl

void GameField::getCellImageCellDrawIndexCellUnitInit()
{

   int powGab = this->gabarit * this->gabarit;



    this->field.forEach([this](Array<Cell *> &line)
                        { line.forEach([this](Cell *cell, int i)
                                       {     
                                           if (cell->litera == '0' || cell->litera == 'S')
                                           {
                                               if (

                                                   // && !cell->lineToTreeNumber
                                                   !cell->lineToOtherPlaneNumber && !cell->LineToMountNumber
                                                   //  && !cell->lineToDarckGround
                                               )
                                               {

                                                   int rnd = intRand(0, 2);
                                                   Image *img = !rnd ? imager.groundBasic : imager.groundBasic1;

                                                   cell->cellImage = img;
                                                   cell->animX = 100 * intRand(0, 30);
                                                   cell->animY = 0;
                                                   cell->animGabX = 100;
                                                   cell->animGabY = 100;
                                                   cell->cellDrawIndex = 2;
                                               }
                                               else if (cell->lineToOtherPlaneNumber)
                                               {
                                                   Image *img = cell->lineToOtherPlaneNumber == 1 ? imager.pesok1 : imager.pesok2;
                                                   cell->cellImage = img;
                                                   cell->animX = 100 * intRand(0, 5);
                                                   cell->animY = 0;
                                                   cell->animGabX = 100;
                                                   cell->animGabY = 100;
                                                   cell->cellDrawIndex = cell->lineToOtherPlaneNumber == 1 ? 1 : 0;
                                                   // cell->drawGabaritX = cell->lineToOtherPlaneNumber == 1 ? 100 : 100;
                                                   // cell->drawGabaritY = cell->drawGabaritX;
                                               }
                                           }

                                           if (cell->lineToDarckGround == 1)
                                           {
                                               cell->cellImage = imager.groundBasicDarck;
                                               cell->animX = 100 * intRand(0, 30);
                                               cell->animY = 0;
                                               cell->animGabX = 100;
                                               cell->animGabY = 100;
                                               cell->cellDrawIndex = 3;
                                           }
                                           else if (cell->lineToDarckGround == 2)
                                           {
                                               cell->cellImage = imager.groundBasicDarck1;
                                               cell->animX = 100 * intRand(0, 30);
                                               cell->animY = 0;
                                               cell->animGabX = 100;
                                               cell->animGabY = 100;
                                               cell->cellDrawIndex = 3;
                                           }

                                           if (cell->litera == 't')
                                           {
                                               cell->cellImage = imager.underWood;
                                               cell->animX = 100 * intRand(0, 60);
                                               cell->animY = 0;
                                               cell->animGabX = 100;
                                               cell->animGabY = 100;
                                               cell->cellDrawIndex = 1;
                                           }

                                           if (!cell->lineToOtherPlaneNumber)
                                           {
                                               if (cell->lineToTreeNumber == 1)
                                               {
                                                   cell->cellImage = imager.aroundWood1;
                                                   cell->animX = 100 * intRand(0, 30);
                                                   cell->animY = 0;
                                                   cell->animGabX = 100;
                                                   cell->animGabY = 100;
                                                   cell->cellDrawIndex = 2;
                                               }
                                               else if (cell->lineToTreeNumber == 2)
                                               {
                                                   cell->cellImage = imager.aroundWood2;
                                                   cell->animX = 100 * intRand(0, 30);
                                                   cell->animY = 0;
                                                   cell->animGabX = 100;
                                                   cell->animGabY = 100;
                                                   cell->cellDrawIndex = 3;
                                               }
                                           }

                                           if (cell->LineToMountNumber)
                                           {
                                               Image *img = cell->LineToMountNumber == 1 ? imager.mount1 : imager.mount2;
                                               cell->cellImage = img;
                                               cell->animX = 100 * intRand(0, 12);
                                               cell->animY = 0;
                                               cell->animGabX = 100;
                                               cell->animGabY = 100;
                                               cell->cellDrawIndex = 0;
                                           }

                                           if (cell->litera == 'w')
                                           {
                                               cell->cellImage = imager.ocean;
                                               Water *water1 = new Water;
                                               Water *water2 = new Water;
                                               int rand = intRand(0, 2);
                                               water1->alpha = rand ? 250 : 0;
                                               water2->alpha = rand ? 0 : 250;
                                               int checkTakt = intRand(1, 3);
                                               water1->checkTakt = checkTakt;
                                               water2->checkTakt = checkTakt;
                                               cell->waters.push(water1);
                                               cell->waters.push(water2);
                                               water1->animX = 100 * intRand(0, 8);
                                               water1->animY = cell->lineToOtherPlaneNumber ? 100 : 0;
                                               water2->animX = 100 * intRand(0, 8);
                                               water2->animY = cell->lineToOtherPlaneNumber == 1 ? 100 : 0;
                                               cell->animGabX = 100;
                                               cell->animGabY = 100;
                                               cell->cellDrawIndex = cell->lineToOtherPlaneNumber == 1 ? 3 : 2;
                                           }
                                       }); });

    this->field.forEach([](Array<Cell *> arr)
                        { arr.forEach([](Cell *cell)
                                      {
                                          for (int i = 0; i <= 3; i++)
                                          {
                                              Array<Cell *> arr;
                                              cell->drawCells.forEach([i, &arr](Cell *dc)
                                                                      {
                if (dc->cellDrawIndex == i) {
                    arr.push(dc);
                } });
                                              cell->cellsOnDraw.push(arr);
                                          }

                                          cell->drawCells.clear();
                                      }); });
}