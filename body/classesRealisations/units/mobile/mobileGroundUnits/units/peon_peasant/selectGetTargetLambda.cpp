#include "drawTrup.cpp"
//=>updateTargetData

void Peon_peasant::selectGetTargetLambda()
{

    TargetData &td = this->targetData;
    //
    if (
        this->profession != "")
    {

        // if (this->focus)
        // {
        //     console.log("select lambda by prof = ");
        // }

        if (this->personalCaseDeep == 3)
        {
            if (this->wood)
            {
                // if (this->focus)
                // {
                //     console.log("selct lambda 1 = ");
                // }

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

                // if (this->focus)
                // {
                //     console.log("selct lambda 2 = ");
                // }

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
        }
        else 
        if (td.unit)
        {

            // if (this->focus)
            // {
            //     console.log("selct lambda 3 = ");
            // }

            if (td.unit->canTakeGold)
            {

                // if (this->focus)
                // {
                //     console.log("selct lambda 4 = " + td.unit->name);
                // }

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

                // if (this->focus)
                // {
                //     console.log("selct lambda 5 = ");
                // }

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

                // if (this->focus)
                // {
                //     console.log("selct lambda on tree 6 = ");
                // }

                this->isGetTargetLambda = [this](Cell *c)
                {
                    Unit *cgu = c->groundUnit;
                    // if (this->focus && cgu)
                    // {
                    //     console.log("================================");
                    //     console.log("cgu = ", cgu);
                    //     console.log("cgu->canGiveTree = ", cgu->canGiveTree);
                    //     console.log("cgu->hp > 0 = ", cgu->hp > 0);
                    //     console.log("!cgu->lesorub = ", !cgu->lesorub);
                    // }
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

                // if (this->focus)
                // {
                //     console.log("selct lambda 7 = ");
                // }

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
    }
    else
    {
        if (td.unit)
        {

            // if (this->focus)
            // {
            //     console.log("selct lambda 8 = ");
            // }

            this->isGetTargetLambda = [this, td](Cell *c)
            {
                Unit *cgu = c->groundUnit;
                if (cgu &&
                    cgu == td.unit)
                {
                    return true;
                }
                return false;
            };
        }
        else
        {

            // if (this->focus)
            // {
            //     console.log("selct lambda 9 = ");
            // }

            this->isGetTargetLambda = [](Cell *c)
            {
                return false;
            };
        }
    }
}