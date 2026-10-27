#include "create.cpp"
//=>out

void Fraction::controller()
{

    // this->hardCount++;
    // if (this->hardCount == 10)
    // {
    //     this->hardCount = 0;
    // }

    this->peons.clear();
    this->allBuildings.clear();
    this->peonsOnGold.clear();
    this->peonsOnWood.clear();
    this->AllLifeUnits.clear();
    this->damagedAndConstructionBuildings.clear();
    this->fTownHoll.townHollsByLevel.forEach([](Array<Unit *> &thls)
                                             { thls.clear(); });

    this->allUnits.filterSelf([this](Unit *u)
                              {
                if (u->hp > 0) {
                    if (u->canMove) 
                    {
                       if (u->canBuild) {
                            this->peons.push(u);
                            if (u->onWood) 
                                    {
                                       this->peonsOnWood.push(u);
                                    } 
                                    else 
                                    {
                                       this->peonsOnGold.push(u);
                                    }
                       }
                       this->AllLifeUnits.push(u);
                    } 
                    else if (u->canStandStill) {
                        if (u->isComplite)
                        {
                           if (u->canTakeGold) 
                           {
                              this->fTownHoll.townHollsByLevel.getItemPtr(u->level)->push(u);
                           }
                        }

                        
                        if (u->hp < u->hpMax) {
                            this->damagedAndConstructionBuildings.push(u);
                        }
                        this->allBuildings.push(u);
                    }
                    return false;
                }                    

            return true; });

    // console.log("length = ", this->AllLifeUnits.length);

    this->controlTimer++;
    if (this->controlTimer == 1)
    {
        this->controlTimer = 0;

        // int current = 0;
        // Array<Unit *> onHard;
        // bool isOne = false;

        // /////////////////////////// => test kill
        // if (this->peons.length)
        // {
        //     for (int i = 0; i < 5; i++)
        //     {
        //         int rand = intRand(0, this->peons.length);
        //         Unit *u = this->peons.getItem(rand);
        //         u->takeDamage(1000);
        //     }
        // }
        // /////////////////////////// <= test kill

        int activeCount = 0;
        for (int i = 0; i < this->peons.length; i++)
        {
            Unit *peon = this->peons.getItem(i);
            bool isBlocked = peon->blockedCheck(peon).isBlocked;

            // if (peon->profession != "" && !this->hardCount)
            // {
            //     onHard.push(peon);
            // }

            if (peon->hp)
            {
 
                if (peon->targetData.unit &&
                    peon->targetData.unit->deleteTimer >= 100)
                    {
                        peon->targetData.unit = nullptr;
                    }

                if (
                    !peon->inSave &&
                    !peon->isActive &&
                    peon->profession != "" &&
                    peon->orderOnWay.isComplite &&
                    !isBlocked)
                {
                    // if (peon->focus) {
                    //     console.log("go controller");
                    // }
                    activeCount++;
                    peon->orderOnWay.go(peon->profession, 0, true);
                    peon->isActive = true;
                }
            }

            if (activeCount == 1000)
            {
                break;
            }
        }
    }

    // this->allBuildings.filterSelf([this](Unit *u)
    //                               {
    //                         if (!u->isDelete) {
    //             return false;
    //         }
    //         return true; });

    this->allBuildings.forEach([](Unit *building)
                               {
            if (building->isActive) {
                building->activeProg();
            } });

    // console.log("peons = ", this->peons.length);
    // console.log("buildings = ", this->allBuildings.length);
};