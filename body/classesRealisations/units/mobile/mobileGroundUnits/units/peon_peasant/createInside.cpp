#include "preDraw.cpp"
//=>stendOnCell

void Peon_peasant::createInside(Cell *c, bool isNew = false)
{

    this->persNum = this->fraction->unitCount;
    this->cell = nullptr;
    this->gf = c->gf;
    this->game = c->game;
    this->name = "peon";
    this->type = "life";
    this->mapColor = this->fraction->mapColor;
    this->image = this->fraction->peon.img_1;
    this->x = c->x;
    this->y = c->y;
    this->getGabX = c->gabX;
    this->getGabY = this->getGabX;
    this->drawIndexY = c->y + c->gabX / 2;

    this->animGabX = 100;
    this->animGabY = 100;
    this->animStepX = 100;
    this->animStepY = 100;
    this->animCorrectionX = 25;
    this->animCorrectionY = 25;
    this->drawGabaritX = 100;
    this->drawGabaritY = 100;
    this->inOutCount = 0;


    this->animX = intRand(0, 8) * 100;
    this->animY = 0;
    this->hpMax = 50;
    this->hp = 50;
    this->deleteTimer = 3000;

    this->inOutTimer = 0;
    this->inSave = true;
    this->animMashtab = this->startAnimMashtab;
    this->fraction->allUnits.push(this);
    // this->fraction->AllLifeUnits.push(this);

    canGiveTree = false;
    canGiveGold = false;
    canTakeWood = false;
    canTakeGold = false;
    canBuild = true;
    canMove = true;

    if (isNew)
    {
        c->game->AllUnitsPtr.push(this);
        // console.log("push");
    }
    else
    {

        this->thwd.clear();
        ////////////////////////////// reset
        this->isPotentialWayComplite = true;
        this->orderOnWay.isComplite = true;
        this->isGetMyCell = true;
        this->fightTarget = nullptr;
        this->outHoldTimer = 0;
        this->way.clear();
        this->iNeedFreeWay = false;
        this->targetData.clear();
        this->isDelete = false;
        this->deleteTimer = 3000;
        this->alpha = 255;
        this->inBufer = false;
        this->isIgetMyTarget = false;
    }
}