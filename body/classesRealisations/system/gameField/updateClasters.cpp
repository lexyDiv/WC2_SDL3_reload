#include "addClasterOnUpdate.cpp"
//=>savePushOnTrups

void GameField::updateClasters()
{
    if (this->clastersOnUpdate.length)
    {
       
        this->clastersOnUpdate.forEach([](Claster *cou){
            //cou->isUpdated = true;
           // cou->addOnUpdate = false;
            ///////////////////////////////// => delete around
            cou->zones.forEach([](Zone *couZone){
                couZone->contactZones.forEach([couZone](Zone *z){
                    int zIndex = z->contactZones.indexOf(couZone); // ok
                    z->contactZones.splice(zIndex, 1);
                });
            });

            ///////////////////////////////// <= delete around

            cou->getZones();


            cou->zones.forEach([](Zone *z){
                z->getAroundZones();
                z->contactZones.forEach([z](Zone *zcz){
                    zcz->contactZones.push(z);
                   // zcz->cl->isTouchUpdated = true;
                });
            });

            cou->addOnUpdate = false;

        });




        this->clastersOnUpdate.clear();
    }
}