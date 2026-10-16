#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

  // if (this->focus) {
  //   console.log("hp = ", this->hp);
  // }

  // console.log("need finish = ", this->targetData.isNeedMagistralFinish);

  if (this->focus)
  {
    console.log("--------------Active------------");
    
  }

  if (!this->isActiveCheck() || this->holdTimerControl()

  )
  {
    if (this->focus)
    {
      console.log("active return");
    }
    return;
  }

  // this->gf->focusClaster = this->cell->claster;

  // if (this->focus) {
  //   console.log("timer = " + to_string(this->needHolTimer));
  // }

  if (this->frashWayCheckNeed && this->orderOnWay.isComplite)
  {
    this->frashWayCheckNeed = false;
    if (this->profession != "")
    {
      this->orderOnWay.go(this->profession);
    }
    else if (this->targetData.clicckedCell)
    {
      this->orderOnWay.go(this->targetData.clicckedCell);
    }
    else if (this->targetData.unit && this->targetData.unit->cell)
    {
      this->orderOnWay.go(this->targetData.unit->cell);
    }
  }

  ///////////////////////////////////// => fastOrder

  Unit *target = this->updateTargetData();

  if (this->focus)
  {
    if (target)
    {
      console.log("td name " + target->name);
    }
  }

  ////////////////////////////////////  <= fastOrder

  if (
      !this->wayTakts &&
      !this->fightTarget &&
      (target ||
       ((this->wayIndex <= 15) &&
        this->way.length &&
        !this->needHolTimer &&
        !this->isIgetMyTarget)))
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
    this->isIgetMyTarget = this->isGetTarget();

    if (this->isIgetMyTarget)
    {
      if (this->focus)
      {
        if (target)
        {
          console.log("i get target : " + target->name);
        }
      }
      this->stendOnCell();
      this->isIgetMyTarget = false;
      this->selectAnAction();
      this->orderOnWay.isComplite = true;
     // console.log("order obnul");
    }
  }

  if (this->fightTarget)
  {
    if (this->focus) {
       console.log("have fightTarget");
    }
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