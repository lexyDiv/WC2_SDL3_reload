#include "UnitData.h"
//=>Fraction


class Nation  // only too nations = orcs & peoples
{
public:
    Nation() {};
    Nation(string type)
    {
        this->type = type;
       // this->color = color;
        if (type == "orcs")
        {
            // if (color == "red")
            // {
            //     this->peon = imager.peonRed;
            //     this->peonWithWood = imager.peonWithWoodRed;
            //     this->peonWithGold = imager.peonWithGoldRed;
            //     this->greateHall = imager.townHallOrcRed;
            //     this->mapColor = { R: 255, G: 0, B: 0 };
            // }
        }
        else
        {
        }
    };
    string type = "";
   // string color = "";
  //  Color mapColor;
    ///////////////////////// => peon
    // Image *peon = nullptr;
    // Image *peonWithWood = nullptr;
    // Image *peonWithGold = nullptr;
    // float peon_peasant_sight = 1.0f;
    // float peon_peasant_speed = 1.0f;
    // float peon_peasant_hpMax = 50.0f;
    // /////////////////////////// <= peon
    // Image *greateHall = nullptr;
    // Image *greateHall2 = nullptr;
    // Image *greateHall3 = nullptr;
};

Nation orcs("orcs");
Nation humans("humans");