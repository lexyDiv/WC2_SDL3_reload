#include "Claster.h"
//=>out

bool isCellValide(Cell *c)
{
  return (c->plane->type != "sea" &&
          (!c->groundUnit ||
           c->groundUnit->type == "life"));
};


void getAllZoneCells(Cell *cell, ThData *td) {
    Array<Cell *> allZoneCells;
    Zone *z = cell->zone;
    allZoneCells.push(cell);
   // Cell *nextCell = cell;
    
   // while(nextCell) {
      for (int i = 0; i < allZoneCells.length; i++) {
        Cell *az = allZoneCells.getItem(i);
        Td_way_data *thwd_az = az->thwd.getItemPtr(td->num);
        thwd_az->explored = td->createCount;
        az->aroundCells.forEach([td, z, az, &allZoneCells](Cell *azac){
           if (!azac->zone &&
               azac->claster == az->claster &&
               azac->thwd.getItemPtr(td->num)->explored != td->createCount &&
                isCellValide(azac)) {
                azac->zone = z;
                z->cells.push(azac);
                allZoneCells.push(azac);
               }
        });
        // if (thwd_az->explored != td->createCount) {

        // }
      }
     // nextCell = nullptr;
    //}
};


void Claster::getZones()
{

  this->td->createCount += 0.001;
  Array<Cell *> validCells;

  this->zones.forEach([](Zone *z)
                      {
     if (z) {
            delete z;
      z = nullptr;
     } });

  this->zones.clear();



  // this->cells.forEach([&validCells, this](Cell *c)
  //                     {
  //          if (isCellValide(c)) 
  //           {
  //             validCells.push(c);
  //           } });

  Zone *cz = nullptr;
  this->cells.forEach([this, &cz](Cell *c)
                     {
                        // c->ok = true;
                         if (!c->zone && isCellValide(c))
                         {
                           cz = new Zone;
                            this->zones.push(cz);

                            thDatas.forEach([cz](ThData *td){
                              Td_way_data_z thwd;
                              cz->thwd.push(thwd);
                            });
                  
                            cz->cells.push(c);
                            c->zone = cz;
                            cz->cl = this;

                            getAllZoneCells(c, td);
///////////////////////////////////////////////////////////// => get cell
                            MinDataC md;
                            md.cell = cz->cells.getItem(0);
                            md.dis = this->td->get_H(md.cell, this->cell);
                            cz->cells.forEach([this, &md](Cell *c, int i){
                              int res = this->td->get_H(c, this->cell);
                              if (res < md.dis) {
                                 md.cell = c;
                                 md.dis = res;
              
                              }
                            });
                            cz->cell = md.cell;
///////////////////////////////////////////////////////// <= get cell

                         }

                  //        c->aroundCells.forEach([this, cz](Cell *ac)
                  //                               {
                    
                  //  if (ac->claster == this &&
                  //      isCellValide(ac) &&
                  //      !ac->zone
                  //     ) 
                  //     {
                  //       ac->zone = cz;
                  //       cz->cells.push(ac);
                  //     } });


                     });
}