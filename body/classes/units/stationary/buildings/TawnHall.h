#include "in.h"

//=>out


class TownHall : public Unit {
    public:
    TownHall() : Unit(){};
    ~TownHall(){};

    void create(Cell * cell) override;
    void draw() override;
     void wellCome(Unit *peon) override;
     void activeProg() override;
     void getTrees() override;
     void getShahts() override;
     bool isActiveCheck() override;
     MinData getPeonOutCell() override;
     MinData getPeonExtrimeOutCell() override;
};

//void TownHall::draw() {};
void TownHall::wellCome(Unit*) {};
//void TownHall::activeProg(){};
void TownHall::getTrees() {};
void TownHall::getShahts() {};
bool TownHall::isActiveCheck() {return false;};
   MinData TownHall:: getPeonOutCell()
  {
    return {
      index : 0,
      min : 0.0,
      i : 0,
      k : 0,
      cell : nullptr
    };
  };
  MinData TownHall:: getPeonExtrimeOutCell() { return {
    index : 0,
    min : 0.0,
    i : 0,
    k : 0,
    cell : nullptr
  }; };