#include "footman_grunt.h"
//=> out

class Peon_peasant : public MobileGroundUnit
{
public:
    Peon_peasant(){};
    ~Peon_peasant(){};
     bool isActiveCheck() override;
     void create(Cell *cell) override;
     void draw() override;
    // void getHandTarget(Cell *cell) override;
    // void getCurrentTargetCell() override;
    // // void getCurrentTargetCell2() override;
    // // void getCurrentTargetCell3() override;
    // // void getCurrentTargetCell4() override;
     void activeProg() override;
     void stendOnCell() override;
    // void stendOnCellWait() override;
    // bool isGetTarget() override;
    // bool isTargetObjValide() override;
    // void selectAnAction() override;
    // void fightControl() override;
     void createInside(Cell *c) override;

     Unit *getAnyTree() override;
     Unit *getAnyShaht() override;
    // Unit *getTreeNear() override;
    // Unit *getBaseForUnloading() override;
    // Unit *getBaseForUnloadingGold() override;
     void preDraw() override;
     void updateCurrentTarget() override;
    // void takeDamage(int damage) override;
    // void trupCreate() override;
    // void drawTrup() override;

    
    // void trupCreate() override;

    // void orderOnWayControl() override;
    //  void goWayAnimation() override;
    // void goWay() override;
    // bool isNextCellFreeToGoWay(ProtoObj *nextCell) override;
    //  bool isNeedHoldGoWay(ProtoObj *nextCell) override;
    // bool isOnGetPotentialWayGetTarget(ProtoObj *cell) override;
    // bool isNewCellOnGetWayValide(ProtoObj *cell) override;
};