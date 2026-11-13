#include "in.h"

//=>farm

class TownHall : public Unit
{
public:
    TownHall() : Unit() {};
    ~TownHall() {};

    bool create(Cell *cell, bool isComplite, bool isNew) override;
    void draw() override;
    void wellCome(Unit *peon) override;
    void activeProg() override;
    void getTrees() override;
    void getShahts() override;
    bool isActiveCheck() override;
    MinData getPeonOutCell() override;
    MinData getPeonExtrimeOutCell() override;
    void takeDamage(int damage) override;
    void trupCreate() override;
    void drawTrup() override;

    void checkCompliteState();
    void upgrade();
    bool get4x4myCells(Cell *cell) override;

    

  
    
   // mutex mt;

    ///////////////////////// => debug
    
    ///////////////////////// <= debug
};

// void TownHall::draw() {};
// void TownHall::wellCome(Unit*) {};
// void TownHall::activeProg(){};
// void TownHall::getTrees() {};
// void TownHall::getShahts() {};
