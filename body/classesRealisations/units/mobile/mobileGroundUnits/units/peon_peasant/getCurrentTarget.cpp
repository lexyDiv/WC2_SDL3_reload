#include "stendOnCellWait.cpp"
//=>inFightAnimation

void Peon_peasant::getCurrentTarget() {
//       // this->preTargetCell = cell;
//     // this->profession = "";
//     this->potentialWay.clear();
//     this->wayIndex = 0;

//     this->isPotentialWayComplite = false;
//    // this->targetCell = nullptr;
//     //this->targetDataControl = this->unitMenu->targetDataControl;
//    // this->targetData.unit = nullptr;


//    // console.log(to_string(this->deep));

//     if (
//         //cell->groundUnit
//         this->targetData.unit
//     )
//     {

//     //     this->targetData.unit = cell->groundUnit;
//     //    // this->targetData.bornCount = cell->groundUnit->bornCount;

//     //     if (this->fraction->control == "human" &&
//     //     &this->fraction->nation == &targetData.unit->fraction->nation)
//     //     {
//     //         this->profession = this->gold > 0 && this->targetData.unit->name == "greatHall" ? "g" : this->profession;
//     //         this->profession = this->wood > 0 && (this->targetData.unit->name == "greatHall" || this->targetData.unit->name == "mill") ? "w" : this->profession;
//     //     }



//         if (
//            // cell->groundUnit->name == "tree"
//             this->targetData.unit->name == "tree"
//         )
//         {
//            // this->profession = "w";
//             // if (this->wood)
//             // {
//             //     Unit *base = this->getBaseForUnloading();
//             //     if (base)
//             //     {
//             //         this->getCurrentTarget(base->cell);
//             //         return;
//             //     }
//             // }

//             //this->targetDataControl = this->fraction->control == "" ? this->unitMenu->targetDataControlWoodComp : this->unitMenu->targetDataControlWood;
//             this->isOnGetPotentialWayGetTarget = [this](Cell *cell)
//             {
//                 Unit *gu = cell->groundUnit;
//                 if (
//                     gu && gu->name == "tree")
//                 {
//                     this->targetData.unit = gu;
//                    // this->targetData.clicckedCell = gu->cell;
//                    // this->targetData.bornCount = gu->bornCount;
//                     return true;
//                 }
//                 return false;
//             };

//             if (!this->iNeedFreeWay)
//             {
//                 this->isNewCellOnGetWayValide = [this](Cell *cell)
//                 {
//                     Unit *gu = cell->groundUnit;
//                     Cell *tc = this->cell;
//                     if (tc &&
//                         cell->plane == tc->plane &&
//                         (!gu ||
//                          gu->way.length ||
//                          (gu->fraction && gu->fraction->unionCase != this->fraction->unionCase &&
//                           gu->isWarrior) ||
//                          (gu->name == "tree" && !gu->lesorub)))
//                     {
//                         return true;
//                     }
//                     return false;
//                 };
//             }
//             else
//             {
//                 this->isNewCellOnGetWayValide = [this](Cell *cell)
//                 {
//                     Unit *gu = cell->groundUnit;
//                     Cell *tc = this->cell;
//                     if (tc &&
//                         cell->plane == tc->plane &&
//                         (!gu ||
//                          gu->type == "life" ||
//                          gu->name == "tree" && !gu->lesorub))
//                     {
//                         return true;
//                     }
//                     return false;
//                 };
//             }
//         }
//         else
//         {
//             // if (cell->groundUnit->name == "shaht")
//             // {
//             //     this->profession = "g";
//             //     if (this->gold > 0)
//             //     {
//             //         Unit *base = this->getBaseForUnloadingGold();
//             //         if (base)
//             //         {
//             //             this->getHandTarget(base->cell);
//             //             return;
//             //         }
//             //     }
//             // };
//             // if (cell->groundUnit->type != "life")
//             // {
//             //     this->targetDataControl = this->fraction->control == "" ? this->unitMenu->targetDataControlBuildingComp : this->unitMenu->targetDataControlBuilding;
//             // }
//             this->isOnGetPotentialWayGetTarget = [this](Cell *cell)
//             {
//                 Unit *gu = cell->groundUnit;
//                 if ( // cell == this->targetCell ||
//                     gu == this->targetData.unit)
//                 {
//                     return true;
//                 }
//                 return false;
//             };

//             if (!this->iNeedFreeWay)
//             {
//                 this->isNewCellOnGetWayValide = [this](Cell *cell)
//                 {
//                     Unit *gu = cell->groundUnit;
//                     Cell *tc = this->cell;
//                     if (tc &&
//                         cell->plane == tc->plane &&
//                         (!gu ||
//                          gu->way.length ||
//                          gu == this->targetData.unit))
//                     {
//                         return true;
//                     }
//                     return false;
//                 };
//             }
//             else
//             {
//                 this->isNewCellOnGetWayValide = [this](Cell *cell)
//                 {
//                     Unit *gu = cell->groundUnit;
//                     Cell *tc = this->cell;
//                     if (tc &&
//                         cell->plane == tc->plane &&
//                         (!gu ||
//                          gu->type == "life" ||
//                          gu == this->targetData.unit))
//                     {
//                         return true;
//                     }
//                     return false;
//                 };
//             }
//         }
//     }
//     else
//     {
//         // if (this->fraction->control == "human")
//         // {
//         //     this->profession = "";
//         // }
//         this->isOnGetPotentialWayGetTarget = [this](Cell *cell)
//         {
//             if (
//                // cell == this->targetCell
//                cell == this->targetData.clicckedCell
//             )
//             {
//                 return true;
//             }
//             return false;
//         };

//         this->isNewCellOnGetWayValide = [this](Cell *cell)
//         {
//             Unit *gu = cell->groundUnit;
//             Cell *tc = this->cell;
//             if (tc &&
//                 cell->plane == tc->plane &&
//                 (!gu ||
//                  gu->way.length))
//             {
//                 return true;
//             }
//             return false;
//         };
//     }

//     // if (this->cell && this->cell->game->unitsOnWay.indexOf(this) == -1)
//     // {
//     //     this->game->unitsOnWay.push(this);
//     // }
//     if (!this->isActive)
//     {
//         this->isActive = true;
//        // this->fraction->activeUnits.push(this);
//     }
}