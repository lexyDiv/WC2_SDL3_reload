// gdb ./prog core
// g++ -g main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image
// g++ main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image

#include "body/out.h"

int main()
{

    for (int i = 0; i < th_count; i++)
    {
        ThData *td = new ThData(i);
        td->thds = &thDatas;
        thDatas.push(td);
    }

    int optimalDeltaTime = 1000 / 30;
    
    while (!quit)
    {
        // console.log(to_string(game->isGFComplite));
        Uint64 startTick = SDL_GetTicks();

        basicDo([]()
                {
                     game->process(); 
                    });

        basicDraw([]()
                  { game->draw(); });

        Uint64 finishTick = SDL_GetTicks();
        int deltaTime = int(finishTick) - int(startTick);
        if (deltaTime < optimalDeltaTime)
        {
            //  console.log("delay : " + to_string(optimalDeltaTime - deltaTime));
            SDL_Delay(optimalDeltaTime - deltaTime);
        }
        else
        {
            console.log("hold");
        }

        for (auto &t : threads)
        {
            t.join();
        }

        threads.clear();
    }
    game->quit = quit;
    ctx.Close();

    thDatas.forEach([](ThData *td)
                    { delete td; });
}