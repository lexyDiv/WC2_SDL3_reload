#include "Game.cpp"
//=>draw

GameField gfData;

void Game::create()
{

  gfData = GameField();
  this->gf = &gfData; 
  this->gf->getPathes(&this->pathes[1], 1);
  this->gf->game = this;
  this->gf->create();



  Fraction *fraction = new Fraction;
  fraction->create(this, &orcs, "red");
  fraction->control = "human";
  this->fractions.push(fraction);


  this->isGFComplite = true;

  thDatas.forEach([](ThData *th)
                  { th->createMyActiveProgZone(thDatas.length); 
                  });
}