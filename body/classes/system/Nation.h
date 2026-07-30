#include "Menu.h"
//=>Plane


class Nation
{
public:
    Nation() {};
    Nation(string type, string color)
    {
        this->type = type;
        this->color = color;
        if (type == "orc")
        {
            if (color == "red")
            {
                this->peon = imager.peonRed;
                this->peonWithWood = imager.peonWithWoodRed;
                this->peonWithGold = imager.peonWithGoldRed;
                this->greateHall = imager.townHallOrcRed;
                this->mapColor = { R: 255, G: 0, B: 0 };
            }
        }
        else
        {
        }
    };
    string type = "";
    string color = "";
    Color mapColor;
    Image *peon = nullptr;
    Image *peonWithWood = nullptr;
    Image *peonWithGold = nullptr;
    Image *greateHall = nullptr;
    Image *greateHall2 = nullptr;
    Image *greateHall3 = nullptr;
};

class NationsHub
{
public:
    Nation redOrcs = Nation("orc", "red");

    NationsHub()
    {
        this->orcs.push(this->redOrcs);
    }
    Array<Nation> orcs;
    Array<Nation> humans;
};

NationsHub nationsHub;