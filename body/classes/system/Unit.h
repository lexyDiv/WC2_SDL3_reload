#include "Th.h"
//=>system out

class Unit
{
public:
  Unit() {};
 virtual ~Unit() {};

  Cell *cell = nullptr;

  virtual void create(Cell *) {};
  virtual void getContactCells();
  virtual void draw() {};
  virtual void get2x2myCells(Cell *cell);
  virtual void get3x3myCells(Cell *cell);
  virtual void get4x4myCells(Cell *cell);
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

  virtual void getDeltasXY(Cell *nextCell) {};

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

  virtual void getHandTarget(Cell *cell) {};
  virtual void getCurrentTargetCell() {};
  virtual void stendOnCell() {};
  virtual void stendOnCellWait() {};
  virtual void selectAnAction(){};
  virtual void fightControl(){};
  virtual void createInside(Cell *c) {};
  virtual Unit *getAnyTree(){ return nullptr; };
  virtual Unit *getAnyShaht(){ return nullptr; };
  virtual Unit *getTreeNear(){ return nullptr; };
  virtual Unit *getBaseForUnloading(){ return nullptr; };
  virtual Unit *getBaseForUnloadingGold(){ return nullptr; };
  virtual void preDraw(){};
  virtual void updateCurrentTarget(){};
  virtual void takeDamage(int damage){};
  virtual void trupCreate(){};
  virtual void drawTrup(){};
  virtual void standOnCell() {};

  int deleteTimer = 50;
  Array<Cell *> myCells;
  Array<Cell *> contactCells;
  Array<Cell *> exitCells;
  Array<Unit *> clients;
  Array<Unit *> outClients;
  Array<MinData> wellComeCells;
  Array<Unit *> potentialClients;
  Array<Cell *> potentialWay;
  Array<Cell *> way;

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
  double conor = 0;
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
  Game *game = nullptr;
  Fraction *fraction;
  bool isAddOnDraw = false;
  int alpha = 255;
  int getGabX = 0;
  int getGabY = 0;
  int gold = 0;
  int wood = 0;
  bool inSave = false;
  double animMashtab = 1;
  bool isActive = false;
  int animTimer = 0;
  bool isGetMyCell = true;
  bool inFight = false;
  int createTimer = 0;
  int persNum = 0;
  string profession = "";
  int inOutTimer = 0;
  int inOutCount = 0;
  double inOutMashtabCount = 0;
  double inOutMashtabMin = 0.456000;
  double startAnimMashtab = 0.456000;

  double wayDeltaX = 0;
  double wayDeltaY = 0;
  int outHoldTimer = 0;
  int updateTimer = 0;

   double speedTale = 0;
   int wayTakts = 0;
   int holdWayCount = 0;
   int wayIndex = 0;
   bool isPotentialWayComplite = true;

   Order orderOnWay;
};