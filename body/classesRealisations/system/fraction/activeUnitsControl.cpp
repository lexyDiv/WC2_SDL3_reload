#include "Fraction.cpp"
//=>create

void Fraction::activeUnitsControl() {
            this->AllLifeUnits.forEach([](Unit *unit){
            if (unit->isActive) {
                unit->activeProg();
            }
        });
}