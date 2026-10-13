#include "savePushOnTrups.cpp"
//=>out

void GameField::activeShahtsControl()
{
    this->game->allShahtsPtr.forEach([](Unit *shaht)
                               { 
                                if (shaht->isActive) {
                                   // console.log("here in field");
                                    shaht->activeProg();
                                } });
}