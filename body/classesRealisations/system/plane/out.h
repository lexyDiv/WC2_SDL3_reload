#include "Plane.cpp"
//=>th

Plane::~Plane()
{
    this->contactPlanes.forEach([](ToOtherPlane *plane){
        plane->otherPlane = nullptr;
        plane->cellsToOther.clear();
        delete plane;
        plane = nullptr;
    });
}