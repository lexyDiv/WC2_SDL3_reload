#include "get3x3myCells.cpp"
//=>out

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