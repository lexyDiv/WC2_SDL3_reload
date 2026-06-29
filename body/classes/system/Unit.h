#include "Th.h"
//=>system/out.h

class Unit
{
public:
     Unit(){};
    ~Unit() {};
    
    Cell *cell = nullptr;

   virtual void create(Cell*){};
};