#include "takeDamage.cpp"
//=> drawTrup

void TownHall::trupCreate()
{

    // console.log("trup create");

    if (!this->isDelete)
    {
        this->isDelete = true;
        this->image = imager.land_destroyed_site;
        this->animX = 0;
        this->animY = 0;
        this->animGabX = 64;
        this->animGabY = 64;

        // this->isAddOnDraw = false;

        // Boo *boo = new BuildingBoo;
        //  boo->create(this->cell->x - 150, this->cell->y - 140, 400, 400, this);

        this->myCells.forEach([this](Cell *c)
                              {
                                  c->ripUnits.push(this);
                                  // c->boos.push(boo);
                              });

        this->potentialClients.forEach([this](Unit *u)
                                       {
                                           u->fastDead = true;
                                           if (u->myDoorCell)
                                           {
                                               int index = u->myDoorCell->groundUnitOnDraw.indexOf(u);
                                               if (index != -1)
                                               {
                                                   u->myDoorCell->groundUnitOnDraw.splice(index, 1);
                                               }
                                           }
                                           u->takeDamage(3000);

                                       });

        this->clients.forEach([this](Unit *u)
                              {
                                  u->fastDead = true;
                                  u->takeDamage(3000);
                                  // this->fraction->nation->addToBuffer(u);
                              });

        this->outClients.forEach([this](Unit *u)
                                 {
                                     if (u->cell && u->cell->groundUnit == u)
                                     {
                                         u->fastDead = true;
                                         u->cell->groundUnit = nullptr;
                                         u->takeDamage(3000);
                                         // console.log("here");
                                     }
                                     // this->fraction->nation->addToBuffer(u);
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

        // this->fraction->nation->addToBuffer(this);
        this->inBufer = true;
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
};