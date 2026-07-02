#include "Fraction.h"
//=>GameField

class Game
{
public:
  virtual void getPotentialWayControl(){};
  virtual void getPotentialWayControl2() {};
  virtual void getPotentialWayControl3() {};
  virtual void getPotentialWayControl4() {};

  ////////////////////////////////////////////  => cases
  virtual void unitsActiveZone(int index, bool isFinal) {};

  bool isUnitsActiveComplite = false;
  bool isUnitsActiveComplite2 = false;
  bool isUnitsActiveComplite3 = false;
  bool isUnitsActiveComplite4 = false;
  bool isUnitsActiveComplite5 = false;
  bool isUnitsActiveComplite6 = false;
  bool isUnitsActiveComplite7 = false;

  //////////////////////////////////////////////////////////  <= cases

  Game(){};
   ~Game();
   void create();
   void draw();
   void preDraw();
   void fonMenuDraw();
   void fractionsControl();
   void process(Uint64 *startTick, int *optimalDeltaTime);
      void process();

  vector<string> pathes{
      "levels/test_1.txt",
      "levels/testBig_1.txt",
      "levels/testBig_500.txt"};
  GameField *gf = nullptr;
  ObjMenu *objMenu = nullptr;
  bool isGFComplite = false;
  Array<Fraction *> fractions;
  Array<Unit *> unitsOnWay;

   Array<Unit *> AllUnitsPtr;
   Array<Unit *> allPeonsPtr;
   Array<Unit *> allTreesPtr;
   Array<Unit *> allMountsPtr;
   Array<Unit *> allShahtsPtr;
  
  ///////////////////////////////////////////////////
  Array<Cell> allCells;

  int scanIndex = 0;
};

Game gameData;

Game *game = &gameData;