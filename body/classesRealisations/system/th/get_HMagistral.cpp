#include "get_GMagistral.cpp"
//=>magistralWayCreate

float ThData::get_HMagistral(MagistralClaster *potentialMc, MagistralClaster *finishMc)
{
    // float finVer = finishMc->y; //finishCell->ver;
    // float finHor = finishMc->x; //finishCell->hor;
    // float pVer = potentialMc->x;
    // float pHor = potentialMc->y;

    // float deltaHor = abs(finHor - pHor);
    // float deltaVer = abs(finVer - pVer);

   // return (deltaHor + deltaVer) * 10;
    float xCat = potentialMc->hor - finishMc->hor;
    float yCat = potentialMc->ver - finishMc->ver;
    float dis = sqrt(xCat *xCat + yCat *yCat);
   //console.log("y = " + to_string(potentialMc->y));
   // console.log("dis = " + to_string(dis));

    return dis;

}