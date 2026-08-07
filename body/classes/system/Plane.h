#include "Menu.h"
//=>Th

class ToOtherPlane {
    public:
    ToOtherPlane(){};
    ~ToOtherPlane(){};
    Plane *otherPlane = nullptr;
    Array<Cell *> cellsToOther;
};

class Plane {
    public:
    Plane(){};
    ~Plane();

    string type = "";
    int number = 0;
    Array<Cell *> cells;
    Array<ToOtherPlane *> contactPlanes;
    Array<Unit *> trees;
    Array<Unit *> shahts;
    Array<Unit *> oils;
};