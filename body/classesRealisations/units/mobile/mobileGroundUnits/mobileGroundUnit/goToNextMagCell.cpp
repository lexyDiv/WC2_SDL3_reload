#include "selectNextMagCell.cpp"
//=>out

void MobileGroundUnit::goToNextMagCell() {

   if (this->orderOnWay.isComplite) {
    TargetData &td = this->targetData;
    td.saveClickedCell = td.clicckedCell;
    td.saveUnit = td.unit;

    this->game->unitsOnWayMT.lock();
    this->game->unitsOnWay.push(this);
    this->game->unitsOnWayMT.unlock();
    this->way.clear();
    this->wayIndex = 0;
    this->isPotentialWayComplite = false;
    //this->personalCaseDeep = 150;

   //  this->isOnGetPotentialWayGetTarget = [this](Cell *c){
 
   //      if (c == this->targetData.nextMagCell) {
   //         return true;
   //      }
         
   //      return false;
   //  };

   }
}