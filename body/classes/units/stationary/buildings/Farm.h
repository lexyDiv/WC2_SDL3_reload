#include "TawnHall.h"
//=>out


class Farm : public Unit {
    public:
    bool create(Cell *c, bool isComplite = false, bool isNew = false) override;
    void draw() override;
};