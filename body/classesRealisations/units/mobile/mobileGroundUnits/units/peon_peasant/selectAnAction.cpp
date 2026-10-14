#include "isGetTarget.cpp"
//=>fightControl

void Peon_peasant::selectAnAction()
{
    Unit *gu = this->targetData.unit;

    if (gu)
    {
        // if (this->focus) {
        //     console.log("wood : " + to_string(this->wood));
        //     console.log("target name : " + gu->name);
        //     console.log("--------------------------------------------");
        // }

        if (gu->canGiveTree && this->wood)
        {
            return;
        }
        else if (gu->canGiveTree && !this->wood)
        {
            this->gold = 0;
            this->inFight = true;
            this->getConor(gu->cell);
            gu->lesorub = this;
        }
        else if ((gu->fraction == this->fraction 
            //|| !gu->fraction
        ) &&
                 gu->type != "life")
        {
           // console.log("here");
            if (
                (!gu->isComplite || gu->hp < gu->hpMax))
            {
               // console.log("here 2");
                this->inFight = true;
            }
            else
            {
               // if (this->wood || this->gold){
//console.log("here 3");
                gu->wellCome(this);
               // }
            }
        }
        // else
        // {
        //     gu->wellCome(this);
        // }
    }
};