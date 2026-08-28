#include "holdTimerControl.cpp"
//=>units_out

// void Peon_peasant::getProfessionWoodCase()
// {
//     if (this->wood)
//     {
//         Unit *unloadingBase = this->getBaseForUnloading();
//         if (unloadingBase)
//         {
//             this->targetObj.clear();
//             this->targetObj.clickedCell = unloadingBase->cell;
//             this->targetObj.unit = unloadingBase;
//             this->targetObj.isActive = true;
//         }
//         else
//         {
//             this->targetObj.clear();
//             console.log("getProfession : no base for unloading");
//         }
//     }
//     else
//     {
//         Unit *tree = this->getAnyTree();
//         if (tree)
//         {
//             this->targetObj.clear();
//             this->targetObj.clickedCell = tree->cell;
//             this->targetObj.unit = tree;
//             this->targetObj.isActive = true;
//         }
//         else
//         {
//             this->targetObj.clear();
//             console.log("getProfession : no tree more");
//         }
//     }
// }

// void Peon_peasant::getProfessionGoldCase()
// {
//     if (this->gold)
//     {
//         Unit *unloadingBase = this->getBaseForUnloadingGold();
//         if (unloadingBase)
//         {
//             this->targetObj.clear();
//             this->targetObj.clickedCell = unloadingBase->cell;
//             this->targetObj.unit = unloadingBase;
//             this->targetObj.isActive = true;
//         }
//         else
//         {
//             this->profession = "";
//             this->targetObj.clear();
//             console.log("getProfession : no base for unloading gold");
//         }
//     }
//     else
//     {
//         Unit *shaht = this->getAnyShaht();
//         if (shaht)
//         {
//             this->targetObj.clear();
//             this->targetObj.clickedCell = shaht->cell;
//             this->targetObj.unit = shaht;
//             this->targetObj.isActive = true;
//         }
//         else
//         {
//             this->profession = "";
//             this->targetObj.clear();
//             console.log("getProfession : no tree more");
//         }
//     }
// }

// void Peon_peasant::getProfession()
// {
//     string &prof = this->orderOnWay.profession;
//     if (prof == "w")
//     {
//         if (this->profession != "w")
//         {
//             this->profession = prof;
//             this->getProfessionWoodCase();
//         }
//     }
//     else if (this->orderOnWay.profession == "g")
//     {
//         if (this->profession != "g")
//         {
//             this->profession = prof;
//             this->getProfessionGoldCase();
//         }
//     }
//     else
//     {
//         Unit *tou = this->targetObj.unit;
//         if (tou)
//         {
//             if (tou->name == "tree")
//             {
//                 this->profession = "w";
//             }
//             else if (tou->name == "shaht")
//             {
//                 this->profession = "g";
//             }
//             else if (tou->name == "greatHall")
//             {
//                 if (this->wood)
//                 {
//                     this->profession = "w";
//                 }
//                 else if (this->gold)
//                 {
//                     this->profession = "g";
//                 }
//                 else
//                 {
//                     this->profession = "";
//                 }
//             }
//         }
//     }
// }