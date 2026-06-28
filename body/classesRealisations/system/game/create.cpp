#include "Game.cpp"
//=>draw

GameField gfData;

void Game::create()
{
    gfData = GameField();
    this->gf = &gfData;//new GameField(&this->pathes[0], 1);
    this->gf->getPathes(&this->pathes[0], 1);
    this->gf->game = this;
    this->gf->create();

  //  this->objMenu = new ObjMenu;
  //  this->objMenu->create(this->gf);

    ////////////////////////////// fractons
  //  ProtoFraction *fraction = new Fraction;
  //  fraction->create(this, nationsHub->orcs.getItem3(0));
   // fraction->control = "human";
   // this->fractions.push(fraction);
    //////////////////////////////

    this->isGFComplite = true;
}