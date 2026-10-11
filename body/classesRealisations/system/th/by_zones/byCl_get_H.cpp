#include "byCl_get_G.cpp"
//=>byCl_potentialWayCreate

int ThData::byCl_get_H(Zone *exploredZone) {

    int finVer = this->targetCell->ver;
    int finHor = this->targetCell->hor;
    int pVer = exploredZone->cell->ver;
    int pHor = exploredZone->cell->hor;

    int deltaHor = abs(finHor - pHor);
    int deltaVer = abs(finVer - pVer);
       
    return (deltaHor + deltaVer)* 10;

   // return 0;
}