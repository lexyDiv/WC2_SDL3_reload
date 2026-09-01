#include "goWay.cpp"
//=>isNextCellFreeToGoWay

bool MobileGroundUnit::isNeedHoldGoWay(Cell *nc)
{
    
    Unit *gu = nc ? nc->groundUnit : nullptr;
    Cell *guNextCell = gu ? gu->nextCell : nullptr;
    Unit *gutdu = gu ? gu->targetData.unit : nullptr;


    if (gu
       // && this->wayIndex > 10
    && gu->isActive
    && gu->isPotentialWayComplite
    && gu->way.length 
   // && this->wayIndex > 1 
   // && this->way.length > 2 
    //&& gufc 
   // && gufc == this->way.getItem(this->wayIndex - 2)
   && guNextCell
   && guNextCell == this->flipCell
) {
       // console.log("here");
        return true;
    }

    // if (gu && this->wayIndex > 10 
    //     &&  (!gu->isPotentialWayComplite ||
    //     gu->inSave ||
    //      (!gu->potentialWay.length && 
    //       (gu->way.length) &&
    //       (gu->wayIndex) &&
    //       (this->wayIndex > 1 &&
    //        (gufc && gufc == this->way.getItem(this->wayIndex - 2))) 
    //        && gutdu 
    //        && gutdu == this->targetData.unit &&
    //        (gu->gold > 0 || gu->wood) && (this->gold > 0 || this->wood) && (gutdu->name == "shaht" || gutdu->name == "greatHall"))
      
    //     )
    //     )
    // {
    //    // console.log("here");
    //     return true;
    // }

    // bool isCrox = (nextCell == this->cell->top_right &&
    //                ((this->cell->top->groundUnit && this->cell->top->groundUnit->isPotentialWayComplite &&
    //                  !this->cell->top->groundUnit->isGetMyCell && this->cell->top->groundUnit->conor == this->fraction->peon.conorTop_left) ||
    //                 (this->cell->right->groundUnit && this->cell->right->groundUnit->isPotentialWayComplite &&
    //                  !this->cell->right->groundUnit->isGetMyCell &&
    //                  this->cell->right->groundUnit->conor == this->fraction->peon.conorBottom_right))) ||
    //                       // 2
    //                       (nextCell == this->cell->top_left &&
    //                        ((this->cell->top->groundUnit && this->cell->top->groundUnit->isPotentialWayComplite &&
    //                          !this->cell->top->groundUnit->isGetMyCell &&
    //                          this->cell->top->groundUnit->conor == this->fraction->peon.conorTop_right) ||
    //                         (this->cell->left->groundUnit && this->cell->left->groundUnit->isPotentialWayComplite &&
    //                          !this->cell->left->groundUnit->isGetMyCell &&
    //                          this->cell->left->groundUnit->conor == this->fraction->peon.conorBottom_left))) ||
    //                       // 3
    //                       (nextCell == this->cell->bottom_left &&
    //                        ((this->cell->left->groundUnit && this->cell->left->groundUnit->isPotentialWayComplite &&
    //                          !this->cell->left->groundUnit->isGetMyCell &&
    //                          this->cell->left->groundUnit->conor == this->fraction->peon.conorTop_left) ||
    //                         (this->cell->bottom->groundUnit && this->cell->bottom->groundUnit->isPotentialWayComplite &&
    //                          !this->cell->bottom->groundUnit->isGetMyCell &&
    //                          this->cell->bottom->groundUnit->conor == this->fraction->peon.conorBottom_right))) ||

    //                       // 4
    //                       (nextCell == this->cell->bottom_right &&
    //                        ((this->cell->bottom->groundUnit && this->cell->bottom->groundUnit->isPotentialWayComplite &&
    //                          !this->cell->bottom->groundUnit->isGetMyCell &&
    //                          this->cell->bottom->groundUnit->conor == this->fraction->peon.conorBottom_left) ||
    //                         (this->cell->right->groundUnit && this->cell->right->groundUnit->isPotentialWayComplite &&
    //                          !this->cell->right->groundUnit->isGetMyCell &&
    //                          this->cell->right->groundUnit->conor == this->fraction->peon.conorTop_right)))
    //                   ? true
    //                   : false;

    // if (isCrox)
    // {
    //     return true;
    // }

    return false;
};