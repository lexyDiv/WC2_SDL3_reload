#include "Peon_peasant.cpp"
//=>orderOnWayControl

void Peon_peasant::holdTimerControl()
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
};