#include "orderOnWayControl.cpp"
//=>out

bool isLoop(Unit *self)
{

Unit *unit1 = self;
Unit *unit2 = unit1->nextCell && unit1->nextCell->groundUnit ? unit1->nextCell->groundUnit : nullptr;
Unit *unit3 = unit2 && unit2->nextCell && unit2->nextCell->groundUnit ? unit2->nextCell->groundUnit : nullptr;
Unit *unit4 = unit3 && unit3->nextCell && unit3->nextCell->groundUnit ? unit3->nextCell->groundUnit : nullptr;
Unit *unit5 = unit4 && unit4->nextCell && unit4->nextCell->groundUnit ? unit4->nextCell->groundUnit : nullptr;

if (unit3 != self && unit4 != self && unit5 != self) {
    return false;
}
return true;
};



bool Peon_peasant::isNeedHoldGoWay()
{
   Cell *nc = this->nextCell; 

    Unit *gu = nc ? nc->groundUnit : nullptr;
    Cell *guNextCell = gu ? gu->nextCell : nullptr;
    Unit *gutdu = gu ? gu->targetData.unit : nullptr;

    if (this->needHolTimer >= this->needHoldTimerMax)
    {
        this->needHolTimer = 0;
        return false;
    }

    if (
        gu
        && !isLoop(this)
    )
    {
        return true;
    }


    bool isCrox = (nextCell == this->cell->top_right &&
                   ((this->cell->top->groundUnit && this->cell->top->groundUnit->isPotentialWayComplite &&
                     !this->cell->top->groundUnit->isGetMyCell && this->cell->top->groundUnit->conor == this->fraction->peon.conorTop_left) ||
                    (this->cell->right->groundUnit && this->cell->right->groundUnit->isPotentialWayComplite &&
                     !this->cell->right->groundUnit->isGetMyCell &&
                     this->cell->right->groundUnit->conor == this->fraction->peon.conorBottom_right))) ||
                          // 2
                          (nextCell == this->cell->top_left &&
                           ((this->cell->top->groundUnit && this->cell->top->groundUnit->isPotentialWayComplite &&
                             !this->cell->top->groundUnit->isGetMyCell &&
                             this->cell->top->groundUnit->conor == this->fraction->peon.conorTop_right) ||
                            (this->cell->left->groundUnit && this->cell->left->groundUnit->isPotentialWayComplite &&
                             !this->cell->left->groundUnit->isGetMyCell &&
                             this->cell->left->groundUnit->conor == this->fraction->peon.conorBottom_left))) ||
                          // 3
                          (nextCell == this->cell->bottom_left &&
                           ((this->cell->left->groundUnit && this->cell->left->groundUnit->isPotentialWayComplite &&
                             !this->cell->left->groundUnit->isGetMyCell &&
                             this->cell->left->groundUnit->conor == this->fraction->peon.conorTop_left) ||
                            (this->cell->bottom->groundUnit && this->cell->bottom->groundUnit->isPotentialWayComplite &&
                             !this->cell->bottom->groundUnit->isGetMyCell &&
                             this->cell->bottom->groundUnit->conor == this->fraction->peon.conorBottom_right))) ||

                          // 4
                          (nextCell == this->cell->bottom_right &&
                           ((this->cell->bottom->groundUnit && this->cell->bottom->groundUnit->isPotentialWayComplite &&
                             !this->cell->bottom->groundUnit->isGetMyCell &&
                             this->cell->bottom->groundUnit->conor == this->fraction->peon.conorBottom_left) ||
                            (this->cell->right->groundUnit && this->cell->right->groundUnit->isPotentialWayComplite &&
                             !this->cell->right->groundUnit->isGetMyCell &&
                             this->cell->right->groundUnit->conor == this->fraction->peon.conorTop_right)))
                      ? true
                      : false;

    if (isCrox)
    {
        return true;
    }

    return false;
}