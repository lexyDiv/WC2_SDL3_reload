#include "in.h"
//=>out

class BuildingBoo : public Boo
{

public:
    void create(int x, int y, double width, double height, Unit *father) override;
    void process() override;
};

void BuildingBoo::create(int x, int y, double width, double height, Unit *father)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->image = nullptr;

    this->fatherMyCells.copy(father->myCells);
    this->game = father->game;

    this->image = imager.buildingBoo_image;

    this->animGabX = 100;
    this->animGabY = 100;

    this->game->allBoos.push(this);
};

void BuildingBoo::process()
{

    if (this->timer)
    {
        this->animX += 100;
        if (this->animX == 800)
        {
            this->animX = 0;
            this->animY += 100;
        }

        if (this->animY == 600)
        {
            this->fatherMyCells.forEach([this](Cell *c)
                                        { c->boos.splice(c->boos.indexOf(this), 1); });
            this->readyToOut = true;
            console.log("boo delete");
        }
    }

    this->timer++;
};