#include "activeProg.cpp"
//=>out

void Shaht::wellCome(Unit *peon)
{
    this->potentialClientsMT.lock();
    if (!this->gold || peon->gold)
    {
        this->potentialClientsMT.unlock();
        return;
    }
    this->gold -= 100;
    peon->wood = 0;
    peon->inSave = true;
    int index = this->contactCells.indexOf(peon->cell);
    MinData wellComeCell = index != -1 ? this->wellComeCells.getItem(index) : wellComeCell;
    if (wellComeCell.cell)
    {
        peon->getDeltasXY(wellComeCell.cell);
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