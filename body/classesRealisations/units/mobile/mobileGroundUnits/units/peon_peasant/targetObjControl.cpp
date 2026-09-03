#include "trupCreate.cpp"
//=>PeonPeasant.cpp


void Peon_peasant::targetObjControl() {

        Unit *gu = this->way.length ? this->way.getItem(0)->groundUnit : nullptr;

    if(this->targetData.unit) {
    //console.log(this->targetData.unit->name);
    }
    // if (gu)
    // {
    //     if (gu->name == "tree")
    //     {
    //         this->targetData.unit = gu;
    //         this->targetData.bornCount = gu->bornCount;
    //     }
    // }
};


