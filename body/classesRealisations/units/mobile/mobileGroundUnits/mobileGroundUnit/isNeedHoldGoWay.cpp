#include "goWay.cpp"
//=>isNextCellFreeToGoWay

// bool isLoop(Unit *self)
// {

// Unit *unit1 = self;
// Unit *unit2 = unit1->nextCell && unit1->nextCell->groundUnit ? unit1->nextCell->groundUnit : nullptr;
// Unit *unit3 = unit2 && unit2->nextCell && unit2->nextCell->groundUnit ? unit2->nextCell->groundUnit : nullptr;
// Unit *unit4 = unit3 && unit3->nextCell && unit3->nextCell->groundUnit ? unit3->nextCell->groundUnit : nullptr;
// Unit *unit5 = unit4 && unit4->nextCell && unit4->nextCell->groundUnit ? unit4->nextCell->groundUnit : nullptr;

// if (unit3 != self && unit4 != self && unit5 != self) {
//     return false;
// }
// return true;
// //     Unit *currentUnit = unit;
// // int iter = 0;
// //     while(!currentUnit || iter >= 5) {
// //         iter ++;
// //                    if(self->persNum == 1000) {
// //     console.log(to_string(iter));
// //    }
// //         Unit *cng = currentUnit->cell 
// //         && currentUnit->wayIndex 
// //         && currentUnit->isActive 
// //         && currentUnit->hp 
// //         && currentUnit->nextCell
// //         && currentUnit->name == "peon"
// //         && currentUnit->targetData.unit ? currentUnit->nextCell->groundUnit : nullptr;

// //        if (cng != self) {
// //             currentUnit = cng;
// //         } else {
// //             return true;
// //         }
// //     }
// // return false;
//     // Unit *currentUnit = unit;
//     // while (!currentUnit)
//     // {
//     //     Unit *cng = currentUnit->cell && currentUnit->wayIndex && currentUnit->isActive && currentUnit->hp && currentUnit->nextCell ? currentUnit->nextCell->groundUnit : nullptr;
//     //     Unit *cngTdU = cng && cng->targetData.unit ? cng->targetData.unit : nullptr;
//     //     if (cng
//     //     && cng->)
//     //     {
//     //         currentUnit = currentUnit->nextCell->groundUnit;
//     //     }
//     //     if (!currentUnit->cell ||)
//     // }
//     // return false;
// };

bool MobileGroundUnit::isNeedHoldGoWay()
{

//     Unit *gu = nc ? nc->groundUnit : nullptr;
//     Cell *guNextCell = gu ? gu->nextCell : nullptr;
//     Unit *gutdu = gu ? gu->targetData.unit : nullptr;

//      if (this->needHolTimer >= this->needHoldTimerMax) {
//         this->needHolTimer = 0;
//         return false;
//      }

//     if (
//         gu
//         // && this->wayIndex > 10
//        // && gu->isActive && gu->isPotentialWayComplite && gu->way.length
//         // && this->wayIndex > 1
//         // && this->way.length > 2
//         //&& gufc
//         // && gufc == this->way.getItem(this->wayIndex - 2)
//        // && guNextCell && guNextCell == this->flipCell
//          && !isLoop(this)
//                           // || (gutdu && gutdu == this->targetData.unit)
//                           )
//     {
//         // console.log("here");
// //            if(this->persNum == 1000) {
// //     console.log("hi, i zero");
// //    }
//         return true;
//     }

//     // if (gu && this->wayIndex > 10
//     //     &&  (!gu->isPotentialWayComplite ||
//     //     gu->inSave ||
//     //      (!gu->potentialWay.length &&
//     //       (gu->way.length) &&
//     //       (gu->wayIndex) &&
//     //       (this->wayIndex > 1 &&
//     //        (guNextCell && guNextCell == this->way.getItem(this->wayIndex - 2)))
//     //        && gutdu
//     //        && gutdu == this->targetData.unit &&
//     //        (gu->gold > 0 || gu->wood) && (this->gold > 0 || this->wood) && (gutdu->name == "shaht" || gutdu->name == "greatHall"))

//     //     )
//     //     )
//     // {
//     //    // console.log("here");
//     //     return true;
//     // } // => is classic

//     bool isCrox = (nextCell == this->cell->top_right &&
//                    ((this->cell->top->groundUnit && this->cell->top->groundUnit->isPotentialWayComplite &&
//                      !this->cell->top->groundUnit->isGetMyCell && this->cell->top->groundUnit->conor == this->fraction->peon.conorTop_left) ||
//                     (this->cell->right->groundUnit && this->cell->right->groundUnit->isPotentialWayComplite &&
//                      !this->cell->right->groundUnit->isGetMyCell &&
//                      this->cell->right->groundUnit->conor == this->fraction->peon.conorBottom_right))) ||
//                           // 2
//                           (nextCell == this->cell->top_left &&
//                            ((this->cell->top->groundUnit && this->cell->top->groundUnit->isPotentialWayComplite &&
//                              !this->cell->top->groundUnit->isGetMyCell &&
//                              this->cell->top->groundUnit->conor == this->fraction->peon.conorTop_right) ||
//                             (this->cell->left->groundUnit && this->cell->left->groundUnit->isPotentialWayComplite &&
//                              !this->cell->left->groundUnit->isGetMyCell &&
//                              this->cell->left->groundUnit->conor == this->fraction->peon.conorBottom_left))) ||
//                           // 3
//                           (nextCell == this->cell->bottom_left &&
//                            ((this->cell->left->groundUnit && this->cell->left->groundUnit->isPotentialWayComplite &&
//                              !this->cell->left->groundUnit->isGetMyCell &&
//                              this->cell->left->groundUnit->conor == this->fraction->peon.conorTop_left) ||
//                             (this->cell->bottom->groundUnit && this->cell->bottom->groundUnit->isPotentialWayComplite &&
//                              !this->cell->bottom->groundUnit->isGetMyCell &&
//                              this->cell->bottom->groundUnit->conor == this->fraction->peon.conorBottom_right))) ||

//                           // 4
//                           (nextCell == this->cell->bottom_right &&
//                            ((this->cell->bottom->groundUnit && this->cell->bottom->groundUnit->isPotentialWayComplite &&
//                              !this->cell->bottom->groundUnit->isGetMyCell &&
//                              this->cell->bottom->groundUnit->conor == this->fraction->peon.conorBottom_left) ||
//                             (this->cell->right->groundUnit && this->cell->right->groundUnit->isPotentialWayComplite &&
//                              !this->cell->right->groundUnit->isGetMyCell &&
//                              this->cell->right->groundUnit->conor == this->fraction->peon.conorTop_right)))
//                       ? true
//                       : false;

//     if (isCrox)
//     {
//         return true;
//     }

    return false;
};