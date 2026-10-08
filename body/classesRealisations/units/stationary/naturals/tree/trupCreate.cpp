#include "stressControl.cpp"
//=>drawTrup


void Tree::trupCreate()
{
    this->alpha -= 5;
    this->deleteTimer--;
    if (!this->deleteTimer)
    {
        this->cell->groundUnit = nullptr;
        this->gf->addClasterOnUpdate(this->cell->claster);
    }
    else if (this->deleteTimer == 49)
    {
        this->cell->ripUnits.push(this);
        this->x = this->saveX;
    }
};