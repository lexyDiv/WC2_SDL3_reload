#include "activeProg.cpp"
//=>out

void Shaht::wellCome(Unit *peon)
{
   // console.log("here");
    this->potentialClientsMT.lock();
    if (!this->gold || peon->gold)
    {
       // console.log("here 2");
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
        peon->iNeedFreeWay = false;
        this->potentialClients.push(peon);
        peon->cell->groundUnitOnDraw.push(peon);
        peon->myDoorCell = peon->cell;
        peon->cell->groundUnit = nullptr; //// <=
//console.log("here 3");
        if (!this->isActive)
        {
            this->isActive = true;
        }
    }
    this->potentialClientsMT.unlock();
}