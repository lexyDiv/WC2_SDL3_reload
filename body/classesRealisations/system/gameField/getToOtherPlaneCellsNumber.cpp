#include "getMaxAroundCellsDis.cpp"
//=> getToTreeCellLineNumber

void GameField::getToOtherPlaneCellsNumber()
{
    this->planes.forEach([](Plane *plane)
                         { plane->contactPlanes.forEach([plane](ToOtherPlane *op)
                                                        { op->cellsToOther.forEach([plane](Cell *cell)
                                                                                   { cell->aroundCells.forEach([plane](Cell *contactCell)
                                                                                                               {
              if (!contactCell->lineToOtherPlaneNumber &&
              contactCell->plane == plane) {
                 contactCell->lineToOtherPlaneNumber = 2;
                 contactCell->aroundCells.forEach([plane](Cell* ac){
                  if (!ac->lineToOtherPlaneNumber && plane->type != "sea") {
                     ac->lineToOtherPlaneNumber = 2;
                  }
                 });
              } }); }); }); });
};