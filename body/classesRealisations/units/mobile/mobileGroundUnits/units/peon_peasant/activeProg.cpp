#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{

  // if (this->persNum == 302) {
  //   console.log(to_string(!this->wayIndex && !this->wayTakts && this->isBlockedd(this)));
  // }

  if (!this->isActiveCheck() 
  || this->holdTimerControl() 
  //|| (!this->potentialWay.length && this->orderOnWay.isComplite && !this->wayIndex && !this->wayTakts && this->isBlockedd(this))
  )
  {
    return;
  }

  ////////////////////////////////////////////////////////////
 // if (this->rwd.targetCell)
 // {

    // this->targetData.clicckedCell = this->rwd.saveClickedCell;
    // this->targetData.unit = this->rwd.saveUnit;

    // if (this->potentialWay.length && this->potentialWay.getItem(0) == this->rwd.targetCell)
    // {
    //   // console.log("ok");
    //   this->rwd.dopWay.copy(this->potentialWay);
    //   this->rwd.saveWay.splice(this->rwd.index, this->rwd.saveWay.length - this->rwd.index);

    //   this->rwd.dopWay.forEach([this](Cell *c)
    //                            { this->rwd.saveWay.push(c); });

    //   this->way.copy(this->rwd.saveWay);
    //   this->way.push(this->cell);
    //   this->wayIndex = this->way.length - 1;
    //   this->rwd.dopWay.clear();
    //   this->potentialWay.clear();
    // }
    // else
    // {
    //   // console.log("NO");

    //  // this->orderOnWay.go(this->targetData.clicckedCell);
    //  // this->potentialWay.clear();
    //  // this->wayIndex = 0;
    //   this->rwd.clear();
    // }
 // }

  ////////////////////////////////////////////////////////////////////

  

  if (this->isPotentialWayComplite &&
      this->potentialWay.length)
  {
    // this->isNeedFreeWay();

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