#include "createPeon.cpp"
//=>out

void UnitData::createTownHall(Fraction *fraction)
{
    if (fraction->nation->type == "orcs")
    {
        if (fraction->color == "red")
        {
            this->img_1 = imager.townHallOrcRed;
            this->img_2 = imager.strongholdOrcRed;
            this->img_3 = imager.fortressOrcRed;
            this->img_4 = imager.land_construction_site;
        }
    }
    hpByLevel.push(1200);
    hpByLevel.push(1600);
    hpByLevel.push(2000);
};