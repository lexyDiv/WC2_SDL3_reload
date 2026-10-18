#include "drawTrup.cpp"
//=>basicActionCheck

void Peon_peasant::selectGetTargetLambda()
{

    TargetData &td = this->targetData;

    if (
        this->profession != "")
    {
        if (this->personalCaseDeep == 3)
        {
            if (this->wood)
            {
                this->isGetTargetLambda = [this](Cell *c)
                {
                    Unit *cgu = c->groundUnit;
                    if (
                        cgu &&
                        cgu->fraction == this->fraction &&
                        (cgu->canTakeWood || cgu->canTakeGold))
                    {
                        return true;
                    }
                    return false;
                };
            }
            else if (this->gold)
            {
                this->isGetTargetLambda = [this](Cell *c)
                {
                    Unit *cgu = c->groundUnit;
                    if (
                        cgu &&
                        cgu->fraction == this->fraction &&
                        cgu->canTakeGold)
                    {
                        return true;
                    }
                    return false;
                };
            }
            else
            {
                this->isGetTargetLambda = [](Cell *c)
                {
                    return false;
                };
            }
        }
        else if (td.unit)
        {
            if (td.unit->canTakeGold)
            {
                this->isGetTargetLambda = [this](Cell *c)
                {
                    Unit *cgu = c->groundUnit;
                    if (cgu &&
                        cgu->fraction == this->fraction &&
                        cgu->canTakeGold)
                    {
                        return true;
                    }
                    return false;
                };
            }
            else if (td.unit->canTakeWood)
            {
                this->isGetTargetLambda = [this](Cell *c)
                {
                    Unit *cgu = c->groundUnit;
                    if (cgu &&
                        cgu->fraction == this->fraction &&
                        (cgu->canTakeGold || cgu->canTakeWood))
                    {
                        return true;
                    }
                    return false;
                };
            }
            else if (td.unit->canGiveTree)
            {
                // console.log("here");
                this->isGetTargetLambda = [this](Cell *c)
                {
                    Unit *cgu = c->groundUnit;
                    if (
                        cgu &&
                        cgu->canGiveTree &&
                        cgu->hp > 0 &&
                        !cgu->lesorub)
                    {
                        return true;
                    }
                    return false;
                };
            }
            else if (td.unit->canGiveGold)
            {
                this->isGetTargetLambda = [this](Cell *c)
                {
                    Unit *cgu = c->groundUnit;
                    if (
                        cgu &&
                        cgu->canGiveGold &&
                        cgu->gold)
                    {
                        return true;
                    }
                    return false;
                };
            }
        }
        else
        {
            this->isGetTargetLambda = [](Cell *c)
            {
                return false;
            };
        }
    }
    else // => logic continue here !!!
    {
        if (td.unit)
        {
            this->isGetTargetLambda = [td](Cell *c)
            {
                if (td.unit == c->groundUnit)
                {
                    return true;
                }
                return false;
            };
        }
        else
        {
            this->isGetTargetLambda = [](Cell *c)
            {
                return false;
            };
        }
    }
}