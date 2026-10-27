#include "activeUnitsControl.cpp"
//=>controller

void Fraction::create(Game *game, Nation *nation, string color)
{
  //////////////////////////////
  this->nation = nation;
  this->color = color;
   this->game = game;
  if (this->color == "red")
  {
    this->mapColor = {R : 255, G : 0, B : 0};
  }
  this->peon.createPeon(this);
  this->townHall.createTownHall(this);
  this->unionCase = 1;
  ///////////////////////////
  // console.log("fraction created");

  // console.log(this->nation.color);
 

  // Unit *peon = new Peon_peasant(this);
  // peon->persNum = 2;
  // peon->fraction = this;
  // peon->create(game->gf->field.getItem(3).getItem(24));


  //  Unit *peon2 = new Peon_peasant(this);
  //  peon2->persNum = 1;
  //  peon2->fraction = this;
  //  peon2->create(game->gf->field.getItem(2).getItem(19)); // 8 // 7 => magistral 17 ok 18 ok 19 ok


  ////////////////// townHall

  Unit *townHall = nullptr;

  townHall = new TownHall;
  townHall->fraction = this;
  townHall->create(game->gf->field.getItem(2).getItem(20), true, true);
  townHall->isActive = true;
  townHall->createTimer = 1;

  ////////////////////////////////////////////////////////////////////

  // townHall = new TownHall;
  // townHall->fraction = this;
  // townHall->create(game->gf->field.getItem(2).getItem(120), true, true);
  // townHall->isActive = true;
  // townHall->createTimer = 1;

  // /////////////////////////////////////////////////////////

  // townHall = new TownHall;
  // townHall->fraction = this;
  // townHall->create(game->gf->field.getItem(2).getItem(220), true, true);
  // townHall->isActive = true;
  // townHall->createTimer = 1;

  // //////////////////////////////////////////////////////////////

  // townHall = new TownHall;
  // townHall->fraction = this;
  // townHall->create(game->gf->field.getItem(220).getItem(120), true, true);
  // townHall->isActive = true;
  // townHall->createTimer = 1;

  // /////////////////////////////////////////////////////////////

  // townHall = new TownHall;
  // townHall->fraction = this;
  // townHall->create(game->gf->field.getItem(220).getItem(20), true, true);
  // townHall->isActive = true;
  // townHall->createTimer = 1;

  // /////////////////////////////////////////////////////////////

  // townHall = new TownHall;
  // townHall->fraction = this;
  // townHall->create(game->gf->field.getItem(220).getItem(220), true, true);
  // townHall->isActive = true;
  // townHall->createTimer = 1;

  // /////////////////////////////////////////////////////////////

  // townHall = new TownHall;
  // townHall->fraction = this;
  // townHall->create(game->gf->field.getItem(230).getItem(220), true, true);
  // townHall->isActive = true;
  // townHall->createTimer = 1;

  // /////////////////////////////////////////////////////////////


};