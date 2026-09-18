#include "get_GMagistral.cpp"
//=>magistralWayCreate

float ThData::get_HMagistral(MagistralClaster *potentialMc, MagistralClaster *finishMc)
{
//     float finVer = finishMc->ver; //finishCell->ver;
//     float finHor = finishMc->hor; //finishCell->hor;
//     float pVer = potentialMc->ver;
//     float pHor = potentialMc->hor;

//     float deltaHor = abs(finHor - pHor);
//     float deltaVer = abs(finVer - pVer);

//    return (deltaHor + deltaVer) * 30;


    float xCat = potentialMc->hor - finishMc->hor;
    float yCat = potentialMc->ver - finishMc->ver;
    float dis = sqrt(xCat *xCat + yCat *yCat);
   //console.log("y = " + to_string(potentialMc->y));
   // console.log("dis = " + to_string(dis));

    return dis * 30;

}