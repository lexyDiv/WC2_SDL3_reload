#include "TawnHall.h"
//=>out

class Farm : public Unit
{
public:
    Farm() : Unit() {};
    ~Farm() {};
    bool create(Cell *cell, bool isComplite, bool isNew) override;
    void draw() override;
    void activeProg() override;
    void takeDamage(int damage) override;
    void checkCompliteState();
};