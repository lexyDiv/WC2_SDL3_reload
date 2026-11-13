#include "upgrade.cpp"
//=>out

bool TownHall::get4x4myCells(Cell *cell)
{

    this->myCells.clear();
    this->notValidMyCells.clear();
    Array<Cell *> cells;

    // this->myCells.push(cell);
    // this->myCells.push(cell->right);
    // this->myCells.push(cell->right->right);
    // this->myCells.push(cell->right->right->right);

    cells.push(cell);
    Cell *cell2 = cell->right ? cell->right : nullptr;
    cells.push(cell2);
    Cell *cell3 = cell2 && cell2->right ? cell2->right : nullptr;
    cells.push(cell3);
    Cell *cell4 = cell3 && cell3->right ? cell3->right : nullptr;
    cells.push(cell4);

    for (int i = 0; i < 4; i++)
    {
        Cell *cl = cells.getItem(i);
        if (cl)
        {
            if (!cl->groundUnit &&
                !cl->stopBuild &&
                !cl->shahtsNear.length &&
                cl->litera != 'w')
            {
                this->myCells.push(cl);
            }
            else
            {
                this->notValidMyCells.push(cl);
            }
            Cell *clb = cl->bottom;
            if (clb)
            {
                if (!clb->groundUnit &&
                    !clb->stopBuild &&
                    !clb->shahtsNear.length &&
                    clb->litera != 'w')
                {
                    this->myCells.push(clb);
                }
                else
                {
                    this->notValidMyCells.push(clb);
                }
                Cell *clbb = clb->bottom;
                if (clbb)
                {
                    if (!clbb->groundUnit &&
                        !clbb->stopBuild &&
                        !clbb->shahtsNear.length &&
                        clbb->litera != 'w')
                    {
                        this->myCells.push(clbb);
                    }
                    else
                    {
                        this->notValidMyCells.push(clbb);
                    }
                    Cell *clbbb = clbb->bottom;
                    if (!clbbb->groundUnit &&
                        !clbbb->stopBuild &&
                        !clbbb->shahtsNear.length &&
                        clbbb->litera != 'w')
                    {
                        this->myCells.push(clbbb);
                    }
                    else
                    {
                        this->notValidMyCells.push(clbbb);
                    }
                }
            }
        }
        // this->myCells.push(cl->bottom);
        // this->myCells.push(cl->bottom->bottom);
        // this->myCells.push(cl->bottom->bottom->bottom);
    }


    return this->myCells.length == 16;

    // for (int i = 0; i < this->myCells.length; i++)
    // {
    //     Cell *c = this->myCells.getItem(i);
    //     if (c->groundUnit ||
    //         c->litera == 'w' ||
    //         c->stopBuild)
    //     {
    //         return false;
    //     }
    // }

    // for (int i = 0; i < this->myCells.length; i++)
    // {
    //     Cell *c = this->myCells.getItem(i);
    //     c->groundUnit = this;
    // }
    // return true;
}