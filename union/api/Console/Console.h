#include "in.h"

// => Console.cpp

class saveStr
{
public:
    string str;
    int index;
    saveStr() {};
    saveStr(string str, int index)
    {
        this->str = str;
        this->index = index;
    };
};

class Console
{
public:
    std::mutex mute;
    Array<saveStr> strArr;
    Console(int length);
    void clear();
    void log(string str);
    void preLog(string str);
    void proc(float mX, float mY, bool pressed);
    void draw();
    void drawSB(int A);
    void procSB();
    void procRunner(int mX, int mY);
    void whellOrder(int vector);
    ~Console();

private:
    bool hover = false;
    bool clicked = false;
    int length;
    float x = 10;
    float y = 410;
    SDL_FRect clearButton = {this->x + 470, this->y, 30, 15};
    SDL_FRect scrollBar = {this->x + 470, this->y + 15, 30, 165};
    SDL_FRect scrollRunner = {this->x + 470, this->y + 15, 30, 30};
    float scrollRunnerDrawY = 0;
    float stopAutoScroll = 0;
    SDL_FPoint ClickData = {-1, -1};
    bool clickDataStatus = false;
    Image *runner = new Image("union/src/runner.png");
    bool clickRunnerZone = false;
    bool clearButtonHover = false;
    bool runnerHover = false;
    bool runnerTake = false;
    SDL_FPoint runnerTakePoint = {-1, -1};
    float saveMouseX = 0;
    float saveMouseY = 0;
    float width = 500;
    float height = 180;
    float index = 1;
    bool canClear = false;
    int interval = 0;
    bool isBlocked = false;
    void delArr();
};

bool rect_PointCollision(SDL_FPoint p, SDL_FRect r)
{
    if (!(p.x < r.x || p.x > r.x + r.w || p.y < r.y || p.y > r.y + r.h))
    {
        return true;
    }
    return false;
}