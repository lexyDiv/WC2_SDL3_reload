#include "getBaseForUnloading.cpp"
//=>targetObjControl

void Peon_peasant::trupCreate() {
       this->deleteTimer--;
   if (this->deleteTimer % 10 == 0 && this->animY < 1200)
   {
      this->animY += 100;
   }

   if (!this->deleteTimer)
   {
      this->cell->ripUnits.splice(this->cell->ripUnits.indexOf(this), 1);
      this->isDelete = true;
     // console.log("deleted");
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