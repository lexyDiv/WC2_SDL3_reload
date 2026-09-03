// gdb ./prog core
// export DEBUGINFOD_URLS="https://debuginfod.archlinux.org"
// g++ -g -O0 main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image
// g++ -g main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image
// g++ main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image

#include "body/out.h"

void bdofn()
{
    game->process();
};

void bdrfn()
{
    game->draw();
};

void loadDrawFn()
{
    ctx.FillRect(0, 0, 1000, 1000, "white");
    ctx.DrawText(30, 30, 50, "loading");
}





int main()
{
    int PWPmax = 0;

    for (int i = 0; i //< 1;
       < th_count;
         i++)
    {
        ThData *td = new ThData(i);
        td->thds = &thDatas;
        thDatas.push(td);
    }

    while (!quit)
    {

        if (!game->isGFComplite || th_create_game)
        {
            if (!th_create_game)
            {
                th_create_game = new thread(th_create);
            }
            
            loadingDraw();

            if (game->isGFComplite)
            {
                th_create_game->join();
                delete th_create_game;
                th_create_game = nullptr;
            }
        }
        else // if (!th_create_game)
        {
            game->startTick = SDL_GetTicks();

            basicDo();

            basicDraw();

            for (auto &t : threads)
            {
                t.join();
            }

            game->finishTick = SDL_GetTicks();
           //////////////////////////
           int PWPres = int(game->finishTick) - int(PWPstart);
           
           if (PWPres > PWPmax) {
            PWPmax = PWPres;
           }
           console.log(to_string(PWPres) + " max : " + to_string(PWPmax));
           /////////////////////////


            int deltaTime = int(game->finishTick) - int(game->startTick);
            if (deltaTime < game->optimalDeltaTime)
            {
                //  console.log("delay : " + to_string(game->optimalDeltaTime - deltaTime));

                SDL_Delay(game->optimalDeltaTime - deltaTime);
            }
            else
            {
                //  ThData *thdMin = nullptr;
                //  int minDeep = 30000;
                // ThData *thdMax = nullptr;
                //  int maxDeep = 0;
                //  thDatas.forEach([&thdMin, &minDeep, &thdMax, &maxDeep](ThData *t){
                //        if (t->deep < minDeep) {
                //         minDeep = t->deep;
                //         thdMin = t;
                //        }
                //         if (t->deep > maxDeep) {
                //         maxDeep = t->deep;
                //         thdMax = t;
                //        }
                //  });
                //  console.log("min : " + to_string(thdMin->num) + " d = " + to_string(thdMin->deep) + " max : " + to_string(thdMax->num) + " d = " + to_string(thdMax->deep));
               // console.log("hold " + to_string(thDatas.getItem(0)->deep));
            }

            threads.clear();
        }
    }
    game->quit = quit;
    ctx.Close();

    thDatas.forEach([](ThData *td)
                    { delete td; });
}