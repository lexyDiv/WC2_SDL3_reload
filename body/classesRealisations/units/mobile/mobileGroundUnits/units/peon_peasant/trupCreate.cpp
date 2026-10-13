#include "getBaseForUnloading.cpp"
//=>targetObjControl

void Peon_peasant::trupCreate() {

    if (!this->isDelete) {
      this->isDelete = true;
      this->cell->ripUnits.push(this);
      this->animY = 1000;
      console.log("add to cell");
    }

       this->deleteTimer--;
   if (this->deleteTimer % 10 == 0 && this->animY < 1200)
   {
      this->animY += 100;
   }

   if (!this->alpha)
   {
      this->cell->ripUnits.splice(this->cell->ripUnits.indexOf(this), 1);
      this->game->unitsBufer.push(this);

      this->deleteTimer = 0;
      console.log("add to bufer");
   }
   else if (this->deleteTimer < 2950 && this->deleteTimer % 6 == 0)
   {
      this->alpha --;
      console.log("alpha --");
   }
   else if (this->deleteTimer == 2950)
   {
      this->cell->groundUnit = nullptr;
      
   }
}