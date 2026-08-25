#include "Fraction.h"
//=>GameField

class Game
{
public:
  virtual void getPotentialWayControl(){};
  // virtual void getPotentialWayControl2() {};
  // virtual void getPotentialWayControl3() {};
  // virtual void getPotentialWayControl4() {};

  ////////////////////////////////////////////  => cases
  virtual void unitsActiveZone(int index, bool isFinal) {};

  

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

      bool quit = false;

      Uint64 finishTick = SDL_GetTicks();
      Uint64 startTick = SDL_GetTicks();
      int optimalDeltaTime = 1000 / 30;

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
   Array<Unit *> allOilsPtr;

   Array<Unit *> allLifeUnitsPtr;
  
  ///////////////////////////////////////////////////
  Array<Cell> allCells;

  int scanIndex = 0;
  bool thSpin = true;
  bool needReturn = false;
};

Game gameData;

Game *game = &gameData;