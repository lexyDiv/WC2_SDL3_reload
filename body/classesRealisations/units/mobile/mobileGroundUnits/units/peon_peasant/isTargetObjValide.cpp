#include "getTreeNear.cpp"
//=>isGetTarget

bool Peon_peasant::isTargetObjValide()
{
    Unit *to = this->targetData.unit;

    if (
        to &&
        ((to->canGiveTree && to->lesorub) ||
         to->hp <= 0 ||
         !to->cell ||
         (to->canGiveGold && !to->gold)))
    {
        return false;
    }

    return true;
}