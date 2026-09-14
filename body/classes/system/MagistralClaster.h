#include "Unit.h"
//=>out

class Td_way_data_magistral
{
public:
    //  Td_way_data(){};
    double createCountData = 0;
    int F = 0.0F;
    int H = 0.0F;
    int G = 0.0F;
    double explored = 0;
    double procCurr = 0;
    MagistralClaster *wayFather = nullptr;
    Array<Cell *> validCellsForWayFather;

    Array<Td_way_data_magistral *> bad;
};

class MagistralClaster {
    public:
    MagistralClaster(Cell *cell){
        this->centralCell = cell;
        this->cells.copy(cell->aroundCells);
        this->cells.push(cell);
        this->x = cell->x - cell->gf->cellSize;
        this->y = cell->y - cell->gf->cellSize;
        this->gabarit = cell->gf->cellSize * 3;
    };
    int x = 0;
    int y = 0;
    int gabarit = 0;
    Cell *centralCell = nullptr;
    Array<Cell *> cells;
   // Array<Cell *> validCellsToFather;
    MagistralClaster *up = nullptr;
    MagistralClaster *down = nullptr;
    MagistralClaster *left = nullptr;
    MagistralClaster *right = nullptr;
    Array<Td_way_data_magistral> thwd_mag;
    MagistralClaster *father = nullptr;

    Array<Cell *> upHor;
    Array<Cell *> midHor;
    Array<Cell *> downHor;

    Array<Cell *> leftVer;
    Array<Cell *> midVer;
    Array<Cell *> rightVer;
};