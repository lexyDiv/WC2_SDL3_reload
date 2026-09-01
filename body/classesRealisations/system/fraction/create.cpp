#include "activeUnitsControl.cpp"
//=>controller

void Fraction::create(Game *game, Nation *nation, string color)
{
//////////////////////////////
this->nation = nation;
this->color = color;
if (this->color == "red") {
    this->mapColor = { R: 255, G: 0, B: 0 };
}
  this->peon.createPeon(this);
  this->townHall.createTownHall(this);
    ///////////////////////////
   // console.log("fraction created");
   
   // console.log(this->nation.color);
//    this->game = game;
//     Unit *peon = new Peon_peasant;
//     peon->fraction = this;
//     peon->create(game->gf->field.getItem(10).getItem(3));
//     this->game->allPeonsPtr.push(peon);
//     this->AllLifeUnits.push(peon);

//    ProtoObj *peon2 = new Peon;
//    peon2->fraction = this;
//    peon2->create(game->gf->field.getItem(10).getItem(6));

//    this->peons.push(peon);
//    this->peons.push(peon2);
//     this->game->allPeons.push(peon2);
//     this->AllLifeUnits.push(peon2);

   ////////////////// townHall



    Unit *townHall = new TownHall;
    townHall->fraction = this;
    townHall->create(game->gf->field.getItem(2).getItem(20));
    this->fTownHoll.townHolls.push(townHall);
    townHall->isComplite = true;
    townHall->createTimer = 100;
    townHall->isActive = true;



   //this->activeBuildings.push(townHall);
   ////////////////// townHall

    townHall = new TownHall;
   townHall->fraction = this;
   townHall->create(game->gf->field.getItem(2).getItem(120));
   this->fTownHoll.level_1_townHollsCount++;
   this->fTownHoll.townHolls.push(townHall);
   townHall->isComplite = true;
   ////////////////////

   townHall->createTimer = 100;
   townHall->isActive = true;
   //this->activeBuildings.push(townHall);



    townHall = new TownHall;
   townHall->fraction = this;
   townHall->create(game->gf->field.getItem(2).getItem(220));
   this->fTownHoll.level_1_townHollsCount++;
   this->fTownHoll.townHolls.push(townHall);
   townHall->isComplite = true;
   ////////////////////

   townHall->createTimer = 100;
   townHall->isActive = true;
   //this->activeBuildings.push(townHall);


       townHall = new TownHall;
   townHall->fraction = this;
   townHall->create(game->gf->field.getItem(220).getItem(120));
   this->fTownHoll.level_1_townHollsCount++;
   this->fTownHoll.townHolls.push(townHall);
   townHall->isComplite = true;
   ////////////////////

   townHall->createTimer = 100;
   townHall->isActive = true;
   //this->activeBuildings.push(townHall);


          townHall = new TownHall;
   townHall->fraction = this;
   townHall->create(game->gf->field.getItem(220).getItem(20));
   this->fTownHoll.level_1_townHollsCount++;
   this->fTownHoll.townHolls.push(townHall);
   townHall->isComplite = true;
   ////////////////////

   townHall->createTimer = 100;
   townHall->isActive = true;
   //this->activeBuildings.push(townHall);


             townHall = new TownHall;
   townHall->fraction = this;
   townHall->create(game->gf->field.getItem(220).getItem(220));
   this->fTownHoll.level_1_townHollsCount++;
   this->fTownHoll.townHolls.push(townHall);
   townHall->isComplite = true;
   ////////////////////

   townHall->createTimer = 100;
   townHall->isActive = true;
   //this->activeBuildings.push(townHall);


       townHall = new TownHall;
   townHall->fraction = this;
   townHall->create(game->gf->field.getItem(225).getItem(220));
   this->fTownHoll.level_1_townHollsCount++;
   this->fTownHoll.townHolls.push(townHall);
   townHall->isComplite = true;
   ////////////////////

   townHall->createTimer = 100;
   townHall->isActive = true;
  //this->activeBuildings.push(townHall);


};