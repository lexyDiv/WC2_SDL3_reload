#include "TawnHall.h"
//=>out


class Farm : public Unit {
    public:
        Farm() : Unit() {};
    ~Farm() {};
        bool create(Cell *cell, bool isComplite, bool isNew) override;
    void draw() override;
   // bool create(Cell *c, bool isComplite = false, bool isNew = false) override;
   // void draw() override;
};