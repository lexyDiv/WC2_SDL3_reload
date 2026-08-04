#include "Th.h"
//=>system out

class Unit
{
public:
  Unit() {};
  ~Unit() {};

  Cell *cell = nullptr;

  virtual void create(Cell *) {};
  virtual void getContactCells();
  virtual void draw() {};
  virtual void get2x2myCells(Cell *cell);
  virtual void get3x3myCells(Cell *cell);
  virtual void getContactAndExitCells(Cell *cell, Cell *exitCell, Cell *centerCell);
  virtual void getWellComeCells();

  virtual void orderOnWayControl() {};
  virtual void goWayAnimation() {};
  virtual void inFightAnimation() {};
  virtual void goWay() {};
  virtual bool isNextCellFreeToGoWay(Cell *nextCell) { return false; };
  virtual bool isNeedHoldGoWay(Cell *nextCell) { return false; };
  virtual bool isGetTarget() { return false; };
  virtual bool isTargetObjValide() { return false; };
  virtual bool isBlockedd(Unit *unit) { return false; };
  virtual void iAmHere() {};

  virtual void wellCome(Unit *peon) {};
  virtual void activeProg() {};
  virtual void getTrees() {};
  virtual void getShahts() {};
  virtual bool isActiveCheck() { return false; };
  virtual MinData getPeonOutCell()
  {
    return {
      index : 0,
      min : 0.0,
      i : 0,
      k : 0,
      cell : nullptr
    };
  };
  virtual MinData getPeonExtrimeOutCell() { return {
    index : 0,
    min : 0.0,
    i : 0,
    k : 0,
    cell : nullptr
  }; };

  int deleteTimer = 50;
  Array<Cell *> myCells;
  Array<Cell *> contactCells;
  Array<Cell *> exitCells;
  Array<Unit *> clients;
  Array<MinData> wellComeCells;

  string name = "tree";
  string type = "building";
  Color mapColor = {R : 0, G : 150, B : 0};
  double drawGabaritX = 0;
  double drawGabaritY = 0;
  int randX = intRand(0, 15);
  int randXVec = intRand(0, 2);
  int randY = intRand(0, 15);
  int randYVec = intRand(0, 2);
  double x = randXVec = 0;
  double y = randYVec = 0;
  double saveX = 0;
  double drawIndexY = 0;
  int hp = 50;
  int hpMax = 0;
  bool isComplite = false;
  int animGabX = 0;
  int animGabY = 0;
  int animStepX = 0;
  int animStepY = 0;
  Image *image = nullptr;
  Image *image2 = nullptr;
  int animX = 0;
  int animY = 0;
  int animTakt = 0;
  GameField *gf = nullptr;
  bool isAddOnDraw = false;
  int alpha = 255;
  int getGabX = 0;
  int getGabY = 0;
  int gold = 0;
};