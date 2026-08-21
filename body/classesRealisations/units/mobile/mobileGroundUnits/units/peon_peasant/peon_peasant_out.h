#include "getCurrentTarget.cpp"
//=>units_out

void Peon_peasant::getCurrentTarget(Cell *cell) {
       this->preTargetCell = cell;
    // this->profession = "";
    this->potentialWay.clear();
    this->wayIndex = 0;

    this->isPotentialWayComplite = false;
    this->targetCell = nullptr;
    //this->targetObjControl = this->unitMenu->targetObjControl;
    this->targetObj.unit = nullptr;


   // console.log(to_string(this->deep));

    if (cell->groundUnit)
    {

        this->targetObj.unit = cell->groundUnit;
        this->targetObj.bornCount = cell->groundUnit->bornCount;

        if (this->fraction->control == "human" &&
        &this->fraction->nation == &targetObj.unit->fraction->nation)
        {
            this->profession = this->gold > 0 && this->targetObj.unit->name == "greatHall" ? "g" : this->profession;
            this->profession = this->wood > 0 && (this->targetObj.unit->name == "greatHall" || this->targetObj.unit->name == "mill") ? "w" : this->profession;
        }



        if (cell->groundUnit->name == "tree")
        {
            this->profession = "w";
            if (this->wood)
            {
                Unit *base = this->getBaseForUnloading();
                if (base)
                {
                    this->getHandTarget(base->cell);
                    return;
                }
            }
            //this->targetObjControl = this->fraction->control == "" ? this->unitMenu->targetObjControlWoodComp : this->unitMenu->targetObjControlWood;
            this->isOnGetPotentialWayGetTarget = [this](Cell *cell)
            {
                Unit *gu = cell->groundUnit;
                if (
                    gu && gu->name == "tree")
                {
                    this->targetObj.unit = gu;
                    this->targetObj.bornCount = gu->bornCount;
                    return true;
                }
                return false;
            };

            if (!this->iNeedFreeWay)
            {
                this->isNewCellOnGetWayValide = [this](Cell *cell)
                {
                    Unit *gu = cell->groundUnit;
                    Cell *tc = this->cell;
                    if (tc &&
                        cell->plane == tc->plane &&
                        (!gu ||
                         gu->potentialWay.length ||
                         (gu->fraction && gu->fraction->unionCase != this->fraction->unionCase &&
                          gu->isWarrior) ||
                         (gu->name == "tree" && !gu->lesorub)))
                    {
                        return true;
                    }
                    return false;
                };
            }
            else
            {
                this->isNewCellOnGetWayValide = [this](Cell *cell)
                {
                    Unit *gu = cell->groundUnit;
                    Cell *tc = this->cell;
                    if (tc &&
                        cell->plane == tc->plane &&
                        (!gu ||
                         gu->type == "life" ||
                         gu->name == "tree" && !gu->lesorub))
                    {
                        return true;
                    }
                    return false;
                };
            }
        }
        else
        {
            if (cell->groundUnit->name == "shaht")
            {
                this->profession = "g";
                if (this->gold > 0)
                {
                    Unit *base = this->getBaseForUnloadingGold();
                    if (base)
                    {
                        this->getHandTarget(base->cell);
                        return;
                    }
                }
            };
            // if (cell->groundUnit->type != "life")
            // {
            //     this->targetObjControl = this->fraction->control == "" ? this->unitMenu->targetObjControlBuildingComp : this->unitMenu->targetObjControlBuilding;
            // }
            this->isOnGetPotentialWayGetTarget = [this](Cell *cell)
            {
                Unit *gu = cell->groundUnit;
                if ( // cell == this->targetCell ||
                    gu == this->targetObj.unit)
                {
                    return true;
                }
                return false;
            };

            if (!this->iNeedFreeWay)
            {
                this->isNewCellOnGetWayValide = [this](Cell *cell)
                {
                    Unit *gu = cell->groundUnit;
                    Cell *tc = this->cell;
                    if (tc &&
                        cell->plane == tc->plane &&
                        (!gu ||
                         gu->potentialWay.length ||
                         gu == this->targetObj.unit))
                    {
                        return true;
                    }
                    return false;
                };
            }
            else
            {
                this->isNewCellOnGetWayValide = [this](Cell *cell)
                {
                    Unit *gu = cell->groundUnit;
                    Cell *tc = this->cell;
                    if (tc &&
                        cell->plane == tc->plane &&
                        (!gu ||
                         gu->type == "life" ||
                         gu == this->targetObj.unit))
                    {
                        return true;
                    }
                    return false;
                };
            }
        }
    }
    else
    {
        if (this->fraction->control == "human")
        {
            this->profession = "";
        }
        this->isOnGetPotentialWayGetTarget = [this](Cell *cell)
        {
            if (cell == this->targetCell)
            {
                return true;
            }
            return false;
        };

        this->isNewCellOnGetWayValide = [this](Cell *cell)
        {
            Unit *gu = cell->groundUnit;
            Cell *tc = this->cell;
            if (tc &&
                cell->plane == tc->plane &&
                (!gu ||
                 gu->potentialWay.length))
            {
                return true;
            }
            return false;
        };
    }

    // if (this->cell && this->cell->game->unitsOnWay.indexOf(this) == -1)
    // {
    //     this->game->unitsOnWay.push(this);
    // }
    if (!this->isActive)
    {
        this->isActive = true;
       // this->fraction->activeUnits.push(this);
    }
}