#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

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
    this->potentialWay.clear();
    this->isIgetMyTarget = false;
  }


  if (!this->wayTakts &&
      this->wayIndex <= 5 &&
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

  if (this->inFight)
  {
    this->fightControl(); // maybee HUYNYA refactoring needed !!!
    this->flipCell = nullptr;
  }
  else
  {
    this->goWay();
    this->orderOnWayControl();
  }
}