#include "isAllThreadsDopComplite.cpp"
//=>out

void ThData::PWProcess() {

    int length = this->game->allLifeUnitsPtr.length; //this->allPeons.length;
    for (int i = this->hold; i < length; i += this->thds->length)
    {
        // if (i <= this->allPeons.length - 1)
        // {
        Unit *peon = this->game->allLifeUnitsPtr.getItem(i);
        // if (peon->focus)
        // {
        //     console.log("peon->isPotentialWayComplite 1 : " + to_string(peon->isPotentialWayComplite));
        // }
        if (!peon->isPotentialWayComplite)
        {
           // this->gf->getPotentialWay(peon);

        }
        if (this->game->needReturn)
        {
            this->hold = i;
            return;
        }
        // }
    };
    this->hold = this->num;
//     Uint64 finishT = SDL_GetTicks();
//     Uint64 deltaT = finishT - startT;
//   //  console.log("delta   : " + to_string(deltaT) + " deep   : " + to_string(this->gf->deep));
//     startT = finishT;
}