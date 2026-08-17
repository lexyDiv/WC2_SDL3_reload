#include "getAnyTree.cpp"
//=>getTreeNear

Unit *Peon_peasant::getBaseForUnloadingGold()
{
    if (this->fraction->fTownHoll.townHolls.length)
    {
        MinData md = this->fraction->fTownHoll.townHolls.getMinDataU([this](Unit *item)
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