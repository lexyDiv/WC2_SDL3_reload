#include "byCl_get_G.cpp"
//=>byCl_potentialWayCreate

int ThData::byCl_get_H(Zone *exploredZone, Claster *cl) {

    int finVer = cl->ver;
    int finHor = cl->hor;
    int pVer = exploredZone->cl->ver;
    int pHor = exploredZone->cl->hor;

    int deltaHor = abs(finHor - pHor);
    int deltaVer = abs(finVer - pVer);
       
    return (deltaHor + deltaVer) * 10;

   // return 0;
}