#include "in.h"
//=> out

Plane::~Plane()
{
      this->contactPlanes.forEach([](ToOtherPlane *op){
        delete op;
        op = nullptr;
      });
}