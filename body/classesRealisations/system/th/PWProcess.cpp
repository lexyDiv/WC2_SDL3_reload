#include "isAllThreadsDopComplite.cpp"
//=>out

void ThData::PWProcess() {

    int length = this->game->allLifeUnitsPtr.length; //this->allPeons.length;
    for (int i = this->hold; i < length; i += this->thds->length)
    {

        Unit *peon = this->game->allLifeUnitsPtr.getItem(i);
           
        if (!peon->isPotentialWayComplite)
        {
           // console.log(to_string(this->num));
           // this->gf->getPotentialWay(peon);

        }
        if (this->game->needReturn)
        {
            this->hold = i;
            return;
        }
       
    };
    this->hold = this->num;

}