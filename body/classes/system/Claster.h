#include "Unit.h"
//=>Zones


class Claster {
    public:
    int gab = 0;
    int size = 0;
    Claster(Cell *cell, Game *game);
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

};