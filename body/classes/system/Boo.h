#include "Zone.h"
//=>Bullet

class Boo : public Unit
{

public:
    Boo() {};
    virtual void create(int x, int y, double width, double height, Unit *father) {};
    virtual void trupCreate() {};

    // int x = 0;
    // int y = 0;
     double width = 0;
     double height = 0;
     int timer = 0;
    // Image *image = nullptr;

    // int animGabX = 0;
    // int animGabY = 0;
    // int animStepX = 0;
    // int animStepY = 0;
    // int animCorrectionX = 0;
    // int animCorrectionY = 0;
    // int animX = 0;
    // int animY = 0;
    // int animTakt = 0;
    // int drawY = 0;

    // bool readyToOut = false;
    // bool isAddOnDraw = false;

    Game *game = nullptr;

    Array<Cell *> fatherMyCells;
};