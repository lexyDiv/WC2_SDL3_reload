#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

  // if (this->focus) {
  //   console.log("hp = ", this->hp);
  // }

//console.log("need finish = ", this->targetData.isNeedMagistralFinish);


  if (!this->isActiveCheck() || this->holdTimerControl()

  )
  {
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
     // console.log("here");
      this->orderOnWay.go(this->profession);
    }
    else if (this->targetData.clicckedCell)
    {
     // console.log("here 2");
      this->orderOnWay.go(this->targetData.clicckedCell);
    }
    else if (this->targetData.unit && this->targetData.unit->cell)
    {
     // console.log("here 3");
      this->orderOnWay.go(this->targetData.unit->cell);
    }
  }

  if (!this->wayTakts &&
      (this->wayIndex <= 15) &&
      this->isPotentialWayComplite &&
      this->orderOnWay.isComplite &&
      this->way.length &&
      !this->needHolTimer &&
      !this->inFight &&
      !this->isIgetMyTarget)
  {

    Unit *to = this->targetData.unit;

    if (to)
    {

      bool isTOValide = this->isTargetObjValide();
      
      if (!isTOValide)
      {
        this->stendOnCell();
        this->updateCurrentTarget();
       // console.log("here 4");
      }
    }
    this->isGetTarget();

    if (this->isIgetMyTarget)
    {
      this->stendOnCell();
      this->isIgetMyTarget = false;
      this->selectAnAction();
      //console.log("here 5");
    }
  }

  if (this->inFight)
  {
   // console.log("here 6");
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