#include "drawTrup.cpp"
//=>out

void TownHall::checkCompliteState()
{
    if (this->checkStateNeed)
    {

        int complitePercent = (this->hp * 100) / this->hpMax;
        if (complitePercent <= 30)
        {
            this->image = this->fraction->townHall.construction;
            this->animGabX = 64;
            this->animGabY = 64;
            this->drawGabaritX = 220;
            this->drawGabaritY = 220;
            this->animCorrectionX = 60;
            this->animCorrectionY = 60;
            this->animX = 0;
            this->animY = 0;
        }
        else if (complitePercent <= 50)
        {
            this->image = this->fraction->townHall.construction;
            this->animGabX = 64;
            this->animGabY = 64;
            this->drawGabaritX = 220;
            this->drawGabaritY = 220;
            this->animCorrectionX = 60;
            this->animCorrectionY = 60;
            this->animX = 0;
            this->animY = 64;
        }
        else if (complitePercent < 100)
        {
            this->image = this->fraction->townHall.imagesByLevel.getItem(this->level);
            this->animGabX = 128;
            this->animGabY = 128;
            this->animCorrectionX = 60;
            this->animCorrectionY = 120;
            this->drawGabaritX = 220;
            this->drawGabaritY = 290;
            this->animX = 0;
            this->animY = 128;
        }
        else
        {
            this->image = this->fraction->townHall.imagesByLevel.getItem(this->level);
            this->animGabX = 128;
            this->animGabY = 128;
            this->animCorrectionX = 60;
            this->animCorrectionY = 120;
            this->drawGabaritX = 220;
            this->drawGabaritY = 290;
            this->animX = 0;
            this->animY = 0;
            this->isComplite = true;
            // console.log("complite");
        }

        this->checkStateNeed = false;
    }
}