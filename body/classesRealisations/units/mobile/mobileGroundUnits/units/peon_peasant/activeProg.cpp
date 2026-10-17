#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

  // if (this->focus) {
  //   console.log("hp = ", this->hp);
  // }

//console.log("need finish = ", this->targetData.isNeedMagistralFinish);

//  if(this->focus) {
//   console.log("--------------Active------------");
//  }


  if (!this->isActiveCheck() || this->holdTimerControl()

  )
  {
    // if (this->focus) {
    //   console.log("active return");
    // }
    return;
  }

  //this->gf->focusClaster = this->cell->claster;

  // if (this->focus) {
  //   console.log("timer = " + to_string(this->needHolTimer));
  // }

    
  


  if (this->frashWayCheckNeed && this->orderOnWay.isComplite)
  {
    this->frashWayCheckNeed = false;
    if (this->profession != "")
    {
       if(this->focus) {
 // console.log("1");
 }
      this->orderOnWay.go(this->profession);
    }
    else if (this->targetData.clicckedCell)
    {
       if(this->focus) {
 // console.log("2");
 }
      this->orderOnWay.go(this->targetData.clicckedCell);
    }
    else if (this->targetData.unit && this->targetData.unit->cell)
    {
     // console.log("3");
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
     //  (
      (this->wayIndex <= 15) &&
      this->isPotentialWayComplite &&
     // this->orderOnWay.isComplite &&
      this->way.length &&
      !this->needHolTimer &&
      !this->inFight &&
      !this->isIgetMyTarget
      // ) //|| 
      // targetUnit
    )
  {

    Unit *to = this->targetData.unit;

    if (to)
    {

//  if(this->focus) {
//   console.log("4");
//  }

      bool isTOValide = this->isTargetObjValide();
      
      if (!isTOValide)
      {
//          if(this->focus) {
//   console.log("5");
//  }
        this->stendOnCell();
        this->updateCurrentTarget();
       // console.log("here 4");
      }
    }
    this->isGetTarget();

//      if(this->focus) {
//   console.log("6");
//  }
    if (this->isIgetMyTarget)
    {
      this->stendOnCell();
      this->isIgetMyTarget = false;
      this->selectAnAction();
      //console.log("here 5");
//        if(this->focus) {
//   console.log("7");
//  }
    }
  }

  if (this->inFight)
  {
   // console.log("here 6");
//     if(this->focus) {
//   console.log("8");
//  }
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