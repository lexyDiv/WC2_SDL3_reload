#include "in.h"
//=>draw

void TownHall::create(Cell *cell, bool isComplite = false, bool isNew = false)
{

    this->fraction->unitCount++;
    this->persNum = this->fraction->unitCount;

    this->thwd.clear();
    for (int i = 0; i < thDatas.length; i++)
    {
        Td_xploredData tapd;
        this->thwd.push(tapd);
    }

    this->get4x4myCells(cell);

    Cell *exitCell = cell->bottom_right->bottom_right->bottom_right->bottom_right;
    Cell *centerCell = cell->bottom_right;
    this->cell = centerCell;
    this->game = this->cell->game;
    this->fraction->allBuildings.push(this);

    this->getContactAndExitCells(cell, exitCell, centerCell);
    this->getWellComeCells();
    this->getTrees();
    this->getShahts();
    this->name = "greatHall";
    this->type = "building";
    this->mapColor = this->fraction->mapColor;
    this->image = this->fraction->townHall.img_1;
    this->gf = this->cell->gf;
    this->x = cell->x;
    this->y = cell->y;
    this->getGabX = cell->gabX * 4;
    this->getGabY = this->getGabX;
    this->drawIndexY = cell->y + 30;

    this->animGabX = 128;
    this->animGabY = 128;
    this->animStepX = 128;
    this->animStepY = 128;

    this->animX = 0;
    this->animY = 0;
    this->hpMax = this->fraction->townHall.hpByLevel.getItem(this->level); // 1200;
    this->hp = this->hpMax / 10;
    this->isComplite = isComplite;

    if (this->isComplite)
    {
        this->fraction->fTownHoll.townHollsByLevel.getItemPtr(this->level)->push(this);
        this->hp = this->hpMax;
    }
    else
    {
        this->hp = this->hpMax / 10;
    }
    ///////////////////////////////////////////////////////////////////////
    console.log(this->hp);
    this->createTimer = 0;

    canGiveTree = false;
    canGiveGold = false;
    canTakeWood = true;
    canTakeGold = true;

    if (isNew)
    {
        this->cell->game->AllUnitsPtr.push(this);
    }
    else
    {

        this->isPotentialWayComplite = true;
        this->orderOnWay.isComplite = true;
        this->isGetMyCell = true;
        this->inFight = false;
        this->outHoldTimer = 0;
        this->way.clear();
        this->iNeedFreeWay = false;
        this->targetData.clear();
        this->isDelete = false;
        this->deleteTimer = 3000;
        this->alpha = 255;
        this->inBufer = false;
    }
}