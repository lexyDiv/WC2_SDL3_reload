#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{


   int num = 204;

  // if (this->persNum == num) {
  //   console.log("hp = ", this->hp);
  // }

//console.log("need finish = ", this->targetData.isNeedMagistralFinish);

//  if(this->persNum == num) {
//   console.log("--------------Active------------  = " + this->profession);
//  }


  if (!this->isActiveCheck() || this->holdTimerControl()

  )
  {
    // if (this->persNum == num) {
    //   console.log("active return");
    // }
    return;
  }

  //this->gf->focusClaster = this->cell->claster;

  // if (this->persNum == num) {
  //   console.log("timer = " + to_string(this->needHolTimer));
  // }

    
  


  if (this->frashWayCheckNeed && this->orderOnWay.isComplite)
  {
    this->frashWayCheckNeed = false;
    if (this->profession != "")
    {
//        if(this->persNum == num) {
//   console.log("1");
//  }
      this->orderOnWay.go(this->profession);
    }
    else if (this->targetData.clicckedCell)
    {
//        if(this->persNum == num) {
//   console.log("2");
//  }
      this->orderOnWay.go(this->targetData.clicckedCell);
    }
    else if (this->targetData.unit && this->targetData.unit->cell)
    {
    //       if (this->persNum == num) {
    //   console.log("3");
    // }
      this->orderOnWay.go(this->targetData.unit->cell);
    }
  }

///////////////////////////////////// => fastOrder

// Unit *targetUnit = nullptr;
// if (!this->orderOnWay.isComplite) {
//   Cell *oc = this->orderOnWay.cell;
//   if (oc) {
//     Unit *ocgu = oc->groundUnit;
//      if (oc == this->cell) {
//       this->orderOnWay.isComplite = true;
//      }
//      else if (ocgu) {
//         this->cell->aroundCells.forEach([ocgu, &targetUnit, this](Cell *ac){
//              Unit *acgu = ac->groundUnit;
//              if (acgu == ocgu) {
//               targetUnit = acgu;
//               targetData.clicckedCell = acgu->cell;
//               this->orderOnWay.isComplite = true;
//               this->targetData.unit = acgu;
//              }
//         });
//      }
//   }
// }

////////////////////////////////////  <= fastOrder
  

  if (
       !this->wayTakts && 
      (this->wayIndex <= 15) &&
      this->isPotentialWayComplite &&
      this->way.length &&
      !this->needHolTimer &&
      !this->fightTarget &&
      !this->isIgetMyTarget
    )
  {

    Unit *to = this->targetData.unit;

    if (to)
    {

      bool isTOValide = this->isTargetObjValide();
      
      if (!isTOValide)
      {

        this->stendOnCell();
        this->updateCurrentTarget();
      }
    }
    this->isGetTarget();


    if (this->isIgetMyTarget)
    {
      this->stendOnCell();
      this->isIgetMyTarget = false;
      this->selectAnAction();
    }
  }

  if (this->fightTarget)
  {
    this->fightControl(); // maybee HUYNYA refactoring needed !!!
    this->flipCell = nullptr;
  }
  else
  {
     this->blockedData = this->blockedCheck(this);
   

      this->goWay();
 

    this->orderOnWayControl();

  }
}