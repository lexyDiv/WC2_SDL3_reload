#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

  if (!this->isActiveCheck() || this->holdTimerControl()

  )
  {
    return;
  }


    if (!this->personalCaseDeep && this->iNeedFreeWay && !this->wayIndex == 1 && this->frashWayCheckNeed)
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

    }


  if (!this->wayTakts &&
      (this->wayIndex <= 5 || this->iNeedFreeWay) &&
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