#include "getAnyShaht.cpp"
//=>getBaseForUploadingGold

Unit *Peon_peasant::getAnyTree()
{
    Unit *t = this->getTreeNear();
    if (t)
    {
        return t;
    }

    Unit *base = this->getBaseForUnloading();
    if (base)
    {
        if (this->wood)
        {
            return base;
        }
        for (int i = 0; i < base->orderedTrees.length; i++)
        {
            Unit *tree = base->orderedTrees.getItem(i);
            if (tree->hp > 0 &&
                !tree->lesorub)
            {
                return tree;
            }
        }
    }
    else
    {
        // console.log(to_string(this->cell->plane->trees.length));
        MinData md = this->cell->plane->trees.getMinDataU([this](Unit *item)
                                                         {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = !item->lesorub && item->hp > 0 ? getDis(&delta) : 10000000;
                                                        return dis; });
        Unit *minDisTree = md.unit && md.unit->hp > 0 && !md.unit->lesorub ? md.unit : nullptr;
        return minDisTree;
    }
    // this->plane->trees.clear();
    return nullptr;
};