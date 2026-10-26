#include "in.h"
//=>out

class BuildingBoo : public Boo {

    public:

    void create (int x, int y, double width, double height) override;

};

void BuildingBoo::create(int x, int y, double width, double height) 
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->image = nullptr;
};