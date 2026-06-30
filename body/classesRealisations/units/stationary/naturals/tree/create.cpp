#include "Tree.cpp"
//=>getContactCells

void Tree::create(Cell *cell)
{
    this->deleteTimer = 50;
    cell->groundUnit = this;
    this->myCells.push(cell);
    this->cell = cell;
    this->getContactCells();
    this->name = "tree";
    this->type = "building";
    this->mapColor = {R : 0, G : 150, B : 0};
    int randGY = intRand(0, 50);
    this->drawGabaritX = 40 + randGY;
    this->drawGabaritY = 50 + randGY;
    int randX = intRand(0, 15);
    int randXVec = intRand(0, 2);
    int randY = intRand(0, 15);
    int randYVec = intRand(0, 2);
    this->x = randXVec ? cell->centerX + randX : cell->centerX - randX;
    this->y = randYVec ? cell->centerY + randY : cell->centerY - randY;
    this->saveX = this->x;
    this->drawIndexY = this->y;
    this->hp = 50;
    this->animGabX = 200;
    this->animGabY = 200;
    this->animStepX = 200;
    this->animStepY = 200;
    int randImg = intRand(0, 2);
    this->image = randImg ? imager.tree1 : imager.tree2;
    this->image2 = randImg ? imager.tree1Trup : imager.tree2Trup;
    this->animX = 200 * intRand(0, 4);
    this->animY = 200 * intRand(0, 4);
    this->animTakt = intRand(0, 15);
    this->gf = cell->gf;
    cell->plane->trees.push(this);
}