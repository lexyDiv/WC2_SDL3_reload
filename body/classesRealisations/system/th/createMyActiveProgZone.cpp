#include "process.cpp"
//=>isAllThreadsBasicComplite

void ThData::createMyActiveProgZone(int pathesLength)
{

    int zonesCellsCount = floor(this->game->gf->gabarit / pathesLength);

    this->startIndex = this->num * (zonesCellsCount + 1); 
    this->finishIndex = this->startIndex + (zonesCellsCount - 4); // <=
    this->dopStartIndex = this->finishIndex + 1;
    this->dopFinishIndex = this->finishIndex + 4; // <=

}