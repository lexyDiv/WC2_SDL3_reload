#include "Peon_peasant.cpp"
//=>orderOnWayControl

int Peon_peasant::holdTimerControl()
{
    if (this->outHoldTimer == 30)
    {
        this->outHoldTimer--;
        this->iAmHere();
    }
    else if (this->outHoldTimer)
    {
        this->outHoldTimer--;
    }

     if (this->outHoldTimer == 1)
    {
        if (this->profession != "")
        {
            this->orderOnWay.go(this->profession);
        }
    }

    return this->outHoldTimer;
};