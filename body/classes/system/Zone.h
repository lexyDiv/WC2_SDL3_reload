#include "Claster.h"
//=>out

class Zone {
    public:
    Array<Cell *> cells;
    Array<Td_way_data> thwd;
    Array<Zone *> contactZones;
   // Array<float> distsToContactZones;
};