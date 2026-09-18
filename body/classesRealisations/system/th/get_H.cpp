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



//     float xCat = potentialCell->hor - finishCell->hor;
//     float yCat = potentialCell->ver - finishCell->ver;
//     float dis = sqrt(xCat *xCat + yCat *yCat);
//    //console.log("y = " + to_string(potentialMc->y));
//    // console.log("dis = " + to_string(dis));

//     return dis * 30;

};