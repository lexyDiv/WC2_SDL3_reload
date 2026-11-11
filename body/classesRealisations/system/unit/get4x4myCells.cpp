#include "get3x3myCells.cpp"
//=>getContactCells

bool Unit::get4x4myCells(Cell *cell)
{

    // cell->groundUnit = this;
    this->myCells.push(cell);
    // cell->right->groundUnit = this;
    this->myCells.push(cell->right);
    //  cell->right->right->groundUnit = this;
    this->myCells.push(cell->right->right);
    // cell->right->right->right->groundUnit = this;
    this->myCells.push(cell->right->right->right);
    for (int i = 0; i < 4; i++)
    {
        Cell *cl = this->myCells.getItem(i);
        // cl->bottom->groundUnit = this;
        this->myCells.push(cl->bottom);
        // cl->bottom->bottom->groundUnit = this;
        this->myCells.push(cl->bottom->bottom);
        //  cl->bottom->bottom->bottom->groundUnit = this;
        this->myCells.push(cl->bottom->bottom->bottom);
    }

    for (int i = 0; i < this->myCells.length; i++)
    {
        Cell *c = this->myCells.getItem(i);
        if (c->groundUnit ||
            c->litera == 'w' ||
            c->stopBuild)
        {
            return false;
        }
    }

    for (int i = 0; i < this->myCells.length; i++)
    {
        Cell *c = this->myCells.getItem(i);
        c->groundUnit = this;
    }
    return true;
};