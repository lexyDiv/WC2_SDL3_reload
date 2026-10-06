#include "Plane.h"
//=>Unit.h

class ThData
{
public:
    ThData(int num) { this->num = num; this->hold = num; };
    ~ThData() {};
    int num = 0;
    Game *game = &gameData;
    int startIndex = 0;
    int finishIndex = 0;

    int dopStartIndex = 0;
    int dopFinishIndex = 0;
    int hold = 0;
    int deep = 30000;
    int lowDeep = 40;
    bool isMagistral = false;

    int iter = 0;

    double createCount = 0;
    double procCurr = 0;


    bool isBasicActiveProgComplite = true;
    bool isDopActiveProgComplite = true;

    Cell *min_F_cell = nullptr;
    Cell *globalMin_H_cell = nullptr;

    Array<ThData *> *thds = nullptr;
    Array<Unit *> dopUnits;
    Array<Cell *> openArr;

    void createMyActiveProgZone(int pathesLength);
    void process();
    bool isAllThreadsBasicComplite();
    bool isAllThreadsDopComplite();

    void PWProcess();
    void createPotentialWay(Unit *unit);
    void exploreNewCellAndAddToOpenArr(Unit *unit, Cell *fatherCell, Cell *potentialCell);
    bool isBlocked(Cell *cell, Unit *unit);
    void getCurrentTargetCell(Unit *unit);
    void potentialWayCreate(Unit *unit, Cell *finalCell);

    int get_G(Cell *fatherCell, Cell *potentialCell);
    int get_H(Cell *potentialCell, Cell *finishCell);

    Cell *targetCell = nullptr;
    //Unit exploredUnit = Peon_peasant(nullptr);

    int count = 0;
    Uint64 timeBeforeUnitWay = 0;

    //////////////////////////////// => clasters
    void byCl_createPW(Unit *unit);
    void byCl_exploreNewZone(Unit *unit, Zone *fatherZone, Zone *sonZone, int i);
    int byCl_get_G(Zone *fatherZone, Zone *sonZone);
    int byCl_get_H(Zone *exploredZone, Claster *cl);
    void byCl_potentialWayCreate(Unit *unit, Zone *finalZone);
    void getSuccessLambda();
    Array<Zone *> openArr_z;

    Zone *min_F_zone = nullptr;
    Zone *globalMin_H_zone = nullptr;

    function<bool(Zone *zone)> successWay = [this](Zone *zone){
        return false;
    };

};

Array<ThData *> thDatas;


