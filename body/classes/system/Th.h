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
    int iter = 0;

    double createCount = 0.1;
    double procCurr = 0;


    bool isBasicActiveProgComplite = true;
    bool isDopActiveProgComplite = true;

    Cell *min_F_cell = nullptr;
    Cell *globalMin_H_cell = nullptr;

    MagistralClaster *min_F_mc = nullptr;
    MagistralClaster *globalMin_H_mc = nullptr;

    Array<ThData *> *thds = nullptr;
    Array<Unit *> dopUnits;
    Array<Cell *> openArr;
    Array<MagistralClaster *> openArrMag;

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
    ////////////////////////////////// => magistral

    void createMagistralWay(Unit *unit);
    void exploreNewMagClasterAndAddToOpenArr(Unit *unit, MagistralClaster *mcFather);
    int get_GMagistral();
    int get_HMagistral(MagistralClaster *potentialMc, MagistralClaster *finishMc);
};

Array<ThData *> thDatas;


