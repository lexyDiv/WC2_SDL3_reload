#include "preDraw.cpp"
//=>fractionsControl

int th_count = std::thread::hardware_concurrency() - 1;
std::vector<std::thread> threads;
//Uint64 PWPstart;

void Game::process()
{

    this->fractionsControl();
    this->gf->activeShahtsControl();
    this->gf->trupsControl();
    this->gf->updateClasters();

//    this->gf->clasters.forEach([](Array<Claster *> &line){
//     line.forEach([](Claster *cl){
//         cl->getZones();
//     });
//    });

//       this->gf->clasters.forEach([](Array<Claster *> &line){
//     line.forEach([](Claster *cl){
//         cl->zones.forEach([](Zone *z){
//             z->getAroundZones();
//         });
//     });
//    });

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