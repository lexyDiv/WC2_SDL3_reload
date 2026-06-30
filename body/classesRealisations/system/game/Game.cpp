#include "in.h"
//=> create

Game::~Game()
{
    this->allTreesPtr.forEach([](Unit *tree){
        if (tree) {
            delete tree;
        }
    });
    // this->AllUnits.forEach([](Unit *unit)
    //                        {
    //     delete unit;
    //     unit = nullptr; });

    // this->fractions.forEach([](Fraction *fr)
    //                         {
    //     delete fr;
    //     fr = nullptr; });

    // delete nationsHub;
    // nationsHub = nullptr;   // opredelit chto eto !!!
}