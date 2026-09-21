#include "Unit.h"
//=>out

class Td_way_data_magistral
{
public:
    Td_way_data_magistral(){
      validCellsToFather.reserv(9);
    };
    double createCountData = 0;
    float F = 0.0F;
    float H = 0.0F;
    float G = 0.0F;
    double explored = 0;
    double procCurr = 0;
    MagistralClaster *wayFather = nullptr;
    bool addOnWay = false;
    float last_G = 0;
    Array<Cell *> validCellsToFather;

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
        thwd_mag.reserv(10);
    };
    float x = 0;
    float y = 0;
    float ver = 0;
    float hor = 0;
    int gabarit = 0;
    Cell *centralCell = nullptr;
    Array<Cell *> cells;
    
    MagistralClaster *up = nullptr;
    MagistralClaster *upLeft = nullptr;
    MagistralClaster *upRight = nullptr;
    MagistralClaster *down = nullptr;
    MagistralClaster *downLeft = nullptr;
    MagistralClaster *downRight = nullptr;
    MagistralClaster *left = nullptr;
    MagistralClaster *right = nullptr;
    Array<MagistralClaster *> aroundMc;
    Array<Td_way_data_magistral> thwd_mag;
    MagistralClaster *father = nullptr;

     Array<Cell *> upHor;
    // Array<Cell *> midHor;
     Array<Cell *> downHor;

     Array<Cell *> leftVer;
    // Array<Cell *> midVer;
     Array<Cell *> rightVer;

     Array<Cell *> upRightConor;
     Array<Cell *> upLeftConor;
     Array<Cell *> downRightConor;
     Array<Cell *> downLeftConor;
};
