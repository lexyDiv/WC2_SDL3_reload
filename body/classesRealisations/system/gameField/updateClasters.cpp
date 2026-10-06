#include "addClasterOnUpdate.cpp"
//=>out

void GameField::updateClasters()
{
    if (this->clastersOnUpdate.length)
    {
       // console.log("tipa update");
        this->clastersOnUpdate.forEach([](Claster *cl)
                                       {
                                           cl->getZones();
                                        //    cl->aroundClasters.forEach([](Claster *acl)
                                        //                               {
                                        //                                   if (!acl->addOnUpdate)
                                        //                                   {
                                        //                                       acl->getZones();
                                        //                                   }
                                        //                               });
                                       });

        this->clastersOnUpdate.forEach([](Claster *cl)
                                       { 
                                    cl->zones.forEach([](Zone *z)
                                                       { z->getAroundZones(); });
                                                       
                                    cl->aroundClasters.forEach([](Claster *acl){
                                               acl->zones.forEach([](Zone *z)
                                                       { z->getAroundZones(); });
                                                      
                                    }); 
                                cl->addOnUpdate = false; });

        this->clastersOnUpdate.clear();
    }
}