#include "isActiveCheck.cpp"
//=>getAnyShaht

void Peon_peasant::updateCurrentTarget()
{

    if (this->profession != "")
    {
        this->orderOnWay.profession = this->profession;
        this->orderOnWay.isComplite = false;
    }
    else if (this->targetData.clicckedCell)
    {
        this->orderOnWay.cell = this->targetData.clicckedCell;
        this->orderOnWay.isComplite = false;
    }
    else if (this->targetData.unit && this->targetData.unit->cell && this->targetData.unit->hp)
    {
        this->orderOnWay.cell = this->targetData.unit->cell;
        this->orderOnWay.isComplite = false;
    }
    else
    {
        this->profession = "";
        this->targetData.unit = nullptr;
        this->targetData.clear();
    }

    // if (this->profession == "w")
    // {
    //     Unit *newTree = this->getAnyTree();
    //     if (newTree)
    //     {
    //         this->orderOnWay.isComplite = false;
    //         this->orderOnWay.cell = newTree->cell;
    //         this->orderOnWay.unit = newTree;
    //     }
    //     else
    //     {
    //         this->profession = "";
    //         //this->targetData.unit = nullptr;
    //         this->targetData.clear();
    //     }
    // }
    // else if (this->profession == "g")
    // {
    //     Unit *newShaht = this->getAnyShaht();
    //     if (newShaht)
    //     {
    //         this->orderOnWay.isComplite = false;
    //         this->orderOnWay.cell = newShaht->cell;
    //         this->orderOnWay.unit = newShaht;
    //     }
    //     else
    //     {
    //         this->profession = "";
    //         this->targetData.unit = nullptr;
    //         this->targetData.clear();
    //     }
    // }
};