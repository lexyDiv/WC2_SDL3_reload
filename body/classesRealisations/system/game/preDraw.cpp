#include "draw.cpp"
//=>process

void Game::preDraw()
{
     //  console.log(this->gf->field.getItemLnk(0).getItemLnk(0)->plane->type);
        this->gf->miniMapMouseControl();
        this->gf->offsetControl();
       // this->gf->fieldClick();
      //  this->gf->fieldClickRight();
       // this->objMenu->control();
      //  this->objMenu->buttonsBar.control();
        mouse.defaultKeys();
    
}