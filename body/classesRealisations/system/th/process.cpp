#include "in.h"
//=>createMyActiveProgZone

void ThData::process()
{

   // while (!this->game->quit)
   // {

        // if (this->num == this->thds->length - 1 && !this->game->isGFComplite)
        // {
        //     this->game->create();
        //     this->game->gf->field.forEach([this](Array<Cell *> cells){
        //         cells.forEach([this](Cell *cell){
        //              for (int i = 0; i < this->thds->length; i++) {
        //                 Td_way_data twd;
        //                 cell->thwd.push(twd);
        //              }
        //         });
        //     });
        // }
this->isBasicActiveProgComplite = false;
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