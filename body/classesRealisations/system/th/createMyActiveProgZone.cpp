#include "process.cpp"
//=>out

void ThData::createMyActiveProgZone(int pathesLength) {
    console.log(to_string(this->game->gf->gabarit));
   // console.log(to_string(floor(this->game->gf->gabarit / 3)));
    int zonesCellsCount = floor(this->game->gf->gabarit / pathesLength);
    console.log(to_string(zonesCellsCount));


   // if (!this->num) {
       this->startIndex = this->num * (zonesCellsCount + 2);
       this->finishIndex = this->startIndex + (zonesCellsCount - 2);

       
   // }
}