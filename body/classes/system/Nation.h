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

        /////////////////////////////
        for (int i = 0; i < 2; i++)
        {
            Array<Trace *> buffer;
            this->allTracesBuffers.push(buffer);
        }

    };
    string type = "";

    Array<Unit *> peonsBuffer;
    Array<Unit *> townHallsBuffer;
    Array<Array<Unit *>*> allBuffers;

    //////////////////////////////////////////
    Array<Array<Trace *>> allTracesBuffers;
    Trace *getTraceFromBuffer(int);
    ///////////////////////////////////////////////
    
    void addToAllTracesBuffers(Trace *t);



    void addToBuffer(Unit *u);

};

Nation orcs("orcs");
Nation humans("humans");