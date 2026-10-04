#include "create.cpp"
//=>getDefaultColor

void GameField::mapInit(Array<string> &array)
{
    int cellsCount = this->gabarit * this->gabarit;
    for (int i = 0; i < cellsCount; i++)
    {
        Cell cell;
        cell.persNum = i;
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

    /////////////////////////////////////////////////////////////////////////////////////=> clasters

    int linesCount = (this->gabarit / this->clasterGabarit);

    // console.log("clastarsCount = ", clastersCount);

    this->clasters.reserv(linesCount);

    int startIndex = (this->clasterGabarit - 1) / 2;
    int step = this->clasterGabarit;
    int length = this->field.length;

    for (int ver = startIndex; ver < length; ver += step)
    {
        Array<Cell *> &line = this->field.getItemLnk(ver);
        Array<Claster> lineClasters;
        lineClasters.reserv(linesCount);
        for (int hor = startIndex; hor < length; hor += step)
        {
            // console.log("hor = ", hor);
            Cell *c = line.getItem(hor);
            Claster claster(c, this->game);
            lineClasters.push(claster);
        }
        this->clasters.push(lineClasters);
    }

    // console.log("length = ", this->clasters.length);
}