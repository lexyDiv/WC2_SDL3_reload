#include "Claster.h"
//=>out

class Zone {
    public:
    Zone() {};
    ~Zone() {};
    Array<Cell *> cells;
    Array<Td_way_data_z> thwd;
    Array<Zone *> contactZones;
    Claster *cl = nullptr;
    Cell *cell = nullptr;
    bool isTeesNear = false;
    Array<Unit *> buildingsNear;

    void getAroundZones();
};