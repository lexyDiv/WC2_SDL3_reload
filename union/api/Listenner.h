#include "Mouse/out.h"



bool nextMove = false;
SDL_Event e;

Array<float> tiks;

void listenner(bool &quit)
{
    while (SDL_PollEvent(&e) != 0)
    {
        // User requests quit
        if (e.type == SDL_EVENT_QUIT)
        {

            quit = true;
        }
        if (e.type == SDL_EVENT_KEY_DOWN)
        {
            // console.log(to_string(e.key.keysym.scancode)); // int 40
            if (e.key.key == 40)
            {
                nextMove = true;
                // console.log("eneter");
                //  game->speed++;
                //  game->pause = false;
                // game->tryDel = true;
                // game->needForPause = false;
            }
            if (e.key.key == 44)
            {
                // game->pause = false;
                float acc = 0.0f;
                tiks.forEach([&acc](float e){
                    acc += e;
                });
                console.log("res : " + to_string(acc / float(tiks.length)));
            }
        }
        if (e.type == SDL_EVENT_MOUSE_MOTION)
        {
            mouse.move(e.motion.x, e.motion.y);
            // console.log(to_string(e.motion.x));
            mouse.isMove = true;
        }
        if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        {
            // console.log(to_string(e.button.x)); // 1, 2, 3
            // WayPoint* pnt = new WayPoint(e.button.x, e.button.y);
            // fs.write("levels/level2.txt", pnt, sizeof(WayPoint));
            // wayLine->push(pnt);
            // pnt = nullptr;
            // console.log("click");

            mouse.pressKey(e.button.button);
            mouse.keyDown(e.button.button);
            // console.log("click point");
        }
        if (e.type == SDL_EVENT_MOUSE_BUTTON_UP)
        {
            // console.log(to_string(e.button.button)); // 1, 2, 3
            mouse.upKey(e.button.button);
            mouse.keyUp(e.button.button);
        }
        if (e.type == SDL_EVENT_MOUSE_WHEEL)
        {

            console.whellOrder(e.motion.yrel);
        }
    }
    mouse.listen = true;
}