#include "fightControl.cpp"
//=>units_out

void Peon_peasant::updateCurrentTarget()
{
    if (this->profession == "w")
    {
        Unit *newTree = this->getAnyTree();
        if (newTree)
        {
            this->orderOnWay.isComplite = false;
            this->orderOnWay.cell = newTree->cell;
            this->orderOnWay.unit = newTree;
        }
        else
        {
            this->profession = "";
            this->targetObj.unit = nullptr;
            // console.log("no tree 2");
        }
    }
    else if (this->profession == "g")
    {
        Unit *newShaht = this->getAnyShaht();
        if (newShaht)
        {
            this->orderOnWay.isComplite = false;
            this->orderOnWay.cell = newShaht->cell;
            this->orderOnWay.unit = newShaht;
        }
        else
        {
            this->profession = "";
            this->targetObj.unit = nullptr;
            //  console.log("no shaht");
        }
    }
    else
    {

        // this->profession = "";
        //  console.log("??? " + this->profession);
        // this->targetObj.unit = nullptr;
    }
};