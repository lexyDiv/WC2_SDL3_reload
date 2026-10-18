#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

  int num = 204;

  // if (this->persNum == num) {
  //   console.log("hp = ", this->hp);
  // }

  // console.log("need finish = ", this->targetData.isNeedMagistralFinish);

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

  // this->gf->focusClaster = this->cell->claster;

  // if (this->persNum == num) {
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

  this->basicActionCheck();

  if (this->fightTarget)
  {
    this->fightControl(); 
    this->flipCell = nullptr;
  }
  else
  {
    this->blockedData = this->blockedCheck(this);

    this->goWay();

    this->orderOnWayControl();
  }
}