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
    void createMyActiveProgZone(int pathesLength);
    void process();
};

Array<ThData *> thDatas;