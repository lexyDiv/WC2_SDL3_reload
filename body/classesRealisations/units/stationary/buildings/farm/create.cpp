#include "in.h"
//=>draw


bool Farm::create(Cell *c, bool isComplite = false, bool isNew = false) {





    bool ok = this->get2x2myCells(c);

   if (!ok)
   {
    return false;
   }

   this->cell = c;
   this->canGiveMeal = true;


    return true;
}