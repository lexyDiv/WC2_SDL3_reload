#include "miniMapUpdate.cpp"
//=>createClasters

void GameField::trupsControl()
{
   //  this->trupsOnDelete.forEach([](Unit *trup)
   //                              { trup->trupCreate(); });
   //  this->trupsOnDelete.filterSelf([](Unit *trup)
   //                                 {
   //   if (trup->deleteTimer >= trup->maxDeleteTimer) {
   //      return true;
   //   }
   //   return false; });
   // //  console.log(to_string(this->trupsOnDelete.length));

   this->traces.filterSelf([](Trace &t)
                           {
       if (t.readyToOut)
       {
         return true;
       }
       else
       {
         t.process();
         return false;
       } });

   // tracesOnDelete.forEach([](Trace *t){
   //    delete t;
   //    t = nullptr;
   // });
};