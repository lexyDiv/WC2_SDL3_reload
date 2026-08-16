#include "mobileGroundUnit_in.h"
//=> mobGU goWayANIMATION

void MobileGroundUnit::getDeltasXY(Cell *nextCell) {
            double startDis = 0;
        // this->wayTakts = 0;
        if (this->cell->left == nextCell)
        {
            this->wayDeltaX = this->fraction->peon.leftDeltaX;
            this->wayDeltaY = this->fraction->peon.leftDeltaY;
            startDis = this->gf->cellSize;
            this->conor = this->fraction->peon.conorLeft;
            this->animX = 6 * this->animGabX;
        }
        else if (this->cell->right == nextCell)
        {
            this->wayDeltaX = this->fraction->peon.rightDeltaX;
            this->wayDeltaY = this->fraction->peon.rightDeltaY;
            startDis = this->gf->cellSize;
            this->conor = this->fraction->peon.conorRight;
            this->animX = 2 * this->animGabX;
        }
        else if (this->cell->top == nextCell)
        {
            this->wayDeltaX = this->fraction->peon.topDeltaX;
            this->wayDeltaY = this->fraction->peon.topDeltaY;
            startDis = this->gf->cellSize;
            this->conor = this->fraction->peon.conorTop;
            this->animX = 0 * this->animGabX;
        }
        else if (this->cell->bottom == nextCell)
        {
            this->wayDeltaX = this->fraction->peon.bottomDeltaX;
            this->wayDeltaY = this->fraction->peon.bottomDeltaY;
            startDis = this->gf->cellSize;
            this->conor = this->fraction->peon.conorBottom;
            this->animX = 4 * this->animGabX;
        }
        else if (this->cell->top_left == nextCell)
        {
            this->wayDeltaX = this->fraction->peon.top_leftDeltaX;
            this->wayDeltaY = this->fraction->peon.top_leftDeltaY;
            startDis = this->gf->degDis;
            this->conor = this->fraction->peon.conorTop_left;
            this->animX = 7 * this->animGabX;
        }
        else if (this->cell->top_right == nextCell)
        {
            this->wayDeltaX = this->fraction->peon.top_rightDeltaX;
            this->wayDeltaY = this->fraction->peon.top_rightDeltaY;
            startDis = this->gf->degDis;
            this->conor = this->fraction->peon.conorTop_right;
            this->animX = 1 * this->animGabX;
        }
        else if (this->cell->bottom_left == nextCell)
        {
            this->wayDeltaX = this->fraction->peon.bottom_leftDeltaX;
            this->wayDeltaY = this->fraction->peon.bottom_leftDeltaY;
            startDis = this->gf->degDis;
            this->conor = this->fraction->peon.conorBottom_left;
            this->animX = 5 * this->animGabX;
        }
        else if (this->cell->bottom_right == nextCell)
        {
            this->wayDeltaX = this->fraction->peon.bottom_rightDeltaX;
            this->wayDeltaY = this->fraction->peon.bottom_rightDeltaY;
            startDis = this->gf->degDis;
            this->conor = this->fraction->peon.conorBottom_right;
            this->animX = 3 * this->animGabX;
        }

        startDis -= this->speedTale;
        double preTakts = startDis / this->fraction->peon.speed;
        int preTaktsFloor = floor(preTakts);
        this->speedTale = preTakts - preTaktsFloor;
        this->wayTakts = preTaktsFloor;
}