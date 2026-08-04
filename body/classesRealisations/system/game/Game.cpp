#include "in.h"
//=> create

Game::~Game()
{
    this->allTreesPtr.forEach([](Unit *tree){
        if (tree) {
            delete tree;
        }
    });

    this->allMountsPtr.forEach([](Unit *mount){
        if (mount) {
            delete mount;
        }
    });

    this->allShahtsPtr.forEach([](Unit *shaht){
        if (shaht) {
            delete shaht;
        }
    });

        this->allOilsPtr.forEach([](Unit *oil){
        if (oil) {
            delete oil;
        }
    });
    // this->AllUnits.forEach([](Unit *unit)
    //                        {
    //     delete unit;
    //     unit = nullptr; });

    this->fractions.forEach([](Fraction *fr)
                            {
        delete fr;
        fr = nullptr; });

    // delete nationsHub;
    // nationsHub = nullptr;   // opredelit chto eto !!!
}