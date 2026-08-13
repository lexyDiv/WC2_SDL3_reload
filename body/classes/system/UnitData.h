#include "Imager.h"
//=> Nation

class UnitData
{
public:
    UnitData(string name, Nation *nation);
    UnitData(){};
    ~UnitData() {};
    string name = "";
    Image *img_1 = nullptr;
    Image *img_2 = nullptr;
    Image *img_3 = nullptr;
    double sight = 1;
    double speed = 1;
    double hpMax = 5;

    double conorLeft = 0;          // degToRad(180);
    double leftDeltaX = 0;         // cos(conorLeft) * this->speed;
    double leftDeltaY = 0;         // sin(conorLeft) * this->speed;
    double conorRight = 0;         // degToRad(0);
    double rightDeltaX = 0;        // cos(conorRight) * this->speed;
    double rightDeltaY = 0;        // sin(conorRight) * this->speed;
    double conorTop = 0;           // degToRad(270);
    double topDeltaX = 0;          // cos(conorTop) * this->speed;
    double topDeltaY = 0;          // sin(conorTop) * this->speed;
    double conorBottom = 0;        // degToRad(90);
    double bottomDeltaX = 0;       // cos(conorBottom) * this->speed;
    double bottomDeltaY = 0;       // sin(conorBottom) * this->speed;
    double conorTop_left = 0;      // degToRad(225);
    double top_leftDeltaX = 0;     // cos(conorTop_left) * this->speed;
    double top_leftDeltaY = 0;     // sin(conorTop_left) * this->speed;
    double conorTop_right = 0;     // degToRad(315);
    double top_rightDeltaX = 0;    // cos(conorTop_right) * this->speed;
    double top_rightDeltaY = 0;    // sin(conorTop_right) * this->speed;
    double conorBottom_left = 0;   // degToRad(135);
    double bottom_leftDeltaX = 0;  // cos(conorBottom_left) * this->speed;
    double bottom_leftDeltaY = 0;  // sin(conorBottom_left) * this->speed;
    double conorBottom_right = 0;  // degToRad(45);
    double bottom_rightDeltaX = 0; // cos(conorBottom_right) * this->speed;
    double bottom_rightDeltaY = 0; // sin(conorBottom_right) * this->speed;
};
