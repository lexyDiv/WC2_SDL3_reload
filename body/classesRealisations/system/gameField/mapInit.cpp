#include "create.cpp"
//=>getDefaultColor

void GameField::mapInit(Array<string> &array)
{
    int cellsCount = this->gabarit * this->gabarit;
    for (int i = 0; i < cellsCount; i++) {
        Cell cell;
        this->game->allCells.push(cell);
    }
    int cc = 0;
    array.forEach([this, &cc](string &str, int ver)
                  {
         Array<Cell *> arr;
        for (int hor = 0; hor < str.size(); hor++) {
            char lit = str[hor];
            cc++;
            Array<Cell> &allCellsData = this->game->allCells;
            Cell *cell = allCellsData.getItemPtr(allCellsData.length - cc);
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