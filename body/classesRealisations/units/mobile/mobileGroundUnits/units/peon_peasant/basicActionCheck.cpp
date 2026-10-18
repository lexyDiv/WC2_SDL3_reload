#include "selectGetTargetLambda.cpp"
// => out

bool Peon_peasant::basicActionCheck()
{

   bool isGet = false;

    if (
        !this->wayTakts &&
        (this->wayIndex <= 15) &&
        this->isPotentialWayComplite &&
        this->way.length &&
        !this->needHolTimer &&
        !this->fightTarget &&
        !this->isIgetMyTarget)
    {

        Unit *to = this->targetData.unit;

        if (to)
        {

            bool isTOValide = this->isTargetObjValide();

            if (!isTOValide)
            {

                this->stendOnCell();
                this->updateCurrentTarget();
            }
        }
        this->isGetTarget();

        if (this->isIgetMyTarget)
        {
            isGet = true;
            this->stendOnCell();
            this->isIgetMyTarget = false;
            this->selectAnAction();
        }
    }

    return isGet;
}
