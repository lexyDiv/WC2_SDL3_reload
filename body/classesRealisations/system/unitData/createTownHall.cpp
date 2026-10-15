#include "createPeon.cpp"
//=>out

void UnitData::createTownHall(Fraction *fraction)
{
    if (fraction->nation->type == "orcs")
    {
        if (fraction->color == "red")
        {
            this->img_1 = imager.townHallOrcRed;
           // this->img_2 = imager.peonWithWoodRed;
           // this->img_3 = imager.peonWithGoldRed;
        }
    }
    hpByLevel.push(1200);
    hpByLevel.push(1600);
    hpByLevel.push(2000);
};