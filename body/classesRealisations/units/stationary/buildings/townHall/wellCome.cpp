#include "getPeonOutCell.cpp"
//=>getShahts

void TownHall::wellCome(Unit *peon)
{
    if (peon->gold > 0 || peon->wood)
    {
        int index = this->contactCells.indexOf(peon->cell);
        MinData wellComeCell = index != -1 ? this->wellComeCells.getItem(index) : wellComeCell;
        if (wellComeCell.cell)
        {
            peon->getDeltasXY(wellComeCell.cell);
            peon->inSave = true;
            peon->inOutCount = ceil(wellComeCell.min / peon->fraction->peon.speed);
            peon->inOutMashtabCount = (1 - peon->inOutMashtabMin) / peon->inOutCount;
            // peon->gold = 100;
            // peon->wood = 0;
            // this->gold -= 100;
            this->potentialClients.push(peon);
            if (!this->isActive)
            {
                this->isActive = true;
            }
        }
    }
}