#include "basicDo.cpp"
// => union out

void bdrfn();

void basicDraw()
{
    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");
    bdrfn();
    console.draw();
    ctx.End();
}

void loadDrawFn();

void loadingDraw()
{
    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");
    loadDrawFn();
    console.draw();
    ctx.End();
}