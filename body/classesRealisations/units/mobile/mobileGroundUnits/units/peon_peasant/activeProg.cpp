#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

  if (!this->isActiveCheck() || this->holdTimerControl()

  )
  {
    return;
  }



  if (this->frashWayCheckNeed)
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