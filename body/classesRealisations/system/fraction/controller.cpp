#include "create.cpp"
//=>out


void Fraction::controller()
{
    
    int ordinar = 100;
    this->controlTimer++;
    if (this->controlTimer == 1)
    {
        this->controlTimer = 0;

        int current = 0;

        for (int i = this->hold; i < this->peons.length; i++)
        {
           
            
            this->hold = i;
            Unit *peon = this->peons.getItem(i);


            if (peon->hp &&
                !peon->inSave &&
                !peon->isActive &&
                peon->profession != "" &&
                peon->orderOnWay.isComplite &&
                !peon->isBlockedd_full(peon)
               )
            {
               // console.log("here");
   

                current++;
                peon->orderOnWay.go(peon->profession);
                peon->isActive = true;

            }
            if (current == ordinar)
            {
                break;
            }
        };
        if (this->hold >= this->peons.length - 1)
        {
            // console.log("obnul");
            this->peons.filterSelf([](Unit *peon)
                                   {
            if (peon) {
                return false;
            }
            return true; });
            this->hold = 0;
        }
    }


  //  this->activeUnitsControl();

       this->allBuildings.forEach([](Unit *building){
            if (building->isActive) {
                building->activeProg();
            }
        });


};