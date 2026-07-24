#include "Shaht.h"
//=> out


class Oil : public Unit {
     public:
     Oil() : Unit(){};
     ~Oil();

    void create(Cell * cell) override;
    void draw() override;
   // void createUnitMenu() override;
};