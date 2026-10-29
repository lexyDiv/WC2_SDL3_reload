#include "isGetTarget.cpp"
//=>fightControl

void Peon_peasant::selectAnAction()
{
    Unit *gu = this->targetData.unit;

    if (gu && gu->hp > 0)
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
           // this->image = this->fraction->peon.img_1;
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
};