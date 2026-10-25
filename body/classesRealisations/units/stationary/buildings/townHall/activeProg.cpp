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

    if (!this->isComplite)
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
                this->animCorrectionX = 90;
                this->animCorrectionY = 120;
                this->drawGabaritX = 285;
                this->drawGabaritY = 290;
                this->animX = 0;
                this->animY = 128;
            }
            else
            {
                this->image = this->fraction->townHall.imagesByLevel.getItem(this->level);
                this->animGabX = 128;
                this->animGabY = 128;
                this->animCorrectionX = 90;
                this->animCorrectionY = 120;
                this->drawGabaritX = 285;
                this->drawGabaritY = 290;
                this->animX = 0;
                this->animY = 0;
                this->isComplite = true;
                // console.log("complite");
            }

            this->checkStateNeed = false;
        }

        return;
    }
    else
    {
        if (this->checkStateNeed)
        {

            this->checkStateNeed = false;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    if (this->createTimer && !this->stopCreateUnit)
    {
        this->createTimer--;
        if (!this->createTimer)
        {

            Unit *peon = this->game->unitsBufer.find([](Unit *u)
                                                     {
              if (u->inBufer) {
                u->inBufer = false;
                return true;
              }
              return false; });

            if (peon)
            {
                peon->createInside(this->cell);
            }
            else
            {
                peon = new Peon_peasant(this->fraction);
                peon->createInside(this->cell, true);
            }

            this->fraction->unitCount++;
            peon->persNum = this->fraction->unitCount;
            this->outClients.push(peon);
            peon->outHoldTimer = 30;

            int rand = intRand(0, 10);
             peon->profession = rand >= 1 ? "w" : "g";

            if (this->fraction->peons.length < 400) // 6000 crash 3000
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
                                         // this->mt.lock();
                                           this->clients.push(peon);
                                           
    
                                           // Cell *pc = peon->cell;
                                      
                                             peon->cell = nullptr;
                                             int index = peon->myDoorCell->groundUnitOnDraw.indexOf(peon);
                                             peon->myDoorCell->groundUnitOnDraw.splice(index, 1);
                                             peon->myDoorCell = nullptr;
                                        //    if (pc && pc->groundUnit == peon) {
                                        //     pc->groundUnit = nullptr;
                                        //     peon->cell = nullptr;
                                        //    } else {
                                        //     console.log("townHall on peon cell");
                                        //    }

                                            

                                           peon->inOutTimer = 0;
                                           peon->animMashtab = peon->inOutMashtabMin;
                                           if (this->fraction->fTownHoll.townHollsByLevel.getItem(2).length) {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 150 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 150 : this->fraction->wood;
                                           } else if (this->fraction->fTownHoll.townHollsByLevel.getItem(1).length) {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 125 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 125 : this->fraction->wood;
                                           } else {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 100 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 100 : this->fraction->wood;
                                           }
                                           peon->wood = 0;
                                           peon->gold = 0;
                                          // this->mt.unlock();
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
                peon->hp = peon->hp > 0 ? peon->hp : 1;

                // if (peon->cell == this->cell) {
                //     console.log("outCell");
                // }
                // if (!peon->inSave) {
                //     console.log("No inSave");
                // }
            }
            else
            {
                MinData md = this->getPeonExtrimeOutCell();

                if (md.cell)
                {
                    Cell *oc = md.cell;
                    peon->cell = oc;
                    peon->inOutCount = 0;
                    peon->x = peon->cell->x;
                    peon->y = peon->cell->y;
                    peon->drawIndexY = peon->y;
                    peon->inOutMashtabCount = 1;
                    peon->image = peon->fraction->peon.img_1;
                    oc->groundUnit = peon;
                    peon->hp = peon->hp > 0 ? peon->hp : 1;
                    this->stopCreateUnit = false;
                }
                else
                {
                    this->stopCreateUnit = true;
                   // console.log("on out cell");
                    return;
                }

                //                 if (peon->cell == this->cell) {
                //     console.log("extrime outCell");
                // }
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

            // if (peon->profession != "" && !peon->isBlockedd(peon)) {
            //     peon->orderOnWay.go(peon->profession);
            // }

            // peon->fraction->activeUnits.push(peon);
        }
    };

    this->outClients.filterSelf([this](Unit *peon)
                                {
            // if (peon->cell == this->cell) {
            //         console.log("MY CELL");
            //     }
            if (!peon->inOutTimer) {
            return true;
        }
        return false; });
    // };
    // this->game->mute_push_cases.lock();
    // this->game->addCase(mc);
    // this->game->mute_push_cases.unlock();
}