#include "in.h"
//=>BuildingTrace

class PeonTrace : public Trace
{
public:
    void create(int x, int y, double width, double height, Unit *father) override;
    void process() override;
    void draw() override;
};

void PeonTrace::create(int x, int y, double width, double height, Unit *father)
{
    this->x = father->x;
    this->y = father->y;
    this->width = width;
    this->height = height;
    this->cell = father->cell;
    this->father = father;
    this->image = father->image;
    this->game = this->father->game;
    this->animGabX = father->animGabX;
    this->animGabY = father->animGabY;
    this->bufferIndex = father->bufferIndex;
    this->animX = father->animX;
    this->animY = father->animY;
    this->count++;
    this->persnum = this->count;
    this->timer = 0;
    this->alpha = father->alpha;
}

void PeonTrace::draw()
{
   // console.log("draw = ", this->father->persNum);
    this->isAddOnDraw = false;
    float drawDeltaX = this->game->gf->drawDeltaX;
    float drawDeltaY = this->game->gf->drawDeltaY;

    ctx.DrawImage(this->image,
                  this->animX, this->animY,
                  this->animGabX, this->animGabY,
                  this->x + drawDeltaX - 25,
                  this->y + drawDeltaY - 25,
                  100, 100, SDL_FLIP_NONE, 0, this->alpha);
}

void PeonTrace::process()
{
   if (father->cell) {
        if (!this->father->isDelete)
    {
        this->father->isDelete = true;
        this->cell->traces.push(this);
        this->animY = 1000;

        if (this->father->targetData.unit &&
            this->father->targetData.unit->lesorub &&
            this->father->targetData.unit->lesorub == this->father)
        {
            this->father->targetData.unit->lesorub = nullptr;
        }
    }

    this->timer ++;
    if (this->timer % 10 == 0 && this->animY < 1200)
    {
        this->animY += 100;
    }

    if (!this->alpha)
    {
        this->cell->traces.splice(this->cell->traces.indexOf(this), 1);
        this->father->fraction->nation->addToAllTracesBuffers(this);
        this->readyToOut = true;
       // console.log("trace delete");
    }
    else if (this->timer > 30 && this->timer % 6 == 0)
    {
        this->alpha--;
    }
    else if (this->timer == 30)
    {
        this->father->fraction->nation->addToBuffer(this->father);
        this->father->cell->groundUnit = nullptr;
        this->alpha = 230;
    }
   }
   else 
   {
    cout << "no father cell" << endl;
   }
}
