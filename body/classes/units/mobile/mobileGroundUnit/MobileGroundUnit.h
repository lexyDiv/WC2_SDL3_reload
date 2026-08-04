#include "in.h"
//=>units

class MobileGroundUnit : public Unit {
    public:
    MobileGroundUnit();
    ~MobileGroundUnit();

    void orderOnWayControl() override;
    void goWayAnimation() override;
    void inFightAnimation() override;
    void goWay() override;
    bool isNextCellFreeToGoWay(Cell *nextCell) override;
    bool isNeedHoldGoWay(Cell *nextCell) override;
    bool isGetTarget() override;
    bool isTargetObjValide() override;
    bool isBlockedd(Unit *unit) override;
    void iAmHere() override;
};