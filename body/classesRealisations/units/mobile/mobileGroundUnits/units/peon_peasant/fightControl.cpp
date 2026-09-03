#include "selectAnAction.cpp"
//=>standOnCellWait

void Peon_peasant::fightControl()
{
    Unit *gu = this->targetData.unit;
    if (gu &&
        gu->name == "tree")
    {
        this->inFightTimer += 2;
        if (this->inFightTimer == 50)
        {
            gu->stress = 6;
            gu->hp -= 5;
            if (gu->hp <= 0)
            {
                this->cell->gf->trupsOnDelete.push(gu);
            }
        }
        if (this->inFightTimer == 70)
        {
            this->inFightTimer = 0;
            if (gu->hp <= 0)
            {
                this->targetData.unit = nullptr;
                this->inFight = false;
                this->animY = 0;
                this->image = this->fraction->peon.img_2;
                this->wood = 100;
                //// experement
                this->profession = "w";
                Unit *base = this->getBaseForUnloading();
                if (base)
                {
                    this->orderOnWay.isComplite = false;
                    this->orderOnWay.cell = base->cell;
                }
            }
            else if (!this->orderOnWay.isComplite)
            {
                this->targetData.unit = nullptr;
                this->inFight = false;
                this->animY = 0;
                // this->profession = "";
                gu->lesorub = nullptr;
            }
        }
        gu->stressControl();
    }
};