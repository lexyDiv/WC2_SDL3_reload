#include "get_G.cpp"
//=>potentialWayCreate

int ThData::get_H(Cell *potentialCell, Cell *finishCell)
{
    int finVer = finishCell->ver;
    int finHor = finishCell->hor;
    int pVer = potentialCell->ver;
    int pHor = potentialCell->hor;

    int deltaHor = abs(finHor - pHor);
    int deltaVer = abs(finVer - pVer);

    return (deltaHor + deltaVer) * 10;
};