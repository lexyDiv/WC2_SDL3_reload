#include "takeDamage.cpp"
//=> drawTrup

void TownHall::trupCreate()
{
    if (!this->isDelete)
    {
        this->isDelete = true;
        this->image = imager.land_destroyed_site;
        this->animX = 0;
        this->animY = 0;
        this->animGabX = 64;
        this->animGabY = 64;

        this->isAddOnDraw = false;

        Boo *boo = new BuildingBoo;
        boo->create(0, 0, 0, 0, this);

        this->myCells.forEach([this, boo](Cell *c){
            c->ripUnits.push(this);
            c->boos.push(boo);
        });

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
        
        this->fraction->nation->addToBuffer(this);
        this->inBufer = true;
        this->deleteTimer = 0;
        this->myCells.forEach([this](Cell *c)
                              {
            c->ripUnits.splice(c->ripUnits.indexOf(this), 1);                   
            c->groundUnit = nullptr;
            this->gf->addClasterOnUpdate(c->claster); });
    }
    else if (this->deleteTimer >= 2750)
    {
        this->alpha--;
    }
};