// gdb ./prog core
// g++ -g main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image
// g++ main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image

#include "union/out.h"

int main()
{

    console.log("popa");

    while (true)
    {
        if (!quit)
        {
            listenner(quit);
            ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
            ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

            //    // game->process(&startTick, &optimalDeltaTime);
            
            console.proc(mouse.x, mouse.y, mouse.leftKey);
            console.draw();
            ctx.End();
        }
        else
        {
            ctx.Close();
            break;
        }
    }
}