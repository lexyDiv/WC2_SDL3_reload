#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

  //   if (this->focus) {
  //    // console.log(to_string(this->isPotentialWayComplite));
  //   }

 
  if (!this->isActiveCheck())
  {
    return;
  }

  this->holdTimerControl();
  if(this->outHoldTimer) {
    return;
  }


  if (this->isPotentialWayComplite &&
      this->potentialWay.length)
  {
    this->way.copy(this->potentialWay);
    // this->targetObjControl(); // !!! impotent IMPOTENT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    this->potentialWay.clear();
    this->isIgetMyTarget = false;
  }


  if (!this->wayTakts &&
      this->wayIndex <= 5 &&
      this->isPotentialWayComplite &&
      this->orderOnWay.isComplite &&
      this->way.length && // ???????? way.length ????? !!!!!!
      !this->holdWayCount &&
      !this->inFight)
  {
    if (!this->isIgetMyTarget)
    {
      Unit *to = this->targetObj.unit;
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
        this->targetCell = nullptr;
        this->preTargetCell = nullptr;
        this->stendOnCell();
        this->isIgetMyTarget = false;
        this->selectAnAction();
      }
    }
    // else
    // {
    // }
  }

  if (this->inFight)
  {
    this->fightControl(); // maybee HUYNYA refactoring needed !!!
  }
  else
  {
    this->goWay();
    this->orderOnWayControl();
  }
}