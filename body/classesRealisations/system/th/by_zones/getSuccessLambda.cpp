#include "byCl_potentialWayCreate.cpp"
//=>out


void ThData::getSuccessLambda(Unit *unit)
{

    this->successWay = [](Zone *z)
    {
        return false;
    };

    TargetData *td = &unit->targetData;
    if (td->unit)
    {
        if (td->unit->canGiveTree)
        {
            this->successWay = [this, unit](Zone *z)
            {
                if (z->isTeesNear)
                {
                    for (int i = 0; i < z->cells.length; i++) {
                        Cell *c = z->cells.getItem(i);
                        for (int k = 0; k < c->aroundCells.length; k++) {
                            Cell *ac = c->aroundCells.getItem(k);
                            Unit *u = ac->groundUnit;
                            if (u && u->canGiveTree && !u->lesorub && u->hp > 0) {
                                unit->targetData.unit = u;
                                unit->targetData.clicckedCell = u->cell;
                                console.log("here");
                                return true;
                            }
                        }
                    }
                    return true;
                }
                return false;
            };
        }
        else if (td->unit->type == "building")
        {
            this->successWay = [this, td](Zone *z)
            {
                return isMyBuildingNeare(z, td);
            };
        }
    }
}