#include "Claster.h"
//=>out

class Zone {
    public:
    Zone() {
        for (int i = 0; i < thDatas.length; i++) {
            Td_way_data_z tdz;
            this->thwd.push(tdz);
        }
    };
   // ~Zone() {};
    Array<Cell *> cells;
    Array<Td_way_data_z> thwd;
    Array<Zone *> contactZones;
    Claster *cl = nullptr;
    Cell *cell = nullptr;
    bool isTeesNear = false;
    Array<Unit *> buildingsNear;
    bool isActive = false;

    void getAroundZones();
    void restart();
};

void Zone::restart() {
    this->isActive = false;
    this->cell = nullptr;
    this->thwd.getItemPtr(0)->explored = 0;
    this->contactZones.clear();
    this->cells.forEach([](Cell *c){
        c->thwd.getItemPtr(0)->explored = 0;
        c->zone = nullptr;
    });
    this->cells.clear();
}