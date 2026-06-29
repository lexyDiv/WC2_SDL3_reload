#include "cellsIteration.cpp"
//=> getMaxAroundCellsDis

void recAroundCellsCont(Array<Cell *> &frash, GameField *gf)
{
    Array<Cell *> reFrash;
    for (int i = 0; i < frash.length; i++)
    {
        Cell *cell = frash.getItem(i);
        for (int k = 0; k < cell->aroundCells.length; k++)
        {
            Cell *ac = cell->aroundCells.getItem(k);
            if (ac->litera != 'w' && ac->litera != '9' && !ac->plane)
            {
                ac->plane = cell->plane;
                ac->plane->cells.push(ac);
                reFrash.push(ac);
            }
        }
    }
    if (!reFrash.length)
    {
        return;
    }
    recAroundCellsCont(reFrash, gf);
};

void recAroundCellsSea(Array<Cell *> &frash, GameField *gf)
{
    Array<Cell *> reFrash;
    for (int i = 0; i < frash.length; i++)
    {
        Cell *cell = frash.getItem(i);
        for (int k = 0; k < cell->aroundCells.length; k++)
        {
            Cell *ac = cell->aroundCells.getItem(k);
            if ((ac->litera == 'w' || ac->litera == '9') && !ac->plane)
            {
                ac->plane = cell->plane;
                ac->plane->cells.push(ac);
                reFrash.push(ac);
            }
        }
    }
    if (!reFrash.length)
    {
        return;
    }
    recAroundCellsSea(reFrash, gf);
};

void GameField::getContinents()
{
    int gCont = 1;
    int gSea = 1;

    for (int ver = 0; ver < this->field.length; ver++)
    {
        Array<Cell *> &arr = this->field.getItemLnk(ver);
        for (int hor = 0; hor < arr.length; hor++)
        {
            Cell *cell = arr.getItem(hor);
            if (cell->litera != 'w' && cell->litera != '9' && !cell->plane)
            {
                Plane *plane = new Plane;
                plane->type = "ground";
                this->planes.push(plane);
                cell->plane = plane;
                cell->plane->cells.push(cell);
                plane->number = gCont;
                gCont++;
                Array<Cell *> frash;
                for (int i = 0; i < cell->aroundCells.length; i++)
                {
                    Cell *ac = cell->aroundCells.getItem(i);
                    if (ac->litera != 'w' && ac->litera != '9')
                    {
                        ac->plane = cell->plane;
                        ac->plane->cells.push(ac);
                        frash.push(ac);
                    }
                }
                if (frash.length)
                {
                    recAroundCellsCont(frash, this);
                }
            }
            else if ((cell->litera == 'w' || cell->litera == '9') && !cell->plane)
            {
                Plane *plane = new Plane;
                plane->type = "sea";
                this->planes.push(plane);
                cell->plane = plane;
                cell->plane->cells.push(cell);
                plane->number = gSea;
                gSea++;
                Array<Cell *> frash;
                for (int i = 0; i < cell->aroundCells.length; i++)
                {
                    Cell *ac = cell->aroundCells.getItem(i);
                    if (ac->litera == 'w' || ac->litera == '9')
                    {
                        ac->plane = cell->plane;
                        ac->plane->cells.push(ac);
                        frash.push(ac);
                    }
                }
                if (frash.length)
                {
                    recAroundCellsSea(frash, this);
                }
            }
        }
    }

    this->planes.forEach([this](Plane *plane)
                         { plane->cells.forEach([this, &plane](Cell *cell)
                                                {
         int aclength = cell->aroundCells.length;
         for (int i = 0; i < aclength; i++) {
            Cell *ac = cell->aroundCells.getItem(i);
            if (ac->plane != cell->plane) {
               ToOtherPlane *op = plane->contactPlanes.find([ac](ToOtherPlane *item){
                  return item->otherPlane == ac->plane;
               });
 
               if (op == nullptr) {
                  op = new ToOtherPlane; 
                  op->otherPlane = ac->plane;
                  plane->contactPlanes.push(op);
               }
               cell->lineToOtherPlaneNumber = 1;
               op->cellsToOther.push(cell);
               break;
            }
         } }); });
}