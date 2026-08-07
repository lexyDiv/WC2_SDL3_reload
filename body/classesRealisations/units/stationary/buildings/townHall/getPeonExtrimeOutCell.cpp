#include "isActiveCheck.cpp"
//=>getPeonOutCell

MinData TownHall::getPeonExtrimeOutCell()
{
    MinData md;
    md.cell = nullptr;
    md.index = -1;

    int ol = this->exitCells.length;
    for (int i = 0; i < ol; i++)
    {
        Cell *cell = this->exitCells.getItem(i);
        //while(cell->closedOnCase) {};
       // cell->closedOnCase = true;
        if (!cell->groundUnit)
        {
            md.cell = cell;
            md.index = i;
            return md;
        }
      //  cell->closedOnCase = false;
    }

    return md;
}