#include "getCellImageCellDrawIndexCellUnitInit.cpp"
//=> offsetControl

void GameField::miniMapHoldLeftMouseKey()
{
    int clickIndexX, clickIndexY;
    clickIndexX = this->dx / this->mcs;
    clickIndexY = this->dy / this->mcs;
    clickIndexX = clickIndexX >= this->gabarit ? this->gabarit - 1 : clickIndexX;
    clickIndexY = clickIndexY >= this->gabarit ? this->gabarit - 1 : clickIndexY;
    //  console.log(to_string(clickIndexX));

    Cell *cell = this->field.getItem(clickIndexY).getItem(clickIndexX);
    if (cell && this->drawCell)
    {
        this->offsetX = (this->x + cell->x) - centerX; 
        this->offsetY = (this->y + cell->y) - centerY; 
    }
}

void GameField::miniMapMouseControl()
{
    bool click = mouse.leftKeyDown;
    bool inMap = false;
    if (mouse.leftKeyUp)
    {
        this->miniMapClick = false;
    }

    if (click)
    {
        int mx = mouse.x;
        int my = mouse.y;
        inMap = !(mx < this->miniMapX || mx > this->miniMapX + this->miniMapGab ||
                  my < this->miniMapY || my > this->miniMapY + this->miniMapGab);
        if (inMap)
        {
            this->miniMapClick = true;
            this->miniMapClickX = mx;
            this->miniMapClickY = my;

            this->dx = this->miniMapClickX - this->miniMapX;
            this->dy = this->miniMapClickY - this->miniMapY;

            this->miniMapHoldLeftMouseKey();
        }
    }

    if (this->miniMapClick)
    {
        double deltaX = mouse.x - this->miniMapClickX;
        double deltaY = mouse.y - this->miniMapClickY;

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