#include "miniMapUpdate.cpp"
//=>out

void GameField::trupsControl()
{
    this->trupsOnDelete.forEach([](Unit *trup)
                                { trup->trupCreate(); });
    this->trupsOnDelete.filterSelf([](Unit *trup)
                                   {
     if (!trup->deleteTimer) {
        return true;
     }
     return false; });
   //  console.log(to_string(this->trupsOnDelete.length));
};