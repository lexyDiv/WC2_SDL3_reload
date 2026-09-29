#include "holdTimerControl.cpp"
//=>isNeedHoldGoWay

void Peon_peasant::orderOnWayControl()
{

    this->orderOnWay.mt.lock();
    if (!this->orderOnWay.isComplite)
    {

        if (this->inSave)
        {
            this->orderOnWay.isComplite = true;
            this->orderOnWay.mt.unlock();
            console.log("inSave with order");
            return;
        }

        this->personalCaseDeep = this->orderOnWay.pcd;
        Cell *oCell = this->orderOnWay.cell;
        Unit *oCellGU = oCell ? oCell->groundUnit : nullptr;

        if (this->orderOnWay.stop || oCellGU == this)
        {
            this->targetData.clear();
            this->way.clear();
            this->wayIndex = 0;
            this->orderOnWay.isComplite = true;
            this->orderOnWay.stop = false;
            this->profession = "";
            this->orderOnWay.mt.unlock();
            if (this->focus) {
                console.log("STOP");
            }
            return;
        }

        if (
            (this->blockedData.isBlocked && this->blockedData.type == 'f') // this->isBlockedd_full(this)
            && this->personalCaseDeep != 3                                 //&& this->orderOnWay.specialFreeG0
        )
        {
            this->iNeedFreeWay = true; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! <= ON !!! 2/3
        }

        if (this->orderOnWay.profession == "")
        {

            this->targetData.clear();
            // if (this->focus) {
            //     console.log("NO Prof in order");
            // }
            this->targetData.specialFreeG0 = this->orderOnWay.specialFreeG0;

            Unit *ocu = oCell->groundUnit;
            if (ocu && ocu->type != "life")
            {
                if (ocu->name == "tree")
                {
                    if (this->wood)
                    {
                        Unit *unloadingUnit = this->getBaseForUnloading();
                        if (unloadingUnit)
                        {
                            this->targetData.clicckedCell = unloadingUnit->cell;
                            this->targetData.unit = unloadingUnit;
                            this->targetData.unitPersNum = unloadingUnit->persNum;
                            this->targetData.profession = "w";
                            this->profession = "w";
                            this->targetData.isActual = true;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        // console.log("here - 2");
                        this->targetData.clicckedCell = ocu->cell;
                        this->targetData.unit = ocu;
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "w";
                        this->profession = "w";
                        this->targetData.isActual = true;
                    }
                }
                else if (ocu->name == "greatHall")
                {
                    if (this->wood)
                    {
                        this->targetData.clicckedCell = ocu->cell;
                        this->targetData.unit = ocu;
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "w";
                        this->profession = "w";
                        this->targetData.isActual = true;
                    }
                    else if (this->gold)
                    {
                        this->targetData.clicckedCell = ocu->cell;
                        this->targetData.unit = ocu;
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "g";
                        this->profession = "g";
                        this->targetData.isActual = true;
                    }
                    else
                    {
                        this->targetData.clicckedCell = ocu->cell;
                        this->targetData.unit = ocu;
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "";
                        this->profession = "";
                        this->targetData.isActual = true;
                        // console.log("here");
                    }
                }
                else if (ocu->name == "lamberMill")
                {
                    if (this->wood)
                    {
                        this->targetData.clicckedCell = ocu->cell;
                        this->targetData.unit = ocu;
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "w";
                        this->profession = "w";
                        this->targetData.isActual = true;
                    }
                    else
                    {
                        this->targetData.clicckedCell = ocu->cell;
                        this->targetData.unit = ocu;
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "";
                        this->profession = "";
                        //  console.log("here 2");
                        this->targetData.isActual = true;
                    }
                }
                else if (ocu->name == "shaht")
                {
                    if (this->gold)
                    {
                        Unit *unloadingUnit = this->getBaseForUnloadingGold();
                        if (unloadingUnit)
                        {
                            this->targetData.clicckedCell = unloadingUnit->cell;
                            this->targetData.unit = unloadingUnit;
                            this->targetData.unitPersNum = unloadingUnit->persNum;
                            this->targetData.profession = "g";
                            this->profession = "g";
                            this->targetData.isActual = true;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        this->targetData.clicckedCell = ocu->cell;
                        this->targetData.unit = ocu;
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "g";
                        this->profession = "g";
                        this->targetData.isActual = true;
                    }
                }
                else
                {
                    this->targetData.clicckedCell = ocu->cell;
                    this->targetData.unit = ocu;
                    this->targetData.unitPersNum = ocu->persNum;
                    this->targetData.profession = "";
                    this->profession = "";
                    // console.log("here 3");
                    this->targetData.isActual = true;
                }
            }
            else
            {
                //               if (this->focus)
                // {
                //     console.log("order else before: prof = " + this->profession + " d = " + to_string(this->personalCaseDeep));
                // }
                this->targetData.clicckedCell = this->orderOnWay.cell;
                this->targetData.unit = nullptr;
                this->targetData.unitPersNum = 0;
                this->targetData.profession = "";
                this->profession = (this->personalCaseDeep == 3 || this->personalCaseDeep == 300) ? this->profession : "";
                // console.log("here 4 " + this->profession + " " + to_string((bool)this->metka));
                this->targetData.isActual = true;
                // this->metka = false;
            }
        }
        else
        {
            this->targetData.specialFreeG0 = this->orderOnWay.specialFreeG0;

            TargetData &td = this->targetData;

            // if (td.unit &&
            //     this->orderOnWay.cell &&
            //     (this->orderOnWay.cell->groundUnit != td.unit || !this->isTargetObjValide()))
            // {
            //     this->targetData.clear();
            // }

            if (this->orderOnWay.profession == "w")
            {
                if (this->wood)
                {

                    if (!(td.unit && (td.unit->name == "greatHall" || td.unit->name == "lamberMill") &&
                          this->isTargetObjValide()))
                    {

                        //        if (this->focus) {
                        //     console.log("-----------------------------------");
                        //     console.log("td.unit = " + to_string((bool)td.unit));
                        //     if (td.unit) {
                        //     console.log("g || l = " + to_string((td.unit->name == "greatHall" || td.unit->name == "lamberMill")));
                        //     }
                        //     console.log("valid = " + to_string(this->isTargetObjValide()));
                        //     console.log("-----------------------------------");
                        // }
                        td.clear();

                        Unit *unloadingUnit = this->getBaseForUnloading();
                        if (unloadingUnit)
                        {
                            this->targetData.clicckedCell = unloadingUnit->cell;
                            this->targetData.unit = unloadingUnit;
                            this->targetData.unitPersNum = unloadingUnit->persNum;
                            this->targetData.profession = "w";
                            this->profession = "w";
                            this->targetData.isActual = true;
                        }
                        else
                        {
                        }
                    } else {
                     //console.log("old townHall");
                            if (this->focus) {
                         //   console.log("in order on profession NO CLEAR");
                        }
                    }
                }
                else
                {

                    if (!(td.unit && (td.unit->name == "tree") &&
                          this->isTargetObjValide()))
                    {

                        td.clear();


                        Unit *tree = this->getAnyTree();
                        if (tree)
                        {
                            // console.log("here");
                            this->targetData.clicckedCell = tree->cell;
                            this->targetData.unit = tree;
                            this->targetData.unitPersNum = tree->persNum;
                            this->targetData.profession = "w";
                            this->profession = "w";
                            this->targetData.isActual = true;
                        }
                        else
                        {
                            this->profession = "";
                            this->targetData.clear();
                            this->targetData.specialFreeG0 = this->orderOnWay.specialFreeG0;
                            // console.log("here 5");
                        }
                    }
                }
            }
            else if (this->orderOnWay.profession == "g")
            {
                if (this->gold)
                {

                    if (!(td.unit && (td.unit->name == "greatHall") &&
                          this->isTargetObjValide()))
                    {

                        td.clear();

                        Unit *unloadingUnit = this->getBaseForUnloading();
                        if (unloadingUnit)
                        {
                            this->targetData.clicckedCell = unloadingUnit->cell;
                            this->targetData.unit = unloadingUnit;
                            this->targetData.unitPersNum = unloadingUnit->persNum;
                            this->targetData.profession = "g";
                            this->profession = "g";
                            this->targetData.isActual = true;
                        }
                        else
                        {
                        }
                    }
                }
                else
                {

                    if (!(td.unit && (td.unit->name == "shaht") &&
                          this->isTargetObjValide()))
                    {

                        td.clear();



                        Unit *shaht = this->getAnyShaht();
                        if (shaht)
                        {
                            this->targetData.clicckedCell = shaht->cell;
                            this->targetData.unit = shaht;
                            this->targetData.unitPersNum = shaht->persNum;
                            this->targetData.profession = "g";
                            this->profession = "g";
                            this->targetData.isActual = true;
                        }
                        else
                        {
                        }
                    }
                }
            }

            //
        }

        // if (this->focus) {
        //     if (this->targetData.clicckedCell) {
        //         console.log("td.cell finish = " + to_string(this->targetData.clicckedCell->persNum));
        //     }
        // }

        if (this->targetData.clicckedCell && (!this->blockedData.isBlocked //! this->isBlocked
                                              || this->iNeedFreeWay))
        {
            this->getCurrentTarget();
        }
        // this->personalCaseDeep = this->orderOnWay.pcd;
        this->orderOnWay.isComplite = true;
    }

    this->orderOnWay.mt.unlock();
};