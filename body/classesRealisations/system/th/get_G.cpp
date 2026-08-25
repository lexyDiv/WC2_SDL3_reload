#include "isBlocked.cpp"
//=>get_H

int ThData::get_G(Cell *fatherCell, Cell *potentialCell)
{
    Cell *pc = potentialCell;
    return fatherCell->top == pc ||
                   fatherCell->left == pc ||
                   fatherCell->right == pc ||
                   fatherCell->bottom == pc
               ? 10
               : 14;
}