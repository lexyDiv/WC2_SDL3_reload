#include "getPeonOutCell.cpp"
//=>getShahts

void TownHall::wellCome(Unit *peon)
{
    if (peon->gold > 0 || peon->wood)
    {
        this->potentialClientsMT.lock();
        peon->inSave = true;
        int index = this->contactCells.indexOf(peon->cell);
        MinData wellComeCell = index != -1 ? this->wellComeCells.getItem(index) : wellComeCell;
        if (wellComeCell.cell)
        {
           // peon->targetData.clear(); // ????????
            peon->getDeltasXY(wellComeCell.cell);
            //peon->inSave = true;
            peon->inOutCount = ceil(wellComeCell.min / peon->fraction->peon.speed);
            peon->inOutMashtabCount = (1 - peon->inOutMashtabMin) / peon->inOutCount;

            this->potentialClients.push(peon);
            peon->cell->groundUnitOnDraw.push(peon);
            peon->myDoorCell = peon->cell;
            peon->cell->groundUnit = nullptr; //// <=
            if (!this->isActive)
            {
                this->isActive = true;
            }
        }
        this->potentialClientsMT.unlock();
    }
}