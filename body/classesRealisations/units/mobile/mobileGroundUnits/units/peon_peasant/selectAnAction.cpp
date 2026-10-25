#include "isGetTarget.cpp"
//=>fightControl

void Peon_peasant::selectAnAction()
{
    Unit *gu = this->targetData.unit;

    if (gu)
    {
        if (
            (gu->canGiveTree && this->wood) ||
            (gu->canGiveGold && this->gold)
           )
        {
            return;
        }
        else if (gu->canGiveTree && !this->wood)
        {
            this->gold = 0;
            this->image = this->fraction->peon.img_1;
            this->fightTarget = gu;
            this->getConor(gu->cell);
            gu->lesorub = this;
        }
        else if (
            gu->fraction == this->fraction &&
            gu->canStandStill)
        {
            if (gu->hp &&
                (!gu->isComplite || gu->hp < gu->hpMax)
            )
            {
               // console.log("any do");
            this->image = this->fraction->peon.img_1;
            this->fightTarget = gu;
            //////////////////////////////////////
           int index = gu->contactCells.indexOf(this->cell);
           MinData wellComeCell = index != -1 ? gu->wellComeCells.getItem(index) : wellComeCell;
           if (wellComeCell.cell) {
           // console.log("get conor");
               this->getConor(wellComeCell.cell);
           }
            /////////////////////////////////////
            
            }
            else if (
                (gu->canTakeGold && this->gold) ||
                (gu->canTakeWood && this->wood))
            {
                gu->wellCome(this);
            }
        }
        else if (gu->canGiveGold)
        {
            gu->wellCome(this);
        }
    }

    //     if (gu)
    //     {
    //         console.log("here");
    //         // if (this->focus) {
    //         //     console.log("wood : " + to_string(this->wood));
    //         //     console.log("target name : " + gu->name);
    //         //     console.log("--------------------------------------------");
    //         // }

    //         if (gu->canGiveTree && this->wood)
    //         {
    //             console.log("here 2");
    //             return;
    //         }
    //         else if (gu->canGiveTree && !this->wood)
    //         {
    //             console.log("here 3");
    //             this->gold = 0;
    //             this->fightTarget = true;
    //             this->getConor(gu->cell);
    //             gu->lesorub = this;
    //         }
    //         else if ((gu->fraction == this->fraction
    //             //|| !gu->fraction
    //         ) &&
    //                  gu->type != "life")
    //         {
    //            console.log("here 4");
    //             if (
    //                 (!gu->isComplite || gu->hp < gu->hpMax))
    //             {
    //                // console.log("here 2");
    //                 this->fightTarget = true;
    //             }
    //             else
    //             {
    //                // if (this->wood || this->gold){
    // //console.log("here 3");
    // console.log("here 5");
    //                 gu->wellCome(this);
    //                // }
    //             }
    //         }
    //         // else
    //         // {
    //         //     gu->wellCome(this);
    //         // }
    //         console.log("here 6");
    //     }
};