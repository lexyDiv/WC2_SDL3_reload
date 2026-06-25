#include "create.cpp"
//=>getDefaultColor

void GameField::mapInit(Array<string> &array)
{
    array.forEach([this](string &str, int ver)
                  {
         Array<Cell *> arr;
        for (int hor = 0; hor < str.size(); hor++) {
            char lit = str[hor];
             Cell *cell = new Cell;
            cell->mapColor = this->getDefaultColor(lit);
            cell->ver = ver;
            cell->hor = hor;
            cell->x = hor * this->cellSize;
            cell->y = ver * this->cellSize;
            cell->gabX = this->cellSize;
            cell->gabY = this->cellSize;
            cell->centerX = cell->x + cell->gabX / 2;
            cell->centerY = cell->y + cell->gabY / 2;
            cell->gf = this;
            cell->game = this->game;
            cell->litera = lit;
            arr.push(cell);
        } 
        this->field.push(arr); });
}