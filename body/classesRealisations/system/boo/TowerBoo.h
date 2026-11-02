#include "BuildingBoo.h"
//=>out

class TowerBoo : public Unit
{
public:
    void create(int x, int y, double width, double height, Unit *father, Cell *c) override;
    void trupCreate() override;
    void draw() override;

    double width = 0;
    double height = 0;
    int timer = 0;
    Array<Cell *> fatherMyCells;
};

void TowerBoo::create(int x, int y, double width, double height, Unit *father, Cell *c = nullptr)
{

    // console.log("create");

    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    this->cell = c;
    this->game = c->game;
    this->image = imager.tower_boo;

    this->animGabX = 1024 / 6;
    this->animGabY = 1024 / 6;
    this->animX = 0;
    this->animY = 0;
    this->drawIndexY = this->y + height;

    // this->game->gf->addToTrupsOnDelete(this); // ?????????
    this->game->gf->trupsOnDelete.push(this);
};

void TowerBoo::trupCreate()
{

    if (!this->isDelete)
    {
        this->isDelete = true;
        this->cell->groundUnitOnDraw.push(this);
        // this->fatherMyCells.forEach([this](Cell *c)
        //                             { c->groundUnitOnDraw.push(this); });
    }


  

    if (this->timer % 1 == 0)
    {

        this->animX += this->animGabX;
        if (this->animX >= 1000)
        {
            this->animX = 0;
            this->animY += this->animGabX;
        }

        if (this->animY >= 1000)
        {
            this->cell->groundUnitOnDraw.splice(this->cell->groundUnitOnDraw.indexOf(this), 1);
            // this->fatherMyCells.forEach([this](Cell *c)
            //                             { c->groundUnitOnDraw.splice(c->groundUnitOnDraw.indexOf(this), 1); });

            this->readyToHardDelete = true;
        }
    }

    this->timer++;
};

void TowerBoo::draw()
{

    this->isAddOnDraw = false;

    float drawDeltaX = this->game->gf->drawDeltaX;
    float drawDeltaY = this->game->gf->drawDeltaY;

    ctx.DrawImage(this->image,
                  this->animX,
                  this->animY,
                  animGabX, animGabY,
                  this->x + drawDeltaX + this->animCorrectionX,
                  this->y + drawDeltaY + this->animCorrectionY,
                  this->width,
                  this->height);

     ctx.FillRect(this->x + drawDeltaX, this->drawIndexY + drawDeltaY, 5, 5, "red");
};