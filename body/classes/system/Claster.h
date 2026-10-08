#include "Unit.h"
//=>Zones


class Claster {
    public:
    int gab = 0;
    int size = 0;
    int num = 0;
    Claster(Cell *cell, Game *game, int ver, int hor);
    ~Claster();
    Array<Zone> allZones;
    Array<Zone *> zones;
    Array<Cell *> cells;
    Cell *cell = nullptr;
    int ver = 0;
    int hor = 0;
    int x = 0;
    int y = 0;
    Game *game = nullptr;
    GameField *gf = nullptr;
    Array<Claster *> aroundClasters;
    Array<int> aroundClasters_G;
    ThData *td = thDatas.getItem(0); // ??????????????????????
    bool addOnUpdate = false;

    void getZones();
    void create();

    /////////////////////////// => debug

    bool isUpdated = false;
    bool isTouchUpdated = false;

};