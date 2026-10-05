#include "Claster.h"
//=>out

bool isCellValide(Cell *c)
{
   return (c->plane->type != "sea" &&
           (!c->groundUnit ||
            c->groundUnit->type == "life"));
};

void Claster::getZones()
{

   Array<Cell *> validCells;

   this->zones.forEach([](Zone *z){
     if (z) {
            delete z;
      z = nullptr;
     }
   });
   this->zones.clear();

   this->cells.forEach([&validCells, this](Cell *c)
                       {
           if (isCellValide(c)) 
            {
              validCells.push(c);
            } });

   Zone *cz = nullptr;
   validCells.forEach([this, &cz](Cell *c)
                      {
                        // c->ok = true;
                         if (!c->zone)
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
                         }

                         c->aroundCells.forEach([this, cz](Cell *ac)
                                                {
                    
                   if (ac->claster == this &&
                       isCellValide(ac) &&
                       !ac->zone
                      ) 
                      {
                        ac->zone = cz;
                        cz->cells.push(ac);
                      } });
                      });
}