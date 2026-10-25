#include "takeDamage.cpp"
//=> out

void TownHall::trupCreate()
{
    if (!this->isDelete)
    {
        this->isDelete = true;
        // this->cell->ripUnits.push(this);
        this->image = imager.land_destroyed_site;
        this->animX = 0;
        this->animY = 0;
        this->drawGabaritX = 180;
        this->drawGabaritY = 180;
        this->animCorrectionX = 40;
        this->animCorrectionY = 40;
        this->animGabX = 64;
        this->animGabY = 64;
    }

    this->deleteTimer --;

    if (this->deleteTimer == 1500)
    {
        this->animY += 64;
    }

    if (this->deleteTimer <= 0)
    {
        this->game->unitsBufer.push(this);
        this->inBufer = true;
        this->deleteTimer = 0;
        this->myCells.forEach([this](Cell *c){
            c->groundUnit = nullptr;
            this->gf->addClasterOnUpdate(c->claster);
        });
    }
    else if (this->deleteTimer <= 250)
    {
        this->alpha--;
    }
};