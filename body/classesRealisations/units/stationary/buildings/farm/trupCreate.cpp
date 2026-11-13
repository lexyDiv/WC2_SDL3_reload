#include "checkCompliteState.cpp"
//=>drawTrup

void Farm::trupCreate()
{
    if (!this->isDelete)
    {
        this->isDelete = true;
        this->image = imager.land_destroyed_site;
        this->animX = 0;
        this->animY = 0;
        this->animGabX = 64;
        this->animGabY = 64;


        this->myCells.forEach([this](Cell *c)
                              {
                                  c->ripUnits.push(this);
                              });
        if (this->focus)
        {
            this->gf->focusUnit = nullptr;
        }
    }

    this->deleteTimer++;

    if (this->deleteTimer == 1500)
    {
        this->animY += 64;
    }

    if (this->deleteTimer >= this->maxDeleteTimer)
    {

        this->deleteTimer = 0;
        this->myCells.forEach([this](Cell *c)
                              {
            c->ripUnits.splice(c->ripUnits.indexOf(this), 1);                   
            c->groundUnit = nullptr;
            this->gf->addClasterOnUpdate(c->claster); });
        this->readyToHardDelete = true;
    }
    else if (this->deleteTimer >= 2750)
    {
        this->alpha--;
    }
}