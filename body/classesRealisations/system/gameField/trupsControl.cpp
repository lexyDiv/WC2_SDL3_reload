#include "miniMapUpdate.cpp"
//=>createClasters

void GameField::trupsControl()
{

   this->trupsOnDelete.filterSelf([this](Unit *u)
                                  {
         if (u->readyToHardDelete)
         {
           // console.log("delete " + u->name);
            delete u;
            u = nullptr;
            this->game->peonsDelete++;
            
            return true;
         }
         else if (u->readyToLightDelete)
         {
            return true;
         }
         else 
         {
            u->trupCreate();
            return false;
         } });

   //  this->trupsOnDelete.forEach([](Unit *u)
   //                              { 
   //                               u->trupCreate();
   //                               if (u->readyToHardDelete) {
   //                                  delete u;
   //                                  u = nullptr;
   //                               } 
   //                             });

   //  this->trupsOnDelete.filterSelf([](Unit *u)
   //                                 {
   //   if (!u || u->readyToLightDelete) {
   //      return true;
   //   }
   //   return false; });
   // //  console.log(to_string(this->trupsOnDelete.length));

   //  this->traces.filterSelf([](Trace *t)
   //                          {
   //      if (t->readyToOut)
   //      {
   //      // console.log("filter = ", t->father->persNum);
   //        return true;
   //      }
   //      else
   //      {
   //        t->process();
   //        return false;
   //      } });

   // tracesOnDelete.forEach([](Trace *t){
   //    delete t;
   //    t = nullptr;
   // });
};