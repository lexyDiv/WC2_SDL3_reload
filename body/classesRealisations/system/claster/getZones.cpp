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
                         c->ok = true;
                         if (!c->zone)
                         {
                            Zone zone;
                            this->zones.push(zone);
                            cz = this->zones.getItemPtr(this->zones.length - 1);
                            // console.log("push");
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