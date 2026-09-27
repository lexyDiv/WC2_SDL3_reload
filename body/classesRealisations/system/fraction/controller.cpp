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
        // Array<Unit *> onHard;
        // bool isOne = false;

        for (int i = this->hold; i < this->peons.length; i++)
        {

            this->hold = i;
            Unit *peon = this->peons.getItem(i);
            bool isBlocked = peon->blockedCheck(peon).isBlocked;

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
                peon->orderOnWay.go(peon->profession);
                peon->isActive = true;
            }
            if (current == ordinar)
            {
                break;
            }
        };

        //////////////////////////
        // if (this->peons.length)
        // {
        //     int rand = intRand(0, this->peons.length);
        //     Unit *randUnit = this->peons.getItem(rand);
        //     if (randUnit->blockedCheck(randUnit).isBlocked &&
        //         !randUnit->isActive &&
        //         randUnit->profession != "" && !randUnit->inSave)
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