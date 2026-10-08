#include "Claster.h"
//=>out

bool isCellValide(Cell *c)
{
  return (c->plane->type != "sea" &&
          (!c->groundUnit ||
           c->groundUnit->type == "life" //||
           // !c->groundUnit->hp
           ));
};

void getAllZoneCells(Cell *cell, ThData *td)
{
  td->createCount += 0.001;
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
              
                 if (azac->groundUnit) 
                     {
                      Td_xploredData *td_exp = azac->groundUnit->thwd.length ? 
                      azac->groundUnit->thwd.getItemPtr(td->num)
                      : nullptr;
                      if (azac->groundUnit->name == "tree") 
                      {
                        z->isTeesNear = true;  
                      } else if (td_exp &&
                                 td_exp->explored != td->createCount) {
                              td_exp->explored = td->createCount;
                              z->buildingsNear.push(azac->groundUnit);
                      }  
                     } });
  }
};

void Claster::getZones()
{

  this->td->createCount += 0.001;

  this->allZones.forEach([](Zone &z)
                         { z.restart(); });
  this->zones.clear();

  Zone *cz = nullptr;
  int iter = 0;
  this->cells.forEach([this, &cz, &iter](Cell *c)
                      {
                        if (!c->zone && isCellValide(c))
                        {
                         // cz = new Zone;
                         for (int i = 0; i < this->allZones.length; i++) {
                          cz = this->allZones.getItemPtr(i);
                          if (!cz->isActive) {
                            cz->isActive = true;
                            cz->num = iter;
                            iter++;
                            break;
                          }
                         }

                          this->zones.push(cz);


                          cz->cells.push(c);
                          c->zone = cz;
                          cz->cl = this;

                          getAllZoneCells(c, td);
                          ///////////////////////////////////////////////////////////// => get cell
                          MinDataC md;
                          md.cell = cz->cells.getItem(0);
                          md.dis = this->td->get_H(md.cell, this->cell);
                          cz->cells.forEach([this, &md](Cell *c, int i)
                                            {
                              int res = this->td->get_H(c, this->cell);
                              if (res < md.dis) {
                                 md.cell = c;
                                 md.dis = res;
              
                              } });
                          cz->cell = md.cell;
                          ///////////////////////////////////////////////////////// <= get cell
                        } });
}