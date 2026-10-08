#include "byCl_exploreNewZone.cpp"
//=>get_H

int ThData::byCl_get_G(Zone *fatherZone, Zone *sonZone)
{ // 10/ 14


    // int finVer = fatherZone->cell->ver;
    // int finHor = fatherZone->cell->hor;
    // int pVer = sonZone->cell->ver;
    // int pHor = sonZone->cell->hor;

    // int deltaHor = abs(finHor - pHor);
    // int deltaVer = abs(finVer - pVer);
       
    // return (deltaHor + deltaVer); //* 10;


    Claster *fcl = fatherZone->cl;
    Claster *scl = sonZone->cl;

    for (int i = 0; i < fcl->aroundClasters.length; i++)
    {
        Claster *ecl = fcl->aroundClasters.getItem(i);
        if (ecl == scl)
        {
            return fcl->aroundClasters_G.getItem(i);
        }
    }

    return 10;
}