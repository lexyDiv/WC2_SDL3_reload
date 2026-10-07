#include "addClasterOnUpdate.cpp"
//=>savePushOnTrups

void GameField::updateClasters()
{
    if (this->clastersOnUpdate.length)
    {
       
        this->clastersOnUpdate.forEach([](Claster *cou){
            cou->addOnUpdate = false;
            ///////////////////////////////// => delete around
            cou->zones.forEach([](Zone *couZone){
                couZone->contactZones.forEach([couZone](Zone *z){
                    int zIndex = z->contactZones.indexOf(couZone); // ok
                    // if (zIndex < 0) {
                    //     cout << "sub-zero" << endl;
                    //     console.log("sub-zero");
                    // }
                    z->contactZones.splice(zIndex, 1);
                });
            });

            ///////////////////////////////// <= delete around

            cou->getZones();

            if (!cou->zones.length) {
                console.log("no new zones");
            }

            cou->zones.forEach([](Zone *z){
                z->getAroundZones();
                if (!z->contactZones.length) {
                    console.log("no z->co"); // => impoasble
                }
                z->contactZones.forEach([z](Zone *zcz){
                    zcz->contactZones.push(z);
                });
            });

        });




        this->clastersOnUpdate.clear();
    }
}