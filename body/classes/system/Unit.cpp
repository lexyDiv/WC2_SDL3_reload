#include "Unit.h"
//=>system/out.h

void Unit::get2x2myCells(Cell *cell)
{
    cell->groundUnit = this;
    this->myCells.push(cell);
    Cell *cell2 = cell->right;
    cell2->groundUnit = this;
    this->myCells.push(cell2);
    Cell *cell3 = cell->bottom;
    cell3->groundUnit = this;
    this->myCells.push(cell3);
    Cell *cell4 = cell2->bottom;
    cell4->groundUnit = this;
    this->myCells.push(cell4);
};

void Unit::getContactCells()
{
    if (this->myCells.length <= 1)
    {
        this->contactCells.copy(this->cell->aroundCells);
    }
    else
    {
        this->myCells.forEach([this](Cell *cell)
                              { cell->aroundCells.forEach([this](Cell *ac)
                                                          {
                if (ac->groundUnit != this) {
                   this->contactCells.push(ac);
                } }); });
    }
}

void Unit::get3x3myCells(Cell *cell)
{
    cell->groundUnit = this;
    this->myCells.push(cell);
    cell->right->groundUnit = this;
    this->myCells.push(cell->right);
    cell->right->right->groundUnit = this;
    this->myCells.push(cell->right->right);
    for (int i = 0; i < 3; i++)
    {
        Cell *cl = this->myCells.getItem(i);
        cl->bottom->groundUnit = this;
        this->myCells.push(cl->bottom);
        cl->bottom->bottom->groundUnit = this;
        this->myCells.push(cl->bottom->bottom);
    }
};