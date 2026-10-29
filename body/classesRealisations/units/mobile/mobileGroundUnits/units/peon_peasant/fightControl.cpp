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

            this->fightTarget->takeDamageByPeon(5);
            // gu->stress = 6;
            // gu->hp -= 5;
            // if (gu->hp <= 0)
            // {

            //     // //// <=  ????????????????????????????????????? MUTEX !!!!!!
            //     this->gf->savePushOnTrups(gu);
            //   // this->fightTarget->deleteTimer = 1;
            //   // this->fightTarget->trupCreate();

            // }
        }
        if (this->inFightTimer == 70)
        {
            this->inFightTimer = 0;
            if (gu->hp <= 0)
            {
                this->targetData.unit = nullptr;
                this->fightTarget = nullptr;
                this->animY = 0;
                this->image = this->fraction->peon.img_2;
                this->wood = 100;
                this->profession = "w";
                this->orderOnWay.go("w");
            }
            else if (!this->orderOnWay.isComplite)
            {
                this->targetData.unit = nullptr;
                this->fightTarget->lesorub = nullptr;
                this->fightTarget = nullptr;
                this->animY = 0;
                // this->profession = "";
            }
        }
        gu->stressControl();
    }
    else
    {
        this->inFightTimer += 2;
        if (this->inFightTimer == 50)
        {
            // console.log("tuk");
            this->fightTarget->takeDamage(-50);
        }
        if (this->inFightTimer == 70)
        {
            this->inFightTimer = 0;
            if (this->fightTarget->hp <= 0 ||
                this->fightTarget->hp >= this->fightTarget->hpMax)
            {
                this->targetData.unit = nullptr;
                this->fightTarget = nullptr;
                this->animY = 0;
            }
            else if (!this->orderOnWay.isComplite)
            {
                this->targetData.unit = nullptr;
                this->fightTarget = nullptr;
                this->animY = 0;
                // this->profession = "";
            }
        }
    }
};