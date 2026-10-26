#include "in.h"
//=> create

Game::~Game()
{
    int deleteCount = 0;

    this->allBoos.forEach([](Boo *boo){
        delete boo;
        boo = nullptr;
    });

    this->AllUnitsPtr.forEach([&deleteCount](Unit *u)
                              {
        delete u;
        u = nullptr;
        deleteCount++; });
    cout << "delete " + to_string(deleteCount) + " units" << endl;

    // this->allTreesPtr.forEach([&deleteCount](Unit *tree)
    //                           {
    //     if (tree) {
    //         deleteCount++;
    //         delete tree;
    //     } });

    //     cout << "delete " + to_string(deleteCount) + " units" << endl;

    // this->allMountsPtr.forEach([](Unit *mount)
    //                            {
    //     if (mount) {
    //         delete mount;
    //     } });

    // this->allShahtsPtr.forEach([](Unit *shaht)
    //                            {
    //     if (shaht) {
    //         delete shaht;
    //     } });

    // this->allOilsPtr.forEach([](Unit *oil)
    //                          {
    //     if (oil) {
    //         delete oil;
    //     } });
    // // this->AllUnits.forEach([](Unit *unit)
    // //                        {
    // //     delete unit;
    // //     unit = nullptr; });

    this->fractions.forEach([](Fraction *fr)
                            {
        delete fr;
        fr = nullptr; });

    // delete nationsHub;
    // nationsHub = nullptr;   // opredelit chto eto !!!
}

void Game::addToAllUnitsPtr(Unit *unit)
{
    mutex mt;
    mt.lock();
    this->AllUnitsPtr.push(unit);
    mt.unlock();
}


// void Game::addToUnitsBufer(Unit *unit)
// {
//     mutex mt;
//     mt.lock();
//     this->unitsBufer.push(unit);
//     mt.unlock();
// }