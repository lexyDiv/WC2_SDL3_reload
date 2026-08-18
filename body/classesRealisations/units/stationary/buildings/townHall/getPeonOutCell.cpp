#include "getPeonExtrimeOutCell.cpp"
//=>wellCome

MinData TownHall::getPeonOutCell()
{
    int ccl = this->contactCells.length;
    MinData md;
    md.cell = nullptr;
    md.index = -1;
    for (int i = 0; i < ccl; i++)
    {
        Cell *cell = this->contactCells.getItem(i);
        //while(cell->closedOnCase){};
       // cell->closedOnCase = true;
        if (!cell->groundUnit)
        {
            md.cell = cell;
            md.index = i;
            return md;
        }
        //cell->closedOnCase = false;
    }

    return md;
}