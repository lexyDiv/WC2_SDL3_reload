#include "getCellImageCellDrawIndexCellUnitInit.cpp"
//=> offsetControl

void GameField::miniMapHoldLeftMouseKey()
{
    int clickIndexX, clickIndexY;
    clickIndexX = this->dx / this->mcs;
    clickIndexY = this->dy / this->mcs;
    
    clickIndexX = clickIndexX >= this->gabarit ? this->gabarit - 1 : clickIndexX;
    clickIndexY = clickIndexY >= this->gabarit ? this->gabarit - 1 : clickIndexY;


    Cell *cell = this->field.getItem(clickIndexY).getItem(clickIndexX);
    if (cell && this->drawCell) {
    int deltaIndexX = this->drawCell->hor - cell->hor;
    int deltaIndexY = this->drawCell->ver - cell->ver;
    int deltaScrollX = deltaIndexX * this->cellSize;
    int deltaScrollY = deltaIndexY * this->cellSize;
    this->offsetX -= deltaScrollX;
    this->offsetY -= deltaScrollY;
    }
}


void GameField::miniMapMouseControl()
{
    bool click = mouse.leftKeyDown;
    if (mouse.leftKeyUp)
    {
        this->miniMapClick = false;
       // mouse.leftKeyUp = false;
    }
    if (click)
    {
        int mx = mouse.x;
        int my = mouse.y;
        if (!(mx < this->miniMapX || mx > this->miniMapX + this->miniMapGab ||
              my < this->miniMapY || my > this->miniMapY + this->miniMapGab))
        {
            this->miniMapClick = true;
            this->miniMapClickX = mx;
            this->miniMapClickY = my;

            this->dx = this->miniMapClickX - this->miniMapX;
            this->dy = this->miniMapClickY - this->miniMapY;

            this->miniMapHoldLeftMouseKey();
        }
       // mouse.leftKeyDown = false;
    }

    if (this->miniMapClick)
    {
        float deltaX = mouse.x - this->miniMapClickX;
        float deltaY = mouse.y - this->miniMapClickY;

        if (deltaX || deltaY)
        {
            int clickIndexX, clickIndexY;
            this->dx += deltaX;
            this->dy += deltaY;

            this->dx = this->dx < 0 ? 0 : this->dx;
            this->dx = this->dx > this->miniMapGab - this->mcs ? this->miniMapGab - this->mcs : this->dx;
            this->dy = this->dy < 0 ? 0 : this->dy;
            this->dy = this->dy > this->miniMapGab - this->mcs ? this->miniMapGab - this->mcs : this->dy;

            this->miniMapHoldLeftMouseKey();
        }

        this->miniMapClickX = mouse.x;
        this->miniMapClickY = mouse.y;
    }
    
}