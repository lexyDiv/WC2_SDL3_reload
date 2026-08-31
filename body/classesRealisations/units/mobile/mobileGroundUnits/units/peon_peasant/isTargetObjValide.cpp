#include "getTreeNear.cpp"
//=>isGetTarget

bool Peon_peasant::isTargetObjValide()
{
    Unit *to = this->targetData.unit;
    if (to->name == "tree")
    {
        if (to->lesorub ||
            to->hp <= 0 ||
           // !to->cell ||
            to->isBlockedd(this)
           )
        {
            return false;
        }
    }
    else if (to->hp <= 0 ||
             !to->cell ||
             (to->name == "shaht" && !to->gold) ||
             to->isBlockedd(this))
    {
        return false;
    } 
    return true;
}