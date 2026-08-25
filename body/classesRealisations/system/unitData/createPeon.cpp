#include "UnitData.cpp"
//=>createTownHall

void UnitData::createPeon(Fraction *fraction)
{
    this->speed = 1.6;

    if (fraction->nation->type == "orcs")
    {
        if (fraction->color == "red")
        {
                 this->img_1 = imager.peonRed;
                 this->img_2 = imager.peonWithWoodRed;
                 this->img_3 = imager.peonWithGoldRed;
        }
    }

    conorLeft = degToRad(180);
    leftDeltaX = cos(conorLeft) * this->speed;
    leftDeltaY = sin(conorLeft) * this->speed;
    conorRight = degToRad(0);
    rightDeltaX = cos(conorRight) * this->speed;
    rightDeltaY = sin(conorRight) * this->speed;
    conorTop = degToRad(270);
    topDeltaX = cos(conorTop) * this->speed;
    topDeltaY = sin(conorTop) * this->speed;
    conorBottom = degToRad(90);
    bottomDeltaX = cos(conorBottom) * this->speed;
    bottomDeltaY = sin(conorBottom) * this->speed;
    conorTop_left = degToRad(225);
    top_leftDeltaX = cos(conorTop_left) * this->speed;
    top_leftDeltaY = sin(conorTop_left) * this->speed;
    conorTop_right = degToRad(315);
    top_rightDeltaX = cos(conorTop_right) * this->speed;
    top_rightDeltaY = sin(conorTop_right) * this->speed;
    conorBottom_left = degToRad(135);
    bottom_leftDeltaX = cos(conorBottom_left) * this->speed;
    bottom_leftDeltaY = sin(conorBottom_left) * this->speed;
    conorBottom_right = degToRad(45);
    bottom_rightDeltaX = cos(conorBottom_right) * this->speed;
    bottom_rightDeltaY = sin(conorBottom_right) * this->speed;
};