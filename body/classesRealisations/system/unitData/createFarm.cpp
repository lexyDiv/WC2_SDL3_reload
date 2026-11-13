#include "createTownHall.cpp"
//=>out

void UnitData::createFarm(Fraction *fraction)
{
    //console.log("here");
    if (fraction->nation->type == "orcs")
    {
        if (fraction->color == "red")
        {
            this->construction = imager.land_construction_site;
            this->img_1 = imager.farm_orc_red;
           // console.log("here = ", this->construction);
        }
    }
}