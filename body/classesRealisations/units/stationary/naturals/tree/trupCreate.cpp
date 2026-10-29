#include "stressControl.cpp"
//=>drawTrup

void Tree::trupCreate()
{
    this->alpha -= 5;
    if (!this->deleteTimer)
    {
        this->cell->ripUnits.push(this);
        
    }
    else if (this->deleteTimer == 50)
    {
        this->x = this->saveX;
        this->gf->addClasterOnUpdate(this->cell->claster);
        this->cell->groundUnit = nullptr;
        this->readyToLightDelete = true;
    }
    this->deleteTimer++;
};