#include "draw.cpp"
//=>isActiveCheck

bool ok = false;
// int tt = 0;

void TownHall::activeProg()
{
    this->isActive = this->isActiveCheck();
    if (!this->isActive)
    {
        return;
    }

    if (this->createTimer)
    {
        this->createTimer--;
        if (!this->createTimer)
        {
            this->fraction->unitCount++;
            Unit *peon = new Peon_peasant(this->fraction);
            peon->createInside(this->cell);
            int ran = intRand(0, 10);
            this->outClients.push(peon);
            peon->profession = "w";
            // peon->profession = ran ? "w" : "g";
            if (this->fraction->peons.length < 1) // 6000 crash 3000
            {
                this->createTimer = 1;
            }
        }
    }

    this->potentialClients.forEach([this](Unit *peon)
                                   {
                                       if (peon->inOutTimer < peon->inOutCount)
                                       {
                                           peon->x += peon->wayDeltaX;
                                           peon->y += peon->wayDeltaY;
                                           peon->inOutTimer++;
                                           peon->animMashtab -= peon->inOutMashtabCount;
                                       }
                                       else
                                       {

                                           this->clients.push(peon);
    
                                            Cell *pc = peon->cell;
                                      
                                            peon->cell->groundUnit = nullptr;
                                            peon->cell = nullptr;

                                           peon->inOutTimer = 0;
                                           peon->animMashtab = peon->inOutMashtabMin;
                                           if (this->fraction->fTownHoll.level_3_townHollsCount) {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 150 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 150 : this->fraction->wood;
                                           } else if (this->fraction->fTownHoll.level_2_townHollsCount) {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 125 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 125 : this->fraction->wood;
                                           } else {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 100 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 100 : this->fraction->wood;
                                           }
                                           peon->wood = 0;
                                           peon->gold = 0;
                                       } });

    this->potentialClients.filterSelf([](Unit *peon)
                                      {
        if (!peon->inOutTimer) {
            return true;
        }
        return false; });

    this->clients.forEach([this](Unit *peon)
                          {
        peon->inOutTimer ++;
        if (peon->inOutTimer == 500) {
            peon->inOutTimer = 0;
            this->outClients.push(peon);
        } });

    this->clients.filterSelf([](Unit *peon)
                             {
         if (!peon->inOutTimer) {
            return true;
        }
        return false; });

    for (int i = 0; i < this->outClients.length; i++)
    {
        Unit *peon = this->outClients.getItem(i);
        if (!peon->inOutTimer)
        {
            peon->inOutCount = 0;
            MinData md = this->getPeonOutCell();
            int index = md.index;

            if (index != -1)
            {
                Cell *oc = md.cell;
                MinData md = this->wellComeCells.getItem(index);
                peon->cell = md.cell;
                peon->inOutCount = ceil(md.min / peon->fraction->peon.speed);
                peon->x = peon->cell->x;
                peon->y = peon->cell->y;
                peon->drawIndexY = peon->y;
                peon->getDeltasXY(oc); // !!!!!!! wery impotent !!!!!!!
                peon->cell = oc;
                peon->inOutMashtabCount = (1 - peon->inOutMashtabMin) / peon->inOutCount;
                peon->image = peon->fraction->peon.img_1;
                oc->groundUnit = peon;
                /////// fake way
            }
            else
            {
                MinData md = this->getPeonExtrimeOutCell();
                Cell *oc = md.cell;
                peon->cell = oc;
                peon->inOutCount = 0;
                peon->x = peon->cell->x;
                peon->y = peon->cell->y;
                peon->drawIndexY = peon->y;
                peon->inOutMashtabCount = 1;
                peon->image = peon->fraction->peon.img_1;
                oc->groundUnit = peon;
            }
        }

        if (peon->inOutTimer < peon->inOutCount)
        {
            // console.log("here");
            peon->x += peon->wayDeltaX;
            peon->y += peon->wayDeltaY;
            peon->drawIndexY = peon->y;
            peon->animMashtab += peon->inOutMashtabCount;

            peon->inOutTimer++;
        }
        else
        {
            // console.log("here 2");
            peon->inOutTimer = 0;
            peon->animMashtab = 1;
            peon->inSave = false;
            // peon->targetObj.unit = nullptr;
            peon->stendOnCell();
            peon->outHoldTimer = 30;
            peon->isActive = true;
            // peon->fraction->activeUnits.push(peon);
        }
    };

    this->outClients.filterSelf([](Unit *peon)
                                {
            if (!peon->inOutTimer) {
            return true;
        }
        return false; });
    // };
    // this->game->mute_push_cases.lock();
    // this->game->addCase(mc);
    // this->game->mute_push_cases.unlock();
}