#include "Zone.h"
//=>Bullet

class Boo
{

public:
    Boo() {};
    virtual void create(int x, int y, double width, double height) {};

    int x = 0;
    int y = 0;
    double width = 0;
    double height = 0;
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

    bool readyToOut = false;
};