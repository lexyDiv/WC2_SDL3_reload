// gdb ./prog core
// g++ -g main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image
// g++ main.cpp -I./include -fmax-include-depth=5000 -o prog -L./sdl3-sample/build -lSDL3 -lSDL3_image

#include "body/out.h"

Game *game = new Game;

void foo()
{
    while (!quit)
    {
        this_thread::sleep_for(chrono::nanoseconds(1));
    }
};

void do1()
{
    game->create();

    while (!quit)
    {
        this_thread::sleep_for(chrono::nanoseconds(1));
    }
}


int main()
{


    thread th_1(do1);
    thread th_2(foo);
    thread th_3(foo);
    thread th_4(foo);

    while (!quit)
    {
        // thread th_do_1(foo);
        // thread th_do_2(foo);
        // thread th_do_3(foo);
        // thread th_do_4(foo);
        basicDo([]()
                { game->process(); }); // units prog basic th
                                       // th_do_1.join();
                                       // th_do_2.join();
                                       // th_do_3.join();
                                       // th_do_4.join();
                                       // thread th_way_1(foo);
                                       // thread th_way_2(foo);
                                       // thread th_way_3(foo);
                                       // thread th_way_4(foo);
                                       // // user input & fractions control
        basicDraw([]()
                  { game->draw(); });
        // // calculated hold here || needReturn = true;
        // th_way_1.join();
        // th_way_2.join();
        // th_way_3.join();
        // th_way_4.join();
    }
    ctx.Close();

    th_1.join();
    th_2.join();
    th_3.join();
    th_4.join();

    delete game;
    game = nullptr;
}