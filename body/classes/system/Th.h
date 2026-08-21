#include "Plane.h"
//=>Unit.h

class ThData
{
public:
    ThData(int num) { this->num = num; };
    ~ThData() {};
    int num = 0;
    Game *game = &gameData;
    void process();
};

Array<ThData *> thDatas;