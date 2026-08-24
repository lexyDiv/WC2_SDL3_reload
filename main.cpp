// gdb ./prog core
// g++ -g main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image
// g++ main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image

#include "body/out.h"

// void foo()
// {

//     while (!quit)
//     {
//         this_thread::sleep_for(chrono::nanoseconds(1));
//     }
// };

// void foo2()
// {
//     while (!quit)
//     {
//         this_thread::sleep_for(chrono::nanoseconds(1));
//     }
// };

// void foo3()
// {
//     while (!quit)
//     {
//         this_thread::sleep_for(chrono::nanoseconds(1));
//     }
// };

// void do1()
// {
//     game->create();

//     while (!quit)
//     {
//         this_thread::sleep_for(chrono::nanoseconds(1));
//     }
// }



int main()
{
  // game->create();



    for (int i = 0; i < th_count; i++) {
         ThData *td = new ThData(i);
         td->thds = &thDatas;
         thDatas.push(td);
        // threads.emplace_back(&ThData::process, td);
    } 




    // thread th_1(do1);
    // thread th_2(foo);
    // thread th_3(foo2);
    // thread th_4(foo3);

    int optimalDeltaTime = 1000 / 30;
   // console.log(to_string(std::thread::hardware_concurrency())); // threds count
   
    while (!quit)
    {
       // console.log(to_string(game->isGFComplite));
        Uint64 startTick = SDL_GetTicks();

        basicDo([]()
                { game->process(); });

        basicDraw([]()
                  { game->draw(); });

        Uint64 finishTick = SDL_GetTicks();
        int deltaTime = int(finishTick) - int(startTick);
        if (deltaTime < optimalDeltaTime)
        {
          //  console.log("delay : " + to_string(optimalDeltaTime - deltaTime));
            SDL_Delay(optimalDeltaTime - deltaTime);
        } else {
            console.log("hold");
        }
    }
    game->quit = quit;
    ctx.Close();

    // th_1.join();
    // th_2.join();
    // th_3.join();
    // th_4.join();

    //     for (auto& t : threads) {
    //     t.join();
    // }

    thDatas.forEach([](ThData* td){
        delete td;
    });
}