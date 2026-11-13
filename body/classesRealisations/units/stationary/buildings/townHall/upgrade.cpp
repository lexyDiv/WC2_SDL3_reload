#include "checkCompliteState.cpp"
//=>get4x4myCells

void TownHall::upgrade()
{
    if (this->updateTicker)
    {
        this->updateTicker++;
        if (this->updateTicker == this->updateCompliteTick)
        {
            this->level++;
            this->updateTicker = 0;
            this->updateCompliteTick = 3000;
            this->animY = 0;
            int complitePercent = (this->hp * 100) / this->hpMax;
            this->hpMax = this->fraction->townHall.hpByLevel.getItem(this->level);
            this->hp = (complitePercent * hpMax) / 100;
        }
    }
    if (this->startUpdate &&
        !this->updateTicker)
    {

        if (this->level < 2)
        {
            this->updateTicker++;
            this->image = this->fraction->townHall.imagesByLevel.getItem(this->level + 1);
            this->animGabX = 200;
            this->animGabY = 200;
            this->animY = 200;
        }

        this->startUpdate = false;
    }
}