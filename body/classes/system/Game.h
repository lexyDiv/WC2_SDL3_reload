#include "Fraction.h"
//=>GameField

class ProtoGame
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

  ProtoGame();
  virtual ~ProtoGame();
  virtual void create();
  virtual void draw();
  virtual void preDraw();
  virtual void fonMenuDraw();
  virtual void fractionsControl();
  virtual void process(Uint64 *startTick, int *optimalDeltaTime) {};

  vector<string> pathes{
      "levels/test_1.txt",
      "levels/testBig_1.txt",
      "levels/testBig_500.txt"};

  GameField *gf = nullptr;
  ObjMenu *objMenu = nullptr;
  bool isGFComplite = false;
  Array<Fraction *> fractions;
  Array<ProtoObj *> unitsOnWay;

  Array<ProtoObj *> AllUnits;
  Array<ProtoObj *> allPeons;
  Array<ProtoObj *> allPeons2;
  int scanIndex = 0;
};