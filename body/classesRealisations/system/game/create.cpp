#include "Game.cpp"
//=>draw

GameField gfData;

void Game::create()
{
  gfData = GameField();
  this->gf = &gfData; // new GameField(&this->pathes[0], 1);
  this->gf->getPathes(&this->pathes[0], 1);
  this->gf->game = this;
  this->gf->create();

  //  this->objMenu = new ObjMenu;
  //  this->objMenu->create(this->gf);

  ////////////////////////////// fractons
  Fraction *fraction = new Fraction;
  fraction->create(this, &orcs, "red");
  fraction->control = "human";
  this->fractions.push(fraction);
  //////////////////////////////

  this->isGFComplite = true;

  thDatas.forEach([](ThData *th)
                  { th->createMyActiveProgZone(thDatas.length); });
}