#include "create.cpp"
//=>out

void Fraction::controller()
{

//    this->hardCount++;
//    if (this->hardCount == 30) {
//     this->hardCount = 0;
//    }

    int ordinar = 100;
    this->controlTimer++;
    if (this->controlTimer == 1)
    {
        this->controlTimer = 0;

        int current = 0;
        // Array<Unit *> onHard;
        // bool isOne = false;
Array<Unit *> onHard;
        for (int i = this->hold; i < this->peons.length; i++)
        {

            this->hold = i;
            Unit *peon = this->peons.getItem(i);
            bool isBlocked = peon->blockedCheck(peon).isBlocked;
            

            // if (peon->profession != "" && !this->hardCount) {
            //     onHard.push(peon);
            // }

            if (peon->hp &&
                !peon->inSave &&
                !peon->isActive &&
                peon->profession != "" &&
                peon->orderOnWay.isComplite &&
                !isBlocked //! peon->isBlockedd_full(peon)
            )
            {
                // console.log("here");

                current++;
                peon->orderOnWay.go(peon->profession, 0, true);
                peon->isActive = true;
            }
            if (current == ordinar)
            {
                break;
            }
        };

        //////////////////////////
        // if (onHard.length)
        // {
        //     int rand = intRand(0, onHard.length);
        //     Unit *randUnit = onHard.getItem(rand);
        //     BlockedData bd = randUnit->blockedCheck(randUnit);
        //     if (bd.isBlocked && bd.type == 'f' &&
        //         !randUnit->isActive &&
        //         randUnit->profession != "" &&
        //          !randUnit->inSave)
        //     {
        //         randUnit->orderOnWay.go(randUnit->profession);
        //         randUnit->isActive = true;
        //        // console.log("hard go");
        //     }
        // }
        ////////////////////////////////////////

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

    this->allBuildings.forEach([](Unit *building)
                               {
            if (building->isActive) {
                building->activeProg();
            } });
            
};