#include "isGetTarget.cpp"
//=>fightControl

void Peon_peasant::selectAnAction()
{
    Unit *gu = this->targetData.unit;

    if (gu && gu->hp > 0)
    {
        if (
            (gu->canGiveTree && this->wood) ||
            (gu->canGiveGold && this->gold))
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
                (!gu->isComplite || gu->hp < gu->hpMax))
            {
                // console.log("any do");
                // this->image = this->fraction->peon.img_1;
                this->fightTarget = gu;
                //////////////////////////////////////

                Cell *cc = nullptr;

                for (int i = 0; i < this->cell->aroundCells.length; i++)
                {
                    Cell *cac = this->cell->aroundCells.getItem(i);
                    if (cac->groundUnit &&
                        cac->groundUnit == gu)
                    {
                        if (cac == this->cell->left ||
                            cac == this->cell->right ||
                            cac == this->cell->top ||
                            cac == this->cell->bottom)
                        {
                            this->getConor(cac);
                            return;
                        }
                        else
                        {
                           cc = cac;
                        }
                    }
                }

                this->getConor(cc);

                //    int index = gu->contactCells.indexOf(this->cell);
                //    MinData wellComeCell = index != -1 ? gu->wellComeCells.getItem(index) : wellComeCell;
                //    bool is = false;
                //     MinData wellComeCell_2;
                //    console.log(wellComeCell_2.cell);
                //    if (wellComeCell.cell) {
                //     console.log("get conor 1");
                //        this->getConor(wellComeCell.cell);
                //    }
                //    else
                //    {
                //     Cell *cc = nullptr;
                //     for (int i = 0; i < this->cell->aroundCells.length; i++)
                //     {
                //         Cell *cac = this->cell->aroundCells.getItem(i);
                //         if (cac->groundUnit &&
                //             cac->groundUnit == gu)
                //             {
                //                 cc = cac;
                //                 break;
                //             }
                //     }
                //     console.log("get conor");
                //     this->getConor(cc);
                //    }
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