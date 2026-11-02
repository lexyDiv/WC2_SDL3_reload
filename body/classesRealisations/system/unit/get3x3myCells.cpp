#include "get2x2myCells.cpp"
//=>get4X4myCells

bool Unit::get3x3myCells(Cell *cell)
{
    // cell->groundUnit = this;
    this->myCells.push(cell);
    // cell->right->groundUnit = this;
    this->myCells.push(cell->right);
    // cell->right->right->groundUnit = this;
    this->myCells.push(cell->right->right);
    for (int i = 0; i < 3; i++)
    {
        Cell *cl = this->myCells.getItem(i);
        // cl->bottom->groundUnit = this;
        this->myCells.push(cl->bottom);
        // cl->bottom->bottom->groundUnit = this;
        this->myCells.push(cl->bottom->bottom);
    }

    for (int i = 0; i < this->myCells.length; i++)
    {
        Cell *c = this->myCells.getItem(i);
        if (c->groundUnit ||
            c->litera == 'w')
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