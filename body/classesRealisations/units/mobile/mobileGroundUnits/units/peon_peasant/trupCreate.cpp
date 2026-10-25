#include "getBaseForUnloading.cpp"
//=>targetObjControl

void Peon_peasant::trupCreate()
{

   if (!this->isDelete)
   {
      this->isDelete = true;
      this->cell->ripUnits.push(this);
      this->animY = 1000;

      if (this->targetData.unit &&
          this->targetData.unit->lesorub &&
          this->targetData.unit->lesorub == this)
      {
         this->targetData.unit->lesorub = nullptr;
      }
   }

   this->deleteTimer--;
   if (this->deleteTimer % 10 == 0 && this->animY < 1200)
   {
      this->animY += 100;
   }

   if (!this->alpha)
   {
      this->cell->ripUnits.splice(this->cell->ripUnits.indexOf(this), 1);
     // this->game->unitsBufer.push(this);
      this->fraction->nation->addToBuffer(this);
      this->deleteTimer = 0;
   }
   else if (this->deleteTimer < 2970 && this->deleteTimer % 6 == 0)
   {
      this->alpha--;

   }
   else if (this->deleteTimer == 2970)
   {
      this->cell->groundUnit = nullptr;
      this->alpha = 230;
   }
}