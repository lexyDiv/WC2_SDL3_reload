#include "isAllThreadsDopComplite.cpp"
//=>createPotentialWay

void ThData::PWProcess() {

    int length = this->game->allLifeUnitsPtr.length; //this->allPeons.length;
    for (int i = this->hold; i < length; i += this->thds->length)
    {

        Unit *unit = this->game->allLifeUnitsPtr.getItem(i);
           
        if (!unit->isPotentialWayComplite)
        {
           // console.log(to_string(this->num));
           // this->gf->getPotentialWay(peon);
           this->createPotentialWay(unit);

        }
        Uint64 currentTime = SDL_GetTicks();
        int deltaTime = int(currentTime) - int(this->game->startTick);
        if (deltaTime >= this->game->optimalDeltaTime - 5)
        {
           //console.log("here");
            this->hold = i;
            this->deep = 100;
            return;
        }
       
    };
    this->hold = this->num;
    if (this->deep < 30000) {
        this->deep += 100;
    }
   // console.log("thd : " + to_string(this->num) + " deep : " + to_string(this->deep));
}