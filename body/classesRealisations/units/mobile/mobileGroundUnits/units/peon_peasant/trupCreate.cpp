#include "getBaseForUnloading.cpp"
//=>targetObjControl

void Peon_peasant::trupCreate() {

    if (!this->isDelete) {
      this->isDelete = true;
      this->cell->ripUnits.push(this);
    }

       this->deleteTimer--;
   if (this->deleteTimer % 10 == 0 && this->animY < 1200)
   {
      this->animY += 100;
   }

   if (!this->deleteTimer)
   {
      this->cell->ripUnits.splice(this->cell->ripUnits.indexOf(this), 1);
      this->game->unitsBufer.push(this);
   }
   else if (this->deleteTimer < 2950)
   {
      this->alpha -= 0.084;
   }
   else if (this->deleteTimer == 2950)
   {
      this->cell->groundUnit = nullptr;
     // console.log("no cell");
   }
}