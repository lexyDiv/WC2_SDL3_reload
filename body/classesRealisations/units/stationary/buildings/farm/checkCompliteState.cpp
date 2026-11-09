#include "takeDamage.cpp"
//=>trupCreate

void Farm::checkCompliteState()
{
    if (this->checkStateNeed)
    {

        int complitePercent = (this->hp * 100) / this->hpMax;
        if (complitePercent <= 30)
        {
            this->image = this->fraction->farm.construction;
            this->animGabX = 64;
            this->animGabY = 64;
            this->animStepX = 64;
            this->animStepY = 64;
            this->animCorrectionX = 0;
            this->animCorrectionY = 0;
            this->drawGabaritX = 100;
            this->drawGabaritY = 100;
            this->deleteTimer = 0;
            this->animY = 0;
        }
        else if (complitePercent <= 50)
        {
            this->image = this->fraction->farm.construction;
            this->animGabX = 64;
            this->animGabY = 64;
            this->animStepX = 64;
            this->animStepY = 64;
            this->animCorrectionX = 0;
            this->animCorrectionY = 0;
            this->drawGabaritX = 100;
            this->drawGabaritY = 100;
            this->deleteTimer = 0;
            this->animY = 64;
        }
        else if (complitePercent < 100)
        {
            this->image = this->fraction->farm.img_1;
            this->animGabX = 100;
            this->animGabY = 100;
            this->animStepX = 100;
            this->animStepY = 100;
            this->animCorrectionX = 0;
            this->animCorrectionY = 0;
            this->drawGabaritX = 100;
            this->drawGabaritY = 100;
            this->deleteTimer = 0;
            this->animY = 100;
        }
        else
        {
            this->image = this->fraction->farm.img_1;
            this->animGabX = 100;
            this->animGabY = 100;
            this->animStepX = 100;
            this->animStepY = 100;
            this->animCorrectionX = 0;
            this->animCorrectionY = 0;
            this->drawGabaritX = 100;
            this->drawGabaritY = 100;
            this->deleteTimer = 0;
            this->animY = 0;
            this->isComplite = true;
            // console.log("complite");
        }

        this->checkStateNeed = false;
    }
}