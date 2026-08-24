#include "process.cpp"
//=>out

void Game::fractionsControl() {
    if(!this->isGFComplite) {return;};
    this->fractions.forEach([](Fraction* fr){
         fr->controller();
    });
};