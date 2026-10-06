#include "Claster.h"
//=>out

bool isCellValide(Cell *c)
{
  return (c->plane->type != "sea" &&
          (!c->groundUnit ||
           c->groundUnit->type == "life"));
};

void getAllZoneCells(Cell *cell, ThData *td)
{
  Zone *z = cell->zone;
  for (int i = 0; i < z->cells.length; i++)
  {
    Cell *az = z->cells.getItem(i);
    Td_way_data *thwd_az = az->thwd.getItemPtr(td->num);
    thwd_az->explored = td->createCount;
    az->aroundCells.forEach([td, z, az](Cell *azac)
                            {
           if (!azac->zone &&
               azac->claster == az->claster &&
               azac->thwd.getItemPtr(td->num)->explored != td->createCount &&
                isCellValide(azac)) {
                azac->zone = z;
                z->cells.push(azac);
               }
              
                 if (azac->groundUnit && 
                     azac->groundUnit->name == "tree") 
                     {
                          z->isTeesNear = true;      
                     }
              });
  }
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

  Zone *cz = nullptr;
  this->cells.forEach([this, &cz](Cell *c)
                      {
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

                        });
}