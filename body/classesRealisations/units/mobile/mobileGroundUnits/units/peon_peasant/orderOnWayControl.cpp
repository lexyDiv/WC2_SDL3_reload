#include "holdTimerControl.cpp"
//=>isNeedHoldGoWay

void Peon_peasant::orderOnWayControl()
{

    this->orderOnWay.mt.lock();
    if (!this->orderOnWay.isComplite &&
        this->orderOnWay.isUpdate)
    {

        console.log("order");

        // if (
        //     this->blockedData.isBlocked &&
        //     this->blockedData.type == 'f' &&
        //     this->personalCaseDeep != 3)
        // {
        //     this->iNeedFreeWay = true; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! <= ON !!! 2/3
        // }

        if (this->targetData.clicckedCell && (!this->blockedData.isBlocked //! this->isBlocked
                                              || this->iNeedFreeWay))
        {

            this->getCurrentTarget();
        }

        this->orderOnWay.isComplite = true;
    }

    this->orderOnWay.mt.unlock();
};