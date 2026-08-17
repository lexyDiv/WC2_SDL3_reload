#include "getBaseForUnloadingGold.cpp"
//=>isTargetObjValide

Unit *Peon_peasant::getTreeNear()
{
    Array<Unit *> ft;
    for (int i = 0; i < this->cell->maxAroundCells.length; i++)
    {
        Unit *obj = this->cell->maxAroundCells.getItem(i)->groundUnit;
        if (obj &&
            obj->name == "tree" &&
            !obj->lesorub &&
            obj->hp > 0)
        {
            ft.push(obj);
        }
    }
    if (!ft.length)
    {
        return nullptr;
    }
    MinData md = ft.getMinDataU([this](Unit *item)
                               {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = !item->lesorub && item->hp > 0 ? getDis(&delta) : 10000000;
                                                        return dis; });
    Unit *minDisTree = md.unit;
    return minDisTree;
}