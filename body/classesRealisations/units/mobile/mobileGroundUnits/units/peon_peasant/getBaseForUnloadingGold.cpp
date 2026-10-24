#include "getAnyTree.cpp"
//=>getTreeNear

Unit *Peon_peasant::getBaseForUnloadingGold()
{

    Array<Unit *> validTH;
  
    this->fraction->fTownHoll.townHollsByLevel.forEach([&validTH, this](Array<Unit *> &thblarr)
                                                       { thblarr.forEach([&validTH, this](Unit *thbl)
                                                                         {
            if (thbl->hp > 0 &&
                thbl->cell->plane == this->cell->plane) {
                    validTH.push(thbl);
                } }); });


    if (validTH.length)
    {
        MinData md = validTH.getMinDataU([this](Unit *item)
                                         {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        return dis; });
        Unit *minDisBase = md.unit;
        return minDisBase;
    }
    return nullptr;
};