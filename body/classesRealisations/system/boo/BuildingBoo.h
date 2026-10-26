#include "in.h"
//=>out

class BuildingBoo : public Boo
{

public:
    void create(int x, int y, double width, double height, Unit *father) override;
    void process() override;
    void draw() override;
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
    this->drawY = this->y + this->height;

    this->game->allBoos.push(this);
};

void BuildingBoo::process()
{

    if (this->timer % 2 == 0)
    {
        this->animX += 100;
        if (this->animX == 800)
        {
            this->animCorrectionX += 4;
            this->animCorrectionY -= 4;

            this->animX = 0;
            this->animY += 100;
        }

        if (this->animY == 600)
        {
            this->fatherMyCells.forEach([this](Cell *c)
                                        { c->boos.splice(c->boos.indexOf(this), 1); });
            this->readyToOut = true;
           // console.log("boo delete");
        }
    }

    this->timer++;
};

void BuildingBoo::draw()
{

    this->isAddOnDraw = false;

    float drawDeltaX = this->game->gf->drawDeltaX;
    float drawDeltaY = this->game->gf->drawDeltaY;

    ctx.DrawImage(this->image, 
        this->animX, 
        this->animY, 
        100, 98, 
        this->x + drawDeltaX + this->animCorrectionX, 
        this->y + drawDeltaY + this->animCorrectionY, 
        this->width, 
        this->height );
};