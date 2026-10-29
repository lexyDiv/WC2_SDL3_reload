#include "in.h"
//=>out

class BuildingBoo : public Unit
{

public:
    void create(int x, int y, double width, double height, Unit *father) override;
    void trupCreate() override;
    void draw() override;

         double width = 0;
     double height = 0;
     int timer = 0;
     Array<Cell *> fatherMyCells;
};

void BuildingBoo::create(int x, int y, double width, double height, Unit *father)
{

    console.log("create");

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
    this->drawIndexY = this->y + this->height;


    


   // this->game->allBoos.push(this);
};

void BuildingBoo::trupCreate()
{

    if (!this->isDelete)
    {
        this->isDelete = true;
        this->fatherMyCells.forEach([this](Cell *c){
            c->groundUnitOnDraw.push(this);
        });
       // this->drawIndexY = this->
    }

    if (this->timer % 2 == 0)
    {
        this->animX += 100;
        if (this->animX == 800)
        {
            this->animCorrectionX += 3;
            this->animCorrectionY -= 4;

            this->animX = 0;
            this->animY += 100;
        }

        if (this->animY == 600)
        {
            this->fatherMyCells.forEach([this](Cell *c)
                                        { c->groundUnitOnDraw.splice(c->groundUnitOnDraw.indexOf(this), 1); });
        
            this->readyToHardDelete = true;
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