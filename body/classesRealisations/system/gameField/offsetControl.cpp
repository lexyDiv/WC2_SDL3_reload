#include "miniMapMouseControl.cpp"
//=>miniMapDraw

int iter = 0;

void GameField::offsetControl()
{
    int mx = mouse.x;
    int my = mouse.y;
    int maxOffsetX = this->width - this->centerX * 2;
    int maxOffsetY = this->height - this->centerY * 2;

    if (mx <= 0 && this->offsetX > 0)
    {
        this->offsetX -= this->offsetStep;
    }
    else if (mx >= ctx.SCREEN_WIDTH - 1)
    {
        this->offsetX += this->offsetStep;
    } 

    if (my <= 0)
    {
        this->offsetY -= this->offsetStep;
    }
    else if (my >= ctx.SCREEN_HEIGHT - 1)
    {
        this->offsetY += this->offsetStep;
    }

    if (this->offsetX < 0)
    {
        this->offsetX = 0;
    }
    if (this->offsetX > maxOffsetX)
    {
        this->offsetX = maxOffsetX;
    }

    if (this->offsetY < 0)
    {
        this->offsetY = 0;
    }
    if (this->offsetY > maxOffsetY)
    {
        this->offsetY = maxOffsetY;
    }

    this->drawOffsetX = this->x + this->offsetX + this->centerX;
    this->drawOffsetY = this->y + this->offsetY + this->centerY;

    int offsetIndexX = (this->drawOffsetX) / this->cellSize;
    int offsetIndexY = (this->drawOffsetY - this->y) / this->cellSize;


    this->drawCell = this->field.getItem(offsetIndexY).getItem(offsetIndexX);
    this->drawDeltaX = this->x - this->offsetX;
    this->drawDeltaY = this->y - this->offsetY;


    ////////////////////////////////////////////////////////////////////////////////
    bool clickLeft = mouse.leftKeyDown;
    bool clickLeftUp = mouse.leftKeyUp;
    bool clickRight = mouse.rightKeyDown;

    int x = mouse.x;
    int y = mouse.y;

    float drawDeltaX = this->drawDeltaX;
    float drawDeltaY = this->drawDeltaY;


    ////////////////////////////////////////////////////////////////// => VREMENNO DEBUG !!!!
    if (clickRight) {
           int cx = x - drawDeltaX;
     int cy = y - drawDeltaY;
     int xIndex = cx / this->cellSize;
     int yIndex = cy / this->cellSize;
     if (xIndex < this->gabarit && yIndex < this->gabarit) {
        Cell *tc = this->field.getItemPtr(yIndex)->getItem(xIndex);
              if (this->focusUnit) {
                this->focusUnit->orderOnWay.go(tc);
                this->focusUnit->isActive = true;
              }
     }
    }

   if (clickLeft) {
     int cx = x - drawDeltaX;
     int cy = y - drawDeltaY;
     int xIndex = cx / this->cellSize;
     int yIndex = cy / this->cellSize;
     if (xIndex < this->gabarit && yIndex < this->gabarit) {
        Cell *tc = this->field.getItemPtr(yIndex)->getItem(xIndex);
        if (tc->groundUnit && tc->groundUnit->type == "life") {
            if (this->focusUnit) {
                this->focusUnit->focus = false;
            }
            tc->groundUnit->focus = true;
            this->focusUnit = tc->groundUnit;
        } else {
                if (this->focusUnit) {
                this->focusUnit->focus = false;
            }
            this->focusUnit = nullptr;
        }
     }
   }

    //////////////////////////////////////////////////////////////////
    // iter++;
    // if (iter == 1)
    // {
    //     iter = 0;
    //     ProtoObj *unit = this->game->objMenu->unit;
    //     if (unit //&& !unit->isPotentialWayComplite
    //              //  && !unit->isActive
    //     )
    //     {
    //         // console.log("here");
    //         int indexX = intRand(0, this->gabarit); // ceil((x - drawDeltaX) / cellSize) - 1;
    //         // console.log("index x = " + to_string(indexX));
    //         int indexY = intRand(0, this->gabarit); // ceil((y - drawDeltaY - this->y) / cellSize);
    //         Order *order = unit->orderOnWay ? unit->orderOnWay : new Order;
    //         ProtoObj *cell = this->field.getItem(indexY).getItem(indexX);
    //         order->cell = cell;
    //         order->isComplite = false;
    //         unit->orderOnWay = order;
    //         if (!unit->isActive)
    //         {
    //             unit->isActive = true;
    //             unit->fraction->activeUnits.push(unit);
    //         }
    //     }
    // }
}