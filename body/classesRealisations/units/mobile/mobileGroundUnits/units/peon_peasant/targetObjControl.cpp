#include "trupCreate.cpp"
//=>PeonPeasant.cpp

void Peon_peasant::targetObjControl()
{
    Unit *gu = this->way.length ? this->potentialWay.getItem(0)->groundUnit : nullptr;

    if(this->targetObj.unit) {
    //console.log(this->targetObj.unit->name);
    }
    // if (gu)
    // {
    //     if (gu->name == "tree")
    //     {
    //         this->targetObj.unit = gu;
    //         this->targetObj.bornCount = gu->bornCount;
    //     }
    // }
}