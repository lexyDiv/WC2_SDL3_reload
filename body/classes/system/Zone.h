#include "Claster.h"
//=>out

class Zone {
    public:
    Array<Cell *> cells;
    Array<Td_way_data_z> thwd;
    Array<Zone *> contactZones;
    Claster *cl = nullptr;

    void getAroundZones();
};