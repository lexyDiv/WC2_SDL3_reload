#include "get_GMagistral.cpp"
//=>magistralWayCreate

int ThData::get_HMagistral(MagistralClaster *potentialMc, MagistralClaster *finishMc)
{
    int finVer = finishMc->ver; //finishCell->ver;
    int finHor = finishMc->hor; //finishCell->hor;
    int pVer = potentialMc->ver;
    int pHor = potentialMc->hor;

    int deltaHor = abs(finHor - pHor);
    int deltaVer = abs(finVer - pVer);

    return deltaHor + deltaVer;
}