#include "updateCurrentTarget.cpp"
//=>getAnyTree

Unit *Peon_peasant::getAnyShaht()
{
    Unit *th = this->getBaseForUnloadingGold();
    if (th)
    {
        if (this->gold > 0)
        {
            return th;
        }
        for (int i = 0; i < th->orderedShahts.length; i++)
        {
            Unit *shaht = th->orderedShahts.getItem(i);
            if (shaht->gold > 0)
            {
                return shaht;
            }
        }
    }

    MinData md = this->cell->plane->shahts.getMinDataU([this](Unit *item)
                                                      {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = item->gold > 0 && item->hp > 0 ? getDis(&delta) : 10000000;
                                                        return dis; });
    Unit *minDisShaht = md.unit && md.unit->gold > 0 ? md.unit : nullptr;
    return minDisShaht;
};