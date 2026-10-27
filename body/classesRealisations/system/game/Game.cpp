#include "in.h"
//=> create

Game::~Game()
{


    this->allTreesPtr.forEach([](Unit *tree)
                              {
        if (tree) {
            delete tree;
        } });
        
    this->allMountsPtr.forEach([](Unit *mount)
                               {
        if (mount) {
            delete mount;
        } });

    this->allShahtsPtr.forEach([](Unit *shaht)
                               {
        if (shaht) {
            delete shaht;
        } });

    this->allOilsPtr.forEach([](Unit *oil)
                             {
        if (oil) {
            delete oil;
        } });


    this->fractions.forEach([](Fraction *fr)
                            {
        delete fr;
        fr = nullptr; });
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::addToAllUnitsPtr(Unit *unit)
{
    mutex mt;
    mt.lock();
    this->AllUnitsPtr.push(unit);
    mt.unlock();
}

void Game::addToAllTracesPtr(Trace *t)
{
  //  mutex mt;
   // mt.lock();
    this->allTracesPtr.push(t);
  //  mt.unlock();
}

// void Game::addToUnitsBufer(Unit *unit)
// {
//     mutex mt;
//     mt.lock();
//     this->unitsBufer.push(unit);
//     mt.unlock();
// }