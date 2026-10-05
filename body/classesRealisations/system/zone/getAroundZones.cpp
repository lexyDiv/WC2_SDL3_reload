#include "in.h"
//=>out

void Zone::getAroundZones() {
    
   // console.log("here");
    this->contactZones.clear();

    ThData *td = this->cl->td;
    td->createCount += 0.001;

    Zone *currentZone = nullptr;



    this->cells.forEach([&currentZone, this, td](Cell *c){

      c->aroundCells.forEach([c, &currentZone, this, td](Cell *ac){
        Td_way_data *thwd_ac = ac->thwd.getItemPtr(td->num);
        Td_way_data_z * thwd_ac_z = ac->zone ? ac->zone->thwd.getItemPtr(td->num) : nullptr;
        if (
            thwd_ac_z &&
             ac->zone != c->zone &&
             thwd_ac->explored != td->createCount &&
             thwd_ac_z->explored != td->createCount &&
             (!currentZone || currentZone != ac->zone)
           ) 
            {
              thwd_ac->explored = td->createCount;
              thwd_ac_z->explored = td->createCount;
              currentZone = ac->zone;
              this->contactZones.push(ac->zone);
            }
      });

    });


  // console.log("zone.contarctZones.length = ", this->contactZones.length);
}
