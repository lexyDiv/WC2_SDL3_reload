#include "Unit.cpp"
//=>get3x3

bool Unit::get2x2myCells(Cell *cell)
{

    this->myCells.clear();
    this->notValidMyCells.clear();
    Array<Cell *> cells;

    cells.push(cell);
    Cell *cell2 = cell->right ? cell->right : nullptr;
    cells.push(cell2);
    Cell *cell3 = cell->bottom ? cell->bottom : nullptr;
    cells.push(cell3);
    Cell *cell4 = cell2 && cell2->bottom ? cell2->bottom : nullptr;
    cells.push(cell4);

    for (int i = 0; i < cells.length; i++)
    {
        Cell *c = cells.getItem(i);
        if (c)
        {
            if (
                c->groundUnit ||
                c->litera == 'w')
            {
                this->notValidMyCells.push(c);
            }
            else
            {
                this->myCells.push(c);
            }
        }
    }

    return this->myCells.length == 4;

    // for (int i = 0; i < this->myCells.length; i++)
    // {
    //     Cell *c = this->myCells.getItem(i);
    //     c->groundUnit = this;
    // }
    // return true;
};