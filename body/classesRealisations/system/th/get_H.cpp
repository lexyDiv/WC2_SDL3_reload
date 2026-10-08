#include "get_G.cpp"
//=>potentialWayCreate

int ThData::get_H(Cell *potentialCell, Cell *finishCell)
{
    // int finVer = finishCell->ver;
    // int finHor = finishCell->hor;
    // int pVer = potentialCell->ver;
    // int pHor = potentialCell->hor;

    // int deltaHor = abs(finHor - pHor);
    // int deltaVer = abs(finVer - pVer);
       
    // return (deltaHor + deltaVer) * 100;

    double xCat = potentialCell->hor - finishCell->hor;
    double yCat = potentialCell->ver - finishCell->ver;
    double res = sqrt(xCat * xCat + yCat * yCat) * 10;

    //console.log("H = ", res);
    return res; //* 10;


};