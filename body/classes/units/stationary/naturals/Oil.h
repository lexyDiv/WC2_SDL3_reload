#include "Shaht.h"
//=> out

class Oil : public Unit
{
public:
   Oil() : Unit() {};
   ~Oil();

   Array<AnimLines *> lines;
   int linesCount = 20;
   int oil = 0;
   float linePusherY = 0.0f;    // oil anim
   float linePullerY = -100.0f; // oil anim

   void create(Cell *cell) override;
   void draw() override;
   // void createUnitMenu() override;
};