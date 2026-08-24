#include "in.h"
//=>createMyActiveProgZone

void ThData::process()
{

   // while (!this->game->quit)
   // {

        if (!this->num && !this->game->isGFComplite)
        {
            this->game->create();
        }

        if (this->game->isGFComplite)
        {
            this->dopUnits.clear();
            this->game->fractions.forEach([this](Fraction *fr)
                                          { fr->AllLifeUnits.forEach([this](Unit *unit)
                                                                     {
                        if (unit->isActive
                            && unit->thSpin != this->game->thSpin
                            && unit->cell
                            && unit->hp > 0
                            ) {
                                int ver = unit->cell->ver;
                           if (ver >= this->startIndex
                               && ver <= this->finishIndex) {
                              if (unit->isActive) {
                                unit->thSpin = this->game->thSpin;
                                 unit->activeProg();
                              }
                           } else if (ver >= this->dopStartIndex
                                      && ver <= this->dopFinishIndex) {
                                  this->dopUnits.push(unit);
                           }
                        } }); });


            this->isBasicActiveProgComplite = true;


            while (!this->isAllThreadsBasicComplite())
            {

            };

            this->dopUnits.forEach([this](Unit *unit)
                                   {
                               if (unit->thSpin != this->game->thSpin) {
                                        if (unit->isActive) {
                                unit->thSpin = this->game->thSpin;
                                 unit->activeProg();
                              }
                               } });
    
            this->isDopActiveProgComplite = true;
      
        }

       // this_thread::sleep_for(chrono::nanoseconds(1));
    }
//}