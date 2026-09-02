#include "orderOnWayControl.cpp"
//=>out

bool MobileGroundUnit::crox()
{

    return (nextCell == this->cell->top_right &&
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
}