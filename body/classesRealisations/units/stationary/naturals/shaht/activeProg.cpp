#include "draw.cpp"
//=>wellCome

void Shaht::activeProg()
{



    this->isActive = this->isActiveCheck();
    if (!this->isActive)
    {
        return;
    }

    this->potentialClients.forEach([this](Unit *peon)
                                   {
                                       if (peon->inOutTimer < peon->inOutCount)
                                       {
                                      //  console.log("here");
                                           peon->x += peon->wayDeltaX;
                                           peon->y += peon->wayDeltaY;
                                           peon->inOutTimer++;
                                           peon->animMashtab -= peon->inOutMashtabCount;
                                       }
                                       else
                                       {
                                        
                                           this->clients.push(peon);
                                           
                                      
                                             peon->cell = nullptr;
                                             int index = peon->myDoorCell->groundUnitOnDraw.indexOf(peon);
                                             peon->myDoorCell->groundUnitOnDraw.splice(index, 1);
                                             peon->myDoorCell = nullptr;


                                        
                                           peon->inOutTimer = 0;
                                           peon->animMashtab = peon->inOutMashtabMin;

                                           peon->gold = 100;


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
       // console.log("in clients = ", peon->inOutTimer);
        if (peon->inOutTimer == 500) {
            peon->inOutTimer = 0;
            this->outClients.push(peon);
           // console.log("nextPush");
        } });



        
    this->clients.filterSelf([](Unit *peon)
                             {
         if (!peon->inOutTimer) {
            //console.log("filter = ", peon->inOutTimer);
            return true;
        }
       // console.log("no filter = ", peon->inOutTimer);
        return false; });



      //  console.log("length = ", this->clients.length);

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
                peon->image = peon->fraction->peon.img_3;
                oc->groundUnit = peon;
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
                peon->image = peon->fraction->peon.img_3;
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
            peon->orderOnWay.go(peon->profession);
            // if (peon->profession != "" && !peon->isBlockedd(peon)) {
            //     peon->orderOnWay.go(peon->profession);
            // }

            // peon->fraction->activeUnits.push(peon);
        }
    };



    this->outClients.filterSelf([](Unit *peon)
                                {
            if (!peon->inOutTimer) {
            return true;
        }
        return false; });


}