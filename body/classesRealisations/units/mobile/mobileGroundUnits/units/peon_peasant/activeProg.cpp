#include "stendOnCell.cpp"
//=>isActiveCheck

void Peon_peasant::activeProg()
{
//   if (this->focus) {
//    // console.log(to_string(this->isPotentialWayComplite));
//   }

  this->isActive = this->isActiveCheck();
  if (!this->isActive) {
    return;
  }

//   if (this->isPotentialWayComplite &&
//       this->pw.length)
//   {
//     this->potentialWay.copy(this->pw);
//     this->targetObjControl(this);
//     this->pw.clear();
//   }

//   if (this->isAnimyCheckNeeded)
//   {
//     this->isAnimyCheckNeeded = false;
//     this->iAmHere();
//   }

//   if (this->outHoldTimer)
//   {
//     this->outHoldTimer--;
//     if (!this->outHoldTimer && this->orderOnWay->isComplite)
//     {
//       this->iAmHere();
//       this->updateCurrentTarget();
//     }
//     else if (this->orderOnWay->isComplite)
//     {
//       this->isActiveCheck();
//       return;
//     }
//   }

//   ///////////////////////////////////////////////////////////////
//   if (!this->wayTakts &&
//       this->wayIndex <= 5 &&
//       this->isPotentialWayComplite &&
//       this->orderOnWay->isComplite &&
//       this->potentialWay.length &&
//       !this->holdWayCount &&
//       !this->inFight)
//   {
//     if (!this->isIgetMyTarget)
//     {
//       ProtoObj *to = this->targetObj.unit;
//       if (to)
//       {
//         bool isTOValide = this->isTargetObjValide();
//         if (!isTOValide)
//         {
//           this->stendOnCell();
//           this->updateCurrentTarget();
    
//         }
//       }

//       this->isGetTarget();
//       if (this->isIgetMyTarget)
//       {
//         this->targetCell = nullptr;
//         this->preTargetCell = nullptr;
//         this->stendOnCell();
//         this->isIgetMyTarget = false;
//         this->selectAnAction();
//       }
//     }
//     else
//     {
//     }
//   }

//   if (this->inFight)
//   {
//     this->fightControl();
//   }
//   else
//   {
//     this->goWay();
//     this->orderOnWayControl();
//   }
  
}