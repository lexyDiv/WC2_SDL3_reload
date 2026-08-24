#include "Plane.h"
//=>Unit.h

class ThData
{
public:
    ThData(int num) { this->num = num; };
    ~ThData() {};
    int num = 0;
    Game *game = &gameData;
    int startIndex = 0;
    int finishIndex = 0;

    int dopStartIndex = 0;
    int dopFinishIndex = 0;

    bool isBasicActiveProgComplite = true;
    bool isDopActiveProgComplite = true;

    Array<ThData *> *thds = nullptr;
    Array<Unit *> dopUnits;

    void createMyActiveProgZone(int pathesLength);
    void process();
    bool isAllThreadsBasicComplite();
    bool isAllThreadsDopComplite();
};

Array<ThData *> thDatas;