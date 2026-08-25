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
    int deep = 10000;

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
};

Array<ThData *> thDatas;