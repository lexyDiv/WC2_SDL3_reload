#include "selectGetTargetLambda.cpp"
//=>out

Unit *Peon_peasant::updateTargetData()
{

    if (!this->orderOnWay.isComplite &&
        !this->fightTarget)
    {


        // console.log("update---------------------------------");

        this->orderOnWay.mt.lock();

        TargetData newTD;

        // if (
        //     this->blockedData.isBlocked &&
        //     this->blockedData.type == 'f' &&
        //     this->personalCaseDeep != 3)
        // {
        //     this->iNeedFreeWay = true; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! <= ON !!! 2/3
        // }

        this->orderOnWay.isUpdate = true;

        string prof = this->orderOnWay.profession;
        Cell *oc = this->orderOnWay.cell;
        Unit *ocu = oc ? oc->groundUnit : nullptr;

       // this->targetData.clear();

        this->targetData.specialFreeG0 = this->orderOnWay.specialFreeG0;
        this->personalCaseDeep = this->orderOnWay.pcd;

        if (
            oc &&
                (oc == this->cell ||
                 oc->plane != this->cell->plane) ||
            (ocu &&
             ((!ocu->fraction && !ocu->canGiveGold && !ocu->canGiveTree) ||
              ocu->canMove)))
        {
            this->orderOnWay.isComplite = true;
            this->way.clear();
            this->wayIndex = 0;
            this->orderOnWay.stop = false;
            if (this->profession != "") {
                console.log("kill prof 1 + pers = ", this->personalCaseDeep);
                console.log("is target ", targetData.unit);
                if (this->orderOnWay.cell) {
                    console.log("order cell gu = ", this->orderOnWay.cell->groundUnit);
                } else {
                    console.log("order prof = " + orderOnWay.profession);
                }
                console.log("-----------------------------");
            }
            this->profession = "";

            // if (this->profession == "") {
            //     console.log("kill prof 1");
            // }
           // console.log("kill prof 1");
            this->orderOnWay.mt.unlock();
            // if (this->focus) {
            //     console.log("update obnull");
            // }
            return nullptr;
        }

        ///////////////////////////////////////////
        if (this->orderOnWay.profession == "")
        {

            if (ocu && ocu->type != "life")
            {
                if (ocu->name == "tree")
                {
                    if (this->wood)
                    {
                        Unit *unloadingUnit = this->getBaseForUnloading();
                        if (unloadingUnit)
                        {
                            int rand = intRand(0, unloadingUnit->myCells.length);
                            Cell *ulc = unloadingUnit->myCells.getItem(rand);
                            //this->targetData.clicckedCell = ulc;
                           // this->targetData.unit = unloadingUnit;
                           newTD.clicckedCell = ulc;
                           newTD.unit = unloadingUnit;

                            this->targetData.unitPersNum = unloadingUnit->persNum;
                            this->targetData.profession = "w";
                            this->profession = "w";
                            this->targetData.isActual = true;
                        }
                    }
                    else
                    {
                       // this->targetData.clicckedCell = ocu->cell;
                       // this->targetData.unit = ocu;
                            newTD.clicckedCell = ocu->cell;
                           newTD.unit = ocu;
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
                        int rand = intRand(0, ocu->myCells.length);
                        Cell *ulc = ocu->myCells.getItem(rand);
                       // this->targetData.clicckedCell = ulc;
                        //this->targetData.unit = ocu;
                            newTD.clicckedCell = ulc;
                           newTD.unit =  ocu;                      
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "w";
                        this->profession = "w";
                        this->targetData.isActual = true;
                    }
                    else if (this->gold)
                    {
                        int rand = intRand(0, ocu->myCells.length);
                        Cell *ulc = ocu->myCells.getItem(rand);
                       // this->targetData.clicckedCell = ulc;
                       // this->targetData.unit = ocu;
                           newTD.clicckedCell = ulc;
                           newTD.unit =  ocu;                      
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "g";
                        this->profession = "g";
                        this->targetData.isActual = true;
                    }
                    else
                    {
                        //                         if (this->focus) {
                        //     console.log("update th ");
                        // }
                       // this->targetData.clicckedCell = ocu->cell;
                       // this->targetData.unit = ocu;
                        newTD.clicckedCell = ocu->cell;
                           newTD.unit = ocu;
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "";
                                    if (this->profession != "") {
                console.log("kill prof ssss");
            }
                        this->profession = "";
                        this->targetData.isActual = true;
                        console.log("kill prof 2");
                    }
                }
                else if (ocu->name == "lamberMill")
                {
                    if (this->wood)
                    {
                        int rand = intRand(0, ocu->myCells.length);
                        Cell *ulc = ocu->myCells.getItem(rand);
                        //this->targetData.clicckedCell = ulc;
                       // this->targetData.unit = ocu;
                           newTD.clicckedCell = ulc;
                           newTD.unit =    ocu;                    
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "w";
                        this->profession = "w";
                        this->targetData.isActual = true;
                    }
                    else
                    {

                       // this->targetData.clicckedCell = ocu->cell;
                       // this->targetData.unit = ocu;
                            newTD.clicckedCell = ocu->cell;
                           newTD.unit =   ocu;                    
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "";
                                    if (this->profession != "") {
                console.log("kill prof rrrrrrrr");
            }
                        this->profession = "";
                        this->targetData.isActual = true;
                        console.log("kill prof 3");
                    }
                }
                else if (ocu->name == "shaht")
                {
                    if (this->gold)
                    {
                        Unit *unloadingUnit = this->getBaseForUnloadingGold();
                        if (unloadingUnit)
                        {

                            int rand = intRand(0, unloadingUnit->myCells.length);
                            Cell *ulc = unloadingUnit->myCells.getItem(rand);
                           // this->targetData.clicckedCell = ulc;
                           // this->targetData.unit = unloadingUnit;
                            newTD.clicckedCell = ulc;
                           newTD.unit = unloadingUnit;                          
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
                        int rand = intRand(0, ocu->myCells.length);
                        Cell *ulc = ocu->myCells.getItem(rand);
                        //this->targetData.clicckedCell = ulc;
                       // this->targetData.unit = ocu;
                            newTD.clicckedCell = ulc;
                           newTD.unit =   ocu;                    
                        this->targetData.unitPersNum = ocu->persNum;
                        this->targetData.profession = "g";
                        this->profession = "g";
                        this->targetData.isActual = true;
                    }
                }
                else
                {

                   // this->targetData.clicckedCell = ocu->cell;
                   // this->targetData.unit = ocu;
                            newTD.clicckedCell = ocu->cell;
                           newTD.unit =     ocu;              
                    this->targetData.unitPersNum = ocu->persNum;
                    this->targetData.profession = "";
                                if (this->profession != "") {
                console.log("kill prof gggggggggggg");
            }
                    this->profession = "";
                    this->targetData.isActual = true;
                    console.log("kill prof 4");
                }
            }
            else
            {
               // this->targetData.clicckedCell = this->orderOnWay.cell;
               // this->targetData.unit = nullptr;
                            newTD.clicckedCell = this->orderOnWay.cell;
                           newTD.unit =    nullptr;           
                this->targetData.unitPersNum = 0;
                this->targetData.profession = "";
                this->profession = (this->personalCaseDeep == 3 || this->personalCaseDeep == 300) ? this->profession : "";
                this->targetData.isActual = true;
            }
        }
        else
        {
            if (this->orderOnWay.profession == "w")
            {
                if (this->wood)
                {

                    Unit *unloadingUnit = this->getBaseForUnloading();

                    if (unloadingUnit)
                    {
                        int rand = intRand(0, unloadingUnit->myCells.length);
                        Cell *ulc = unloadingUnit->myCells.getItem(rand);
                       // this->targetData.clicckedCell = ulc;
                       // this->targetData.unit = unloadingUnit;
                           newTD.clicckedCell = ulc;
                           newTD.unit =    unloadingUnit;                    
                        this->targetData.unitPersNum = unloadingUnit->persNum;
                        this->targetData.profession = "w";
                        this->profession = "w";
                        this->targetData.isActual = true;
                    }
                    else
                    {
                                    if (this->profession != "") {
                console.log("kill prof ffffffffffffffffffffffffff");
            }
                        this->profession = "";
                    }
                }
                else
                {

                    Unit *tree = this->getAnyTree();
                    if (tree)
                    {
                       // this->targetData.clicckedCell = tree->cell;
                       // this->targetData.unit = tree;

                            newTD.clicckedCell = tree->cell;
                           newTD.unit =  tree;                     
                        this->targetData.unitPersNum = tree->persNum;
                        this->targetData.profession = "w";
                        this->profession = "w";
                        this->targetData.isActual = true;
                    }
                    else
                    {
                                    if (this->profession != "") {
                console.log("kill prof hhhhhhhhhhhhhhhhhhhhh");
            }
                        this->profession = "";

                    }
                }
            }
            else if (this->orderOnWay.profession == "g")
            {
                if (this->gold)
                {

                    Unit *unloadingUnit = this->getBaseForUnloading();

                    if (unloadingUnit)
                    {
                        int rand = intRand(0, unloadingUnit->myCells.length);
                        Cell *ulc = unloadingUnit->myCells.getItem(rand);
                       // this->targetData.clicckedCell = ulc;
                       // this->targetData.unit = unloadingUnit;
                           newTD.clicckedCell = ulc;
                           newTD.unit =   unloadingUnit;                     
                        this->targetData.unitPersNum = unloadingUnit->persNum;
                        this->targetData.profession = "g";
                        this->profession = "g";
                        this->targetData.isActual = true;
                    }
                    else
                    {
                                    if (this->profession != "") {
                console.log("kill prof vvvvvvvvvvvvvvvvvvvvvvvvv");
            }
                        this->profession = "";

                    }
                }
                else
                {

                    Unit *shaht = this->getAnyShaht();
                    if (shaht)
                    {
                        int rand = intRand(0, shaht->myCells.length);
                        Cell *ulc = shaht->myCells.getItem(rand);
                        //this->targetData.clicckedCell = ulc;
                       // this->targetData.unit = shaht;

                            newTD.clicckedCell = ulc;
                           newTD.unit =              shaht;         
                        this->targetData.unitPersNum = shaht->persNum;
                        this->targetData.profession = "g";
                        this->profession = "g";
                        this->targetData.isActual = true;
                    }
                }
            }
        }
        /////////////////////////////////////////////

        if (!this->targetData.clicckedCell && !this->targetData.unit)
        {
            this->orderOnWay.isComplite = true;
            this->way.clear();
            this->wayIndex = 0;
            this->orderOnWay.stop = false;
        }
        else
        {
            this->selectGetTargetLambda();
        }

        if (this->targetData.unit != newTD.unit ||
            (!this->targetData.unit && this->targetData.clicckedCell != newTD.clicckedCell)) {
            this->targetData.clear();
        }
        this->targetData.unit = newTD.unit;
        this->targetData.clicckedCell = newTD.clicckedCell;
         

        this->orderOnWay.mt.unlock();

        return this->targetData.unit;
    }

    return nullptr;
}