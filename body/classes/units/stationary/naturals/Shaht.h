#include "Mount.h"
//=>out

class Shaht : public Unit
{
public:
    Shaht() : Unit() {};
    ~Shaht();

  

    void create(Cell *cell) override;
    void draw() override;
  //  void createUnitMenu() override;
   // bool isBlockedd(Unit *unit) override;
   // void wellCome(Unit *peon) override;
   // void activeProg() override;
   // bool isIValideOnWay(Unit *unit) override;
   // bool isActiveCheck() override;
   // MinData getPeonOutCell() override;
};
