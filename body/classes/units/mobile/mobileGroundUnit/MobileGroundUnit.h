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
    void getDeltasXY(Cell *nextCell) override;
    void getConor(Cell *cell) override;
};

MobileGroundUnit::MobileGroundUnit(){};
MobileGroundUnit::~MobileGroundUnit(){};
void MobileGroundUnit::orderOnWayControl(){};
//void MobileGroundUnit::goWayAnimation(){};
void MobileGroundUnit::inFightAnimation(){};
void MobileGroundUnit::goWay(){};
bool MobileGroundUnit::isNextCellFreeToGoWay(Cell *nextCell) { return false; };
bool MobileGroundUnit::isNeedHoldGoWay(Cell *nextCell) { return false; };
bool MobileGroundUnit::isGetTarget() { return false; };
bool MobileGroundUnit::isTargetObjValide() { return false; };

//bool MobileGroundUnit::isBlockedd(Unit *unit) { return false; };
//void MobileGroundUnit::iAmHere(){};

