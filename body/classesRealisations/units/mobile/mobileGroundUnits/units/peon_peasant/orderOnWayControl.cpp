#include "holdTimerControl.cpp"
//=>isNeedHoldGoWay

void Peon_peasant::orderOnWayControl()
{

    if (!this->orderOnWay.isComplite
        //&& !this->wayTakts
    )
    {

        Cell *oCell = this->orderOnWay.cell;
        if (this->orderOnWay.profession == "")
        {
            Cell *finishCell = this->way.length ? this->way.getItem(0) : nullptr;
            Unit *tdu = this->targetData.isActual ? this->targetData.unit : nullptr;
            if (!this->cell || oCell->plane != this->cell->plane || oCell->groundUnit == this || finishCell == oCell || (tdu && tdu == oCell->groundUnit && this->way.length))
            { // click on old obj or cell
                this->orderOnWay.isComplite = true;
                return;
            }
            this->targetData.clear();
            Unit *ocu = oCell->groundUnit;
            if (ocu)
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
                    this->targetData.isActual = true;
                }
            }
            else
            {
                this->targetData.clicckedCell = this->orderOnWay.cell;
                this->targetData.unit = nullptr;
                this->targetData.unitPersNum = 0;
                this->targetData.profession = "";
                this->profession = "";
                this->targetData.isActual = true;
            }
        }
        else
        {
            if (this->profession == this->orderOnWay.profession)
            {
                this->orderOnWay.isComplite = true;
                return;
            }
            if (this->orderOnWay.profession == "w")
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
                       // this->targetData.clear();
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
           this->getCurrentTarget();
        this->orderOnWay.isComplite = true;
        // this->potentialWay.clear();
        // this->wayIndex = 0;

       // this->isPotentialWayComplite = false;
        // console.log(this->targetData.unit->name);
    }

    ///////////////////////////////// => inpotent old keys
    // this->preTargetCell
    // this->targetCell
    ///////////////////////////////// <= inpotent old keys

    // if (!this->orderOnWay.isComplite)
    // {
    //     Cell *oCell = this->orderOnWay.cell;
    //     Cell *finishCell = this->way.length ? this->way.getItem(0) : nullptr;
    //     Unit *tarObj = this->targetData.unit ? this->targetData.unit : nullptr;
    //     if (!this->cell ||
    //         (oCell->plane != this->cell->plane) ||
    //         (oCell->groundUnit == this) ||
    //         (finishCell == oCell) ||
    //         (tarObj && tarObj == oCell->groundUnit && this->way.length) || this->isBlockedd(this))
    //     {

    //         this->orderOnWay.isComplite = true;
    //         return;
    //     }

    //         this->getCurrentTarget(oCell);
    //         this->orderOnWay.isComplite = true;
    // }
};