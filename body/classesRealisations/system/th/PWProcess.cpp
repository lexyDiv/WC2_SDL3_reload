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
        if (this->game->needReturn)
        {
            this->hold = i;
            return;
        }
       
    };
    this->hold = this->num;

}