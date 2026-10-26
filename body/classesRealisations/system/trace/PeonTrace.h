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
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->cell = father->cell;
    this->father = father;
    this->image = father->image;
}

void PeonTrace::process()
{
    // if (!this->father->isDelete)
    // {
    //     this->father->isDelete = true;
    //     this->cell->ripUnits.push(this);
    //     this->animY = 1000;

    //     if (this->targetData.unit &&
    //         this->targetData.unit->lesorub &&
    //         this->targetData.unit->lesorub == this)
    //     {
    //         this->targetData.unit->lesorub = nullptr;
    //     }
    // }

    // this->deleteTimer++;
    // if (this->deleteTimer % 10 == 0 && this->animY < 1200)
    // {
    //     this->animY += 100;
    // }

    // if (!this->alpha)
    // {
    //     this->cell->ripUnits.splice(this->cell->ripUnits.indexOf(this), 1);
    //     this->fraction->nation->addToBuffer(this);
    //     this->deleteTimer = this->maxDeleteTimer;
    // }
    // else if (this->deleteTimer > 30 && this->deleteTimer % 6 == 0)
    // {
    //     this->alpha--;
    // }
    // else if (this->deleteTimer == 30)
    // {
    //     this->cell->groundUnit = nullptr;
    //     this->alpha = 230;
    // }
}

void PeonTrace::draw()
{
}