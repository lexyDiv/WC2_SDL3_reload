#include "Bullet.h"
//=>out

class Trace
{
public:
    virtual void create(int x, int y, double width, double height, Unit *father) {};
    virtual void draw() {};
    virtual void process() {};

    int x = 0;
    int y = 0;
    double width = 0;
    double height = 0;
    int timer = 0;
    Image *image = nullptr;

    int animGabX = 0;
    int animGabY = 0;
    int animStepX = 0;
    int animStepY = 0;
    int animCorrectionX = 0;
    int animCorrectionY = 0;
    int animX = 0;
    int animY = 0;
    int animTakt = 0;
    int drawY = 0;
    int alpha = 255;
    Unit *father = nullptr;
    static Uint64 count;

    bool readyToOut = false;
    bool isAddOnDraw = false;

    Cell *cell = nullptr;

    Game *game = nullptr;

    Array<Cell *> fatherMyCells;
};

Uint64 Trace::count = 0;