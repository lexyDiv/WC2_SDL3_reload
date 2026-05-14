#include "basicDo.cpp"
// => union out

void basicDraw(function<void()> fn)
{
    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");
    fn();
    console.draw();
    ctx.End();
}