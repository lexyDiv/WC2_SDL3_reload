#include "preDraw.cpp"
//=>fractionsControl

int th_count = std::thread::hardware_concurrency() - 1;
std::vector<std::thread> threads;
// Uint64 PWPstart;

void Game::process()
{

    this->fractionsControl();

    this->gf->activeShahtsControl();
    this->gf->trupsControl();
    this->gf->updateClasters();

    //////////////////////////////////////////////////////////////////////////////////

    orcs.allTracesBuffers.forEach([](Array<Trace *> &buffer)
                                  { buffer.filterSelf([](Trace *t)
                                                      { return !t->readyToOut; }); });

    humans.allTracesBuffers.forEach([](Array<Trace *> &buffer)
                                    { buffer.filterSelf([](Trace *t)
                                                        { return !t->readyToOut; }); });

    orcs.allBuffers.forEach([](Array<Unit *> *b)
                            { b->filterSelf([](Unit *u)
                                            { return !u->inBufer; }); });

    humans.allBuffers.forEach([](Array<Unit *> *b)
                              { b->filterSelf([](Unit *u)
                                              { return !u->inBufer; }); });

    //console.log("length = ", orcs.allTracesBuffers.getItemLnk(0).length);                                          
    //////////////////////////////////////////////////////////////////////////////

    this->allBoos.filterSelf([](Boo *boo)
                             {

        if (boo->readyToOut) {
            delete boo;
            boo = nullptr;
            return true;
        }
        else
        {
            boo->process();
            return false;
        } });

    // console.log("buffer = " + orcs.peonsBuffer.length);

    // this->unitsBufer.filterSelf([](Unit *u){
    //     return !u->inBufer;
    // });

    // console.log("length = ", this->unitsBufer.length);

    this->thSpin = !this->thSpin;

    thDatas.forEach([](ThData *td)
                    { threads.emplace_back(&ThData::process, td); });

    // while (!this->isGFComplite)
    // {
    //     basicDraw([]()
    //               {
    // ctx.FillRect(0, 0, 1000, 1000, "white");
    // ctx.DrawText(30, 30, 50, "loading"); });
    //     this_thread::sleep_for(chrono::nanoseconds(10000));
    // }

    for (auto &t : threads)
    {
        t.join();
    }

    threads.clear();

    thDatas.forEach([](ThData *td)
                    { threads.emplace_back(&ThData::PWProcess, td); });

    this->preDraw();
}