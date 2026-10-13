#include "savePushOnTrups.cpp"
//=>addToTrupsOnDelete

void GameField::activeShahtsControl()
{
    this->game->allShahtsPtr.forEach([](Unit *shaht)
                               { 
                                if (shaht->isActive) {
                                   // console.log("here in field");
                                    shaht->activeProg();
                                } });
}