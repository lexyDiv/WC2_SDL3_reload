#include "process.cpp"
//=>out

void Game::fractionsControl() {
    this->fractions.forEach([](Fraction* fr){
         fr->controller();
    });
};