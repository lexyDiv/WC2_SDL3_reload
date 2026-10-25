#include "takeDamage.cpp"
//=> out

void TownHall::trupCreate()
{
    if (!this->isDelete)
    {
        this->isDelete = true;
        this->image = imager.land_destroyed_site;
        this->animX = 0;
        this->animY = 0;
        // this->drawGabaritX = 180;
        // this->drawGabaritY = 180;
        // this->animCorrectionX = 40;
        // this->animCorrectionY = 40;
        this->animGabX = 64;
        this->animGabY = 64;

        this->potentialClients.forEach([this](Unit *u)
                                       {
                 // this->game->unitsBufer.push(u);
                  this->fraction->nation->addToBuffer(u);});

        this->clients.forEach([this](Unit *u)
                              {
                                 this->fraction->nation->addToBuffer(u);});

        this->outClients.forEach([this](Unit *u)
                                 {
            if (u->cell && u->cell->groundUnit == u)
            {
                u->cell->groundUnit = nullptr;
            }
                  this->fraction->nation->addToBuffer(u);});
    }

    this->deleteTimer ++;

    if (this->deleteTimer == 1500)
    {
        this->animY += 64;
    }

    if (this->deleteTimer >= this->maxDeleteTimer)
    {
        // this->game->unitsBufer.push(this);
        this->fraction->nation->addToBuffer(this);
        this->inBufer = true;
        this->deleteTimer = 0;
        this->myCells.forEach([this](Cell *c)
                              {
            c->groundUnit = nullptr;
            this->gf->addClasterOnUpdate(c->claster); });
    }
    else if (this->deleteTimer >= 2750)
    {
        this->alpha--;
    }
};