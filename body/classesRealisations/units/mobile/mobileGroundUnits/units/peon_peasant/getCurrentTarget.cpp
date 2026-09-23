#include "stendOnCellWait.cpp"
//=>inFightAnimation

void Peon_peasant::getCurrentTarget()
{

    this->game->unitsOnWayMT.lock();
    this->game->unitsOnWay.push(this);
    this->game->unitsOnWayMT.unlock();

    // if (this->game->unitsOnWay.length >= 5) {
    //     this->personalCaseDeep = 40;
    //    // console.log("here");
    // }

    this->potentialWay.clear();
    this->wayIndex = 0;

    this->isPotentialWayComplite = false;

    Unit *tdu = this->targetData.unit;

    if (this->iNeedFreeWay)
    {

        
        
        if (tdu)
        {

            if (

                tdu->name == "tree")
            {
                
                this->isOnGetPotentialWayGetTarget = [this](Cell *c)
                {
                    Unit *gu = c->groundUnit;
                    if (
                        gu && gu->name == "tree" && !gu->lesorub)
                    {
                        this->targetData.unit = gu;
                        this->targetData.clicckedCell = gu->cell;

                        return true;
                    }
                    return false;
                };

                // if (!this->iNeedFreeWay)
                // {
                this->isNewCellOnGetWayValide = [this](Cell *c, int iter)
                {
                    Unit *gu = c->groundUnit;

                    Cell *tc = this->cell;

                    if (
                        c->plane == tc->plane &&
                        (!gu ||
                         (gu->type == "life" && !gu->inFight && 
                        (!gu->isActive || !gu->needHolTimer || !gu->isPotentialWayComplite)) ||
                         (gu->name == "tree" && !gu->lesorub)))
                    {

                        return true;
                    }

                    return false;
                };
            }
            else
            {
                this->isOnGetPotentialWayGetTarget = [this](Cell *c)
                {
                    Unit *gu = c->groundUnit;
                    if ( // cell == this->targetCell ||
                        gu && gu == this->targetData.unit)
                    {
                        return true;
                    }
                    return false;
                };

                this->isNewCellOnGetWayValide = [this](Cell *c, int iter)
                {
                    Unit *gu = c->groundUnit;
                    Cell *tc = this->cell;

                    if (
                        c->plane == tc->plane &&
                        (!gu ||
                         (gu->type == "life" && !gu->inFight && 
                        (!gu->isActive || !gu->needHolTimer || !gu->isPotentialWayComplite)) ||
                         gu == this->targetData.unit))
                    {
                        return true;
                    }
                    return false;
                };
            }
        }
        else
        {
            this->isOnGetPotentialWayGetTarget = [this](Cell *c)
            {
                if (
                    // cell == this->targetCell
                    c == this->targetData.clicckedCell)
                {
                    return true;
                }
                return false;
            };

            this->isNewCellOnGetWayValide = [this](Cell *c, int iter)
            {
                Unit *gu = c->groundUnit;
                Cell *tc = this->cell;

                if (
                    c->plane == tc->plane &&
                    (!gu ||
                     c == this->targetData.clicckedCell ||
                     (gu->type == "life" && !gu->inFight && 
                        (!gu->isActive || !gu->needHolTimer || !gu->isPotentialWayComplite))
                     ))
                {
                    return true;
                }
                return false;
            };
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////
    else
    {
        if (tdu)
        {

            if (

                tdu->name == "tree")
            {

                this->isOnGetPotentialWayGetTarget = [this](Cell *c)
                {
                    Unit *gu = c->groundUnit;
                    if (
                        gu && gu->name == "tree" && !gu->lesorub)
                    {
                        this->targetData.unit = gu;
                        this->targetData.clicckedCell = gu->cell;

                        return true;
                    }
                    return false;
                };

                // if (!this->iNeedFreeWay)
                // {
                this->isNewCellOnGetWayValide = [this](Cell *c, int iter)
                {
                    Unit *gu = c->groundUnit;

                    Cell *tc = this->cell;

                    if (gu && gu->needHolTimer)
                    {
                        return false;
                    }

                    if (tc &&
                        c->plane == tc->plane &&
                        (!gu ||
                         (gu->type == "life" && (iter >= 30)) ||
                         gu->way.length ||
                         !gu->isPotentialWayComplite ||
                         (gu->name == "tree" && !gu->lesorub)))
                    {

                        return true;
                    }

                    return false;
                };
            }
            else
            {
                this->isOnGetPotentialWayGetTarget = [this](Cell *c)
                {
                    Unit *gu = c->groundUnit;
                    if ( // cell == this->targetCell ||
                        gu && gu == this->targetData.unit)
                    {
                        return true;
                    }
                    return false;
                };

                this->isNewCellOnGetWayValide = [this](Cell *c, int iter)
                {
                    Unit *gu = c->groundUnit;
                    Cell *tc = this->cell;

                    if (gu && gu->needHolTimer)
                    {
                        return false;
                    }
                    if (
                        c->plane == tc->plane &&
                        (!gu ||
                         (gu->type == "life" && (iter >= 30)) ||
                         gu->wayIndex ||
                         gu == this->targetData.unit))
                    {
                        return true;
                    }
                    return false;
                };
            }
        }
        else
        {
            this->isOnGetPotentialWayGetTarget = [this](Cell *c)
            {
                if (
                    // cell == this->targetCell
                    c == this->targetData.clicckedCell)
                {
                    return true;
                }
                return false;
            };

            this->isNewCellOnGetWayValide = [this](Cell *c, int iter)
            {
                Unit *gu = c->groundUnit;
                Cell *tc = this->cell;
                if (gu && gu->needHolTimer)
                {
                    return false;
                }
                if (
                    c->plane == tc->plane &&
                    (!gu || c == this->targetData.clicckedCell ||
                     (gu->type == "life" && (iter >= 30)) ||
                     gu->wayIndex))
                {
                    return true;
                }
                return false;
            };
        }
    }
}