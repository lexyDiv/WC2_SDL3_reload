#include "holdTimerControl.cpp"
//=>isNeedHoldGoWay

void Peon_peasant::orderOnWayControl()
{

    if (!this->orderOnWay.isComplite)
    {

       // int num = 390;

        this->orderOnWay.mt.lock();

        Cell *oCell = this->orderOnWay.cell;
        Unit *ocu = oCell ? oCell->groundUnit : nullptr;

        TargetData currentTD;

        if (this->inSave)
        {
            this->orderOnWay.isComplite = true;
            this->orderOnWay.mt.unlock();
            console.log("inSave with order");
            return;
        }

        this->personalCaseDeep = this->orderOnWay.pcd;
        this->targetData.specialFreeG0 = this->orderOnWay.specialFreeG0;

        if (
            this->orderOnWay.stop ||
            ocu == this ||
            (ocu &&
             ((ocu->fraction != this->fraction && !ocu->canGiveGold && !ocu->canGiveTree))) ||
            (this->orderOnWay.cell &&
             (this->orderOnWay.cell->plane != this->cell->plane)))
        {
            // console.log("S = " + to_string(this->orderOnWay.stop) + " == " + to_string(ocu == this));
            this->targetData.clear();
            this->way.clear();
            this->wayIndex = 0;
            this->orderOnWay.isComplite = true;
            this->orderOnWay.stop = false;
            // this->profession = "";
            this->orderOnWay.mt.unlock();
            // if (this->persNum == num) {
            //     console.log("STOP");
            // }
            // console.log("here ");
            // if (this->persNum == num)
            // {
            //     console.log("order 2 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            // }
            return;
        }

        if (
            (this->blockedData.isBlocked && this->blockedData.type == 'f') // this->isBlockedd_full(this)
            && this->personalCaseDeep != 3                                 //&& this->orderOnWay.specialFreeG0
        )
        {
            this->iNeedFreeWay = true; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! <= ON !!! 2/3
        }

        // console.log("this->orderOnWay.profession " + this->orderOnWay.profession);
        if (this->orderOnWay.profession == "")
        {

            if (ocu && !ocu->canMove)
            {
                if (ocu->canGiveTree)
                {
                    if (this->wood)
                    {
                        Unit *unloadingUnit = this->getBaseForUnloading();
                        if (unloadingUnit)
                        {
                            int rand = intRand(0, unloadingUnit->myCells.length);
                            Cell *ulc = unloadingUnit->myCells.getItem(rand);
                            currentTD.clicckedCell = ulc;
                            currentTD.unit = unloadingUnit;
                            currentTD.unitPersNum = unloadingUnit->persNum;
                            currentTD.profession = "w";
                            this->profession = "w";
                        }
                        else
                        {
                            currentTD.clicckedCell = nullptr;
                            currentTD.unit = nullptr;
                            this->profession = "";
                        }
                    }
                    else
                    {
                        currentTD.clicckedCell = ocu->cell;
                        currentTD.unit = ocu;
                        currentTD.unitPersNum = ocu->persNum;
                        currentTD.profession = "w";
                        this->profession = "w";
                    }
                }
                else if (
                    // ocu->name == "greatHall"
                    ocu->canTakeGold || ocu->canTakeWood)
                {

                    if (this->wood)
                    {
                        this->profession = "w";
                    }
                    else if (
                        this->gold &&
                        ocu->canTakeGold)
                    {
                        this->profession = "g";
                    }

                    int rand = intRand(0, ocu->myCells.length);
                    Cell *ulc = ocu->myCells.getItem(rand);
                    currentTD.clicckedCell = ulc;
                    currentTD.unit = ocu;
                    currentTD.unitPersNum = ocu->persNum;
                }
                else if (
                    // ocu->name == "shaht"
                    ocu->canGiveGold)
                {
                    if (this->gold)
                    {
                        Unit *unloadingUnit = this->getBaseForUnloadingGold();
                        if (unloadingUnit)
                        {
                            int rand = intRand(0, unloadingUnit->myCells.length);
                            Cell *ulc = unloadingUnit->myCells.getItem(rand);
                            currentTD.clicckedCell = ulc;
                            currentTD.unit = unloadingUnit;
                            currentTD.unitPersNum = unloadingUnit->persNum;
                            currentTD.profession = "g";
                            this->profession = "g";
                        }
                        else
                        {
                            currentTD.unit = nullptr;
                            currentTD.clicckedCell = nullptr;
                            this->profession = "";
                        }
                    }
                    else
                    {
                        int rand = intRand(0, ocu->myCells.length);
                        Cell *ulc = ocu->myCells.getItem(rand);
                        currentTD.clicckedCell = ulc;
                        currentTD.unit = ocu;
                        currentTD.unitPersNum = ocu->persNum;
                        currentTD.profession = "g";
                        this->profession = "g";
                    }
                }
                else
                {

                    currentTD.clicckedCell = ocu->cell;
                    currentTD.unit = ocu;
                    currentTD.unitPersNum = ocu->persNum;
                    currentTD.profession = "";
                    this->profession = "";
                }
            }
            else
            {

                currentTD.clicckedCell = this->orderOnWay.cell;
                currentTD.unit = nullptr;
                currentTD.unitPersNum = 0;
                currentTD.profession = "";
                this->profession =
                    (this->personalCaseDeep == 3 ||
                     this->personalCaseDeep == 300)
                        ? this->profession
                        : "";
            }
        }
        else
        {

            TargetData &td = this->targetData;

            if (this->orderOnWay.profession == "w")
            {
                if (this->wood)
                {
                    if (!(td.unit && (td.unit->canTakeGold || td.unit->canTakeWood) &&
                          (this->isTargetObjValide() || td.nextCell)))
                    {

                        Unit *unloadingUnit = this->getBaseForUnloading();

                        if (unloadingUnit)
                        {
                            int rand = intRand(0, unloadingUnit->myCells.length);
                            Cell *ulc = unloadingUnit->myCells.getItem(rand);
                            currentTD.clicckedCell = ulc;
                            currentTD.unit = unloadingUnit;
                            currentTD.unitPersNum = unloadingUnit->persNum;
                            currentTD.profession = "w";
                            this->profession = "w";
                        }
                        else
                        {
                            this->profession = "";
                            currentTD.unit = nullptr;
                            currentTD.clicckedCell = nullptr;
                        }
                    }
                    else
                    {
                        currentTD.clicckedCell = td.clicckedCell;
                        currentTD.unit = td.unit;
                        this->profession = "w";
                    }
                }
                else
                {

                    if (!(td.unit && (td.unit->canGiveTree) &&
                          this->isTargetObjValide()))
                    {

                        // if (this->persNum == num && this->targetData.unit) {
                        //     console.log("is here !! change tree-----------------------------------");
                        // }

                        Unit *tree = this->getAnyTree();
                        if (tree)
                        {
                            currentTD.clicckedCell = tree->cell;
                            currentTD.unit = tree;
                            currentTD.unitPersNum = tree->persNum;
                            currentTD.profession = "w";
                            this->profession = "w";
                        }
                        else
                        {
                            this->profession = "";
                            currentTD.unit = nullptr;
                            currentTD.clicckedCell = nullptr;
                        }
                    }
                    else
                    {
                        currentTD.clicckedCell = td.clicckedCell;
                        currentTD.unit = td.unit;
                        this->profession = "w";
                    }
                }
            }
            else if (this->orderOnWay.profession == "g")
            {
                if (this->gold)
                {

                    if (!(td.unit && (td.unit->canTakeGold) &&
                          (this->isTargetObjValide() || td.nextCell)))
                    {

                        Unit *unloadingUnit = this->getBaseForUnloading();
                        if (unloadingUnit)
                        {
                            int rand = intRand(0, unloadingUnit->myCells.length);
                            Cell *ulc = unloadingUnit->myCells.getItem(rand);
                            currentTD.clicckedCell = ulc;
                            currentTD.unit = unloadingUnit;
                            currentTD.unitPersNum = unloadingUnit->persNum;
                            currentTD.profession = "g";
                            this->profession = "g";
                        }
                        else
                        {
                            this->profession = "";
                            currentTD.unit = nullptr;
                            currentTD.clicckedCell = nullptr;
                        }
                    }
                    else
                    {
                        currentTD.clicckedCell = td.clicckedCell;
                        currentTD.unit = td.unit;
                        this->profession = "g";
                    }
                }
                else
                {

                    if (!(td.unit && (td.unit->canGiveGold) &&
                          (this->isTargetObjValide() || td.nextCell)))
                    {

                        Unit *shaht = this->getAnyShaht();
                        if (shaht)
                        {
                            int rand = intRand(0, shaht->myCells.length);
                            Cell *ulc = shaht->myCells.getItem(rand);
                            currentTD.clicckedCell = ulc;
                            currentTD.unit = shaht;
                            currentTD.unitPersNum = shaht->persNum;
                            currentTD.profession = "g";
                            this->profession = "g";
                        }
                        else
                        {
                            currentTD.unit = nullptr;
                            currentTD.clicckedCell = nullptr;
                            this->profession = "";
                        }
                    }
                    else
                    {
                        currentTD.clicckedCell = td.clicckedCell;
                        currentTD.unit = td.unit;
                        this->profession = "g";
                    }
                }
            }

            //
        }

        // if (this->persNum == num) {
        //     if (this->targetData.clicckedCell) {
        //         console.log("td.cell finish = " + to_string(this->targetData.clicckedCell->persNum));
        //     }
        // }

        ///////////////////////////////////////////////////////  => targetData.clear();
        if (
            currentTD.unit != this->targetData.unit ||
            (!currentTD.unit && currentTD.clicckedCell && currentTD.clicckedCell != this->targetData.clicckedCell) ||
            (!currentTD.unit && !currentTD.clicckedCell))
        {

            // if (this->persNum == num && this->targetData.unit)
            // {
            //     console.log("targetData.clear() !!!");
            // }

            this->targetData.clear();
        }
        this->targetData.clicckedCell = currentTD.clicckedCell;
        this->targetData.unit = currentTD.unit;
        this->targetData.profession = currentTD.profession;
        this->targetData.unitPersNum = currentTD.unitPersNum;
        ///////////////////////////////////////////////////////  <= targetData.clear();

        // if (this->persNum == num && this->targetData.unit)
        // {
        //     console.log("order = " + this->targetData.unit->name);
        //     console.log("this->blockedData.isBlocked = ", this->blockedData.isBlocked);
        //     console.log("this->targetData.clicckedCell = ", this->targetData.clicckedCell);
        //     console.log("this->iNeedFreeWay = ", this->iNeedFreeWay);
        // }

       this->selectGetTargetLambda();


        if (this->targetData.clicckedCell && (!this->blockedData.isBlocked //! this->isBlocked
                                              || this->iNeedFreeWay))
        {
            this->getCurrentTarget();
        }
        // this->personalCaseDeep = this->orderOnWay.pcd;
        this->orderOnWay.isComplite = true;

        this->orderOnWay.mt.unlock();
    }
}
