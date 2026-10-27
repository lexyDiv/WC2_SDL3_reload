#include "in.h"
//=> create

Game::~Game()
{
    int deleteCount = 0;

    this->allBoos.forEach([&deleteCount](Boo *boo)
                          {
        delete boo;
        boo = nullptr;
    deleteCount++; });
    cout << "delete " + to_string(deleteCount) + " booses" << endl;
    deleteCount = 0;

    this->allTracesPtr.forEach([&deleteCount](Trace *t)
                               {
     if (t)
     {
         delete t;
        t = nullptr;
     } 
    deleteCount++; });

    cout << "==========================================" << endl;
    cout << "tracesCount = " + to_string(tracesCount) << endl;
    cout << "allTracesPtr.length = " + to_string(this->allTracesPtr.length) << endl;
    cout << "delete " + to_string(deleteCount) + " traces" << endl;
    deleteCount = 0;

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