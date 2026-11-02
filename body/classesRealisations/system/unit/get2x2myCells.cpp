#include "Unit.cpp"
//=>get3x3

bool Unit::get2x2myCells(Cell *cell)
{
    // cell->groundUnit = this;
    this->myCells.push(cell);
    Cell *cell2 = cell->right;
    // cell2->groundUnit = this;
    this->myCells.push(cell2);
    Cell *cell3 = cell->bottom;
    // cell3->groundUnit = this;
    this->myCells.push(cell3);
    Cell *cell4 = cell2->bottom;
    // cell4->groundUnit = this;
    this->myCells.push(cell4);

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