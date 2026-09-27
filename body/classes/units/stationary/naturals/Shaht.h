#include "Mount.h"
//=>Oil.h

class Shaht : public Unit
{
public:
    Shaht(){};
    ~Shaht(){};

  

    void create(Cell *cell) override;
    void draw() override;
  //  void createUnitMenu() override;
   // bool isBlockedd(Unit *unit) override;
   // void wellCome(Unit *peon) override;
   // void activeProg() override;
   // bool isIValideOnWay(Unit *unit) override;
   // bool isActiveCheck() override;
   // MinData getPeonOutCell() override;


  Array<Unit *> clients;
  Array<Unit *> outClients;
  Array<Unit *> potentialClients;
};
