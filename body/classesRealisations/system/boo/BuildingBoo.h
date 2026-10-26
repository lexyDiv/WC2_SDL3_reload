#include "in.h"
//=>out

class BuildingBoo : public Boo {

    public:

    void create (int x, int y, double width, double height, Unit *father) override;
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

    // this->fatherMyCells.forEach([this](Cell *c){
    //     c->boos.push(this);
    // });

    this->game = father->game;


    this->game->allBoos.push(this);

};



void BuildingBoo::process() {

    this->timer ++;

    if (this->timer == 50) {
        this->fatherMyCells.forEach([this](Cell *c){
            c->boos.splice(c->boos.indexOf(this), 1);
        });
        this->readyToOut = true;
    }
};