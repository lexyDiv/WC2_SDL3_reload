#include "isBlockedd.cpp"
//=>goWay

void MobileGroundUnit::getConor(Cell *nextCell)
{
    if (this->cell->left == nextCell)
    {
        this->conor = this->fraction->peon.conorLeft;
        this->animX = 6 * this->animGabX;
    }
    else if (this->cell->right == nextCell)
    {
        this->conor = this->fraction->peon.conorRight;
        this->animX = 2 * this->animGabX;
    }
    else if (this->cell->top == nextCell)
    {
        this->conor = this->fraction->peon.conorTop;
        this->animX = 0 * this->animGabX;
    }
    else if (this->cell->bottom == nextCell)
    {
        this->conor = this->fraction->peon.conorBottom;
        this->animX = 4 * this->animGabX;
    }
    else if (this->cell->top_left == nextCell)
    {
        this->conor = this->fraction->peon.conorTop_left;
        this->animX = 7 * this->animGabX;
    }
    else if (this->cell->top_right == nextCell)
    {
        this->conor = this->fraction->peon.conorTop_right;
        this->animX = 1 * this->animGabX;
    }
    else if (this->cell->bottom_left == nextCell)
    {
        this->conor = this->fraction->peon.conorBottom_left;
        this->animX = 5 * this->animGabX;
    }
    else if (this->cell->bottom_right == nextCell)
    {
        this->conor = this->fraction->peon.conorBottom_right;
        this->animX = 3 * this->animGabX;
    }
}