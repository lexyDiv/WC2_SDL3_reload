#include "isAllThreadsDopComplite.cpp"
//=>createPotentialWay


void ThData::PWProcess()
{
    this->deep = 30000;
    int length = this->game->unitsOnWay.length;
    for (int i = this->num; i < length; i += this->thds->length)
    {
        Unit *unit = this->game->unitsOnWay.getItem(i);

        this->timeBeforeUnitWay = SDL_GetTicks();

        if (!unit->isPotentialWayComplite && unit->cell && unit->hp)
        {
            this->createPotentialWay(unit);
            unit->isPotentialWayComplite = true;
        }
       Uint64 currentTime = SDL_GetTicks();
       int deltaTime = int(currentTime) - int(this->game->startTick);

       console.log("time = ", deltaTime);
    //     if (deltaTime >= this->game->optimalDeltaTime - 10)
    //     {
    //        // this->hold = i;
    //        // this->deep = this->deep >= 5000 ? this->deep - 50 : this->deep;
    //        this->deep = this->lowDeep;
    //     }
    };
    // if (this->deep < 5000)
    // {
    //     this->deep += 25;
    // }
}