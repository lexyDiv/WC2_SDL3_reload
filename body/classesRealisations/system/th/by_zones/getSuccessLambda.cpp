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
                if (z->isTeesNear && iter > 1)
                {
                    Array<Unit *> trees;
                    z->cells.forEach([unit, &trees](Cell *c){
                        c->aroundCells.forEach([unit, &trees](Cell *ac){
                            Unit *u = ac->groundUnit;
                            if (u && u->canGiveTree && !u->lesorub && u->hp > 0) {
                                trees.push(u);
                            }
                        });
                    });

                    if (trees.length) {
                        int rand = intRand(0, trees.length);
                        Unit *randTree = trees.getItem(rand);
                        unit->targetData.unit = randTree;
                        unit->targetData.clicckedCell = randTree->cell;
                        return true;
                    }

                    // for (int i = 0; i < z->cells.length; i++) {
                    //     Cell *c = z->cells.getItem(i);
                    //     for (int k = 0; k < c->aroundCells.length; k++) {
                    //         Cell *ac = c->aroundCells.getItem(k);
                    //         Unit *u = ac->groundUnit;
                    //         if (u && u->canGiveTree && !u->lesorub && u->hp > 0) {
                    //            unit->targetData.unit = u;
                    //            unit->targetData.clicckedCell = u->cell;
                    //            // console.log("here");
                    //           // console.log("here ", iter);
                    //             return true;
                    //         }
                    //     }
                }
                   // return true;
                
                
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