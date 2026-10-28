#include "stressControl.cpp"
//=>drawTrup

void Tree::trupCreate()
{
    this->alpha -= 5;
    if (!this->deleteTimer)
    {
        this->gf->addClasterOnUpdate(this->cell->claster);
    }
    else if (this->deleteTimer == 50)
    {
        this->cell->ripUnits.push(this);
        this->x = this->saveX;
        this->cell->groundUnit = nullptr;
        this->readyToLightDelete = true;
    }
    this->deleteTimer++;
};