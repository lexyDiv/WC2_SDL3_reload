#include "isGetTarget.cpp"
//=>fightControl

void Peon_peasant::selectAnAction()
{
    Unit *gu = this->targetObj.unit;

    if (gu)
    {
        // if (this->focus) {
        //     console.log("wood : " + to_string(this->wood));
        //     console.log("target name : " + gu->name);
        //     console.log("--------------------------------------------");
        // }

        if (gu->name == "tree" && this->wood)
        {
            return;
        }
        else if (gu->name == "tree" && !this->wood)
        {
            this->gold = 0;
            this->inFight = true;
            this->getConor(gu->cell);
            gu->lesorub = this;
        }
        else if ((gu->fraction == this->fraction || !gu->fraction) &&
                 gu->type != "life")
        {
            if (
                (!gu->isComplite || gu->hp < gu->hpMax))
            {
                this->inFight = true;
            }
            else
            {
                gu->wellCome(this);
            }
        }
        // else
        // {
        //     gu->wellCome(this);
        // }
    }
};