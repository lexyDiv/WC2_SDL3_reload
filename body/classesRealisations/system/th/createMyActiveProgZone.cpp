#include "process.cpp"
//=>out

void ThData::createMyActiveProgZone(int pathesLength)
{

    int zonesCellsCount = floor(this->game->gf->gabarit / pathesLength);

    this->startIndex = this->num * (zonesCellsCount + 1); 
    this->finishIndex = this->startIndex + (zonesCellsCount - 4); // <=
    this->dopStartIndex = this->finishIndex + 1;
    this->dopFinishIndex = this->finishIndex + 4; // <=

    // for (int i = this->startIndex; i <= this->finishIndex; i++)
    // {
    //     if (i < this->game->gf->gabarit)
    //     {
    //         Cell *cell = this->game->gf->field.getItem(i).getItem(0);
    //         cell->activeZoneIndex = this->num + 1;
    //     }
    //     else
    //     {
    //         //  console.log("//////////////////////////////");
    //         //  console.log(to_string(i));
    //     }
    // }

    // for (int i = this->finishIndex + 1; i <= this->finishIndex + 4; i++)
    // {
    //     if (i < this->game->gf->gabarit)
    //     {
    //         Cell *cell = this->game->gf->field.getItem(i).getItem(1);
    //         cell->activeZoneIndex = this->num + 1;
    //     }
    // }
}