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

    while (!quit)
    {

        if (!game->isGFComplite || th_create_game)
        {
            if (!th_create_game) {
                th_create_game = new thread(th_create);
            }
            basicDraw([]()
                      {
    ctx.FillRect(0, 0, 1000, 1000, "white");
    ctx.DrawText(30, 30, 50, "loading"); });

            if (game->isGFComplite)
            {
                th_create_game->join();
                delete th_create_game;
                th_create_game = nullptr;
            }
        }
        else //if (!th_create_game)
        {
            game->startTick = SDL_GetTicks();

            basicDo([]()
                    { game->process(); });

            basicDraw([]()
                      { game->draw(); });

            for (auto &t : threads)
            {
                t.join();
            }

            game->finishTick = SDL_GetTicks();
            int deltaTime = int(game->finishTick) - int(game->startTick);
            if (deltaTime < game->optimalDeltaTime)
            {
                //  console.log("delay : " + to_string(game->optimalDeltaTime - deltaTime));

                SDL_Delay(game->optimalDeltaTime - deltaTime);
            }
            else
            {
                console.log("hold");
            }

            threads.clear();
        }
    }
    game->quit = quit;
    ctx.Close();

    thDatas.forEach([](ThData *td)
                    { delete td; });
}