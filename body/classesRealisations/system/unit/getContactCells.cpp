#include "get4x4myCells.cpp"
//=>getContactAndExitCells

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