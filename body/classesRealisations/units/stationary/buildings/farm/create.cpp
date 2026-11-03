#include "in.h"
//=>draw


bool Farm::create(Cell *c, bool isComplite = false, bool isNew = false) {

   this->myCells.forEach([this](Cell *c){
    c->groundUnit = this;
   });

    this->cell = c;
    this->canGiveMeal = true;
    this->image = this->fraction->farm.construction; //this->fraction->farm.img_1;
  //  console.log(this->fraction->farm.construction);
   // this->image2 = this->fraction->farm.construction;
    this->getGabX = cell->gabX * 2;
    this->getGabY = this->getGabX;
    this->gf = c->gf;
    this->isComplite = false;


    this->animGabX = 128;
    this->animGabY = 128;
    this->animStepX = 128;
    this->animStepY = 128;
    this->animCorrectionX = 60;
    this->animCorrectionY = 120;
    this->drawGabaritX = 220;
    this->drawGabaritY = 290;
    this->deleteTimer = 0;
    this->maxDeleteTimer = 3000;

    this->fraction->allUnits.push(this);


    return true;
}