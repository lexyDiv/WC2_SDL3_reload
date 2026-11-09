#include "draw.cpp"
//=>takeDamage

void Farm::activeProg()
{
   if (this->isComplite &&
       this->hp == this->hpMax)
   {
      this->isActive = false;
      return;
   }
   this->isActive = true;

   if (!this->isComplite)
   {

      this->checkCompliteState();
      // console.log(this->hp);
      this->checkStateNeed = false;

      return;
   }
}