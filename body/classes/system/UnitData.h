#include "Unit.h"

class UnitData {
   public:
   UnitData(string name);
   ~UnitData(){};
   string name = "";
    Image *img_1 = nullptr;
    Image *img_2 = nullptr;
    Image *img_3 = nullptr;
    float sight = 1.0f;
    float speed = 1.0f;
    float hpMax = 50.0f;
};

