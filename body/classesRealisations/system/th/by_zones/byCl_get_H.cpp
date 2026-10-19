#include "byCl_get_G.cpp"
//=>byCl_potentialWayCreate

int ThData::byCl_get_H(Zone *exploredZone) {

    int finVer = this->targetCell->claster->ver;
    int finHor = this->targetCell->claster->hor;
    int pVer = exploredZone->cell->claster->ver;
    int pHor = exploredZone->cell->claster->hor;

    int deltaHor = abs(finHor - pHor);
    int deltaVer = abs(finVer - pVer);
       
    return (deltaHor + deltaVer)* 10;

   // return 0;
}