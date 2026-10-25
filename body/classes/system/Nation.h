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
        }
        else
        {
        }
       
        this->allBuffers.push(&this->peonsBuffer);
        this->allBuffers.push(&this->townHallsBuffer);

    };
    string type = "";

    Array<Unit *> peonsBuffer;
    Array<Unit *> townHallsBuffer;
    Array<Array<Unit *>*> allBuffers;
    
    void addToBuffer(Unit *u);

};

Nation orcs("orcs");
Nation humans("humans");