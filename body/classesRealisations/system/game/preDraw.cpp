#include "draw.cpp"
//=>process

void Game::preDraw()
{
     
        this->gf->miniMapMouseControl();
        this->gf->offsetControl();
       // this->gf->fieldClick();
      //  this->gf->fieldClickRight();
       // this->objMenu->control();
      //  this->objMenu->buttonsBar.control();
        mouse.defaultKeys();
    
}