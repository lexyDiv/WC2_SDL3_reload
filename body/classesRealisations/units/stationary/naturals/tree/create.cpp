#include "Tree.cpp"
//=>getContactCells

void Tree::create(Cell *cell, bool isComplite = false, bool isNew = false)
{
    this->name = "tree";
    this->type = "tree";
    this->deleteTimer = 0;
    cell->groundUnit = this;
    this->myCells.push(cell);
    this->cell = cell;
    this->getContactCells();

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
    /////////////////////////////////////////// => AI
    int randAI = intRand(0, 2);
    ////////////////////////////////////////    <= AI
    if (randAI)
    {

        int randImg = intRand(0, 2);
        this->image = randImg ? imager.tree1 : imager.tree2;
        this->image2 = randImg ? imager.tree1Trup : imager.tree2Trup;
        this->animX = 200 * intRand(0, 4);
        this->animY = 200 * intRand(0, 4);
        this->animTakt = intRand(0, 15);
    }
    else
    {
        randAI = intRand(0, 8);

        this->animStepX = 100;
        this->animGabX = 100;
        this->animGabY = 100;
        this->isAI = true;
        if (!randAI)
        {
            this->image = imager.ai_tree_1;
            this->image2 = imager.ai_tree_1_trup;
        }
        else if (randAI == 1)
        {
            this->image = imager.ai_tree_2;
            this->image2 = imager.ai_tree_1_trup;
        }
        else if (randAI == 2)
        {
            this->image = imager.ai_tree_3;
            this->image2 = imager.ai_tree_1_trup;
        }
        else if (randAI == 3)
        {
            this->image = imager.ai_tree_4;
            this->image2 = imager.ai_tree_1_trup;
        }
        else if (randAI == 4)
        {
            this->image = imager.ai_tree_5;
            this->image2 = imager.ai_tree_1_trup;
        }
        else if (randAI == 5)
        {
            this->image = imager.ai_tree_6;
            this->image2 = imager.ai_tree_1_trup;
        }
        else if (randAI == 6)
        {
            this->image = imager.ai_tree_7;
            this->image2 = imager.ai_tree_1_trup;
        }  
        else if (randAI == 7)
        {
            this->image = imager.ai_tree_8;
            this->image2 = imager.ai_tree_1_trup;
        }               
        this->animX = 100 * intRand(0, 4);
        this->animY = 100 * intRand(0, 4);
    }

    this->gf = cell->gf;
    cell->plane->trees.push(this);
    // this->cell->game->AllUnitsPtr.push(this);
    this->cell->game->allTreesPtr.push(this);

    this->canGiveTree = true;
    // this->draw();
}