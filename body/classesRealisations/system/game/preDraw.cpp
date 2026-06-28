#include "draw.cpp"
//=>process

void Game::preDraw()
{
    //   console.log(to_string(this->gf->field.getItemLnk(0).getItemLnk(0)->plane->contactPlanes.getItemLnk(0)->cellsToOther.length));
        this->gf->miniMapMouseControl();
        this->gf->offsetControl();
       // this->gf->fieldClick();
      //  this->gf->fieldClickRight();
       // this->objMenu->control();
      //  this->objMenu->buttonsBar.control();
        mouse.defaultKeys();
    
}