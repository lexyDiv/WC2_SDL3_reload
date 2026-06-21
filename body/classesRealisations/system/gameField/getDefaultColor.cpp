#include "mapInit.cpp"
//=> out

Color GameField::getDefaultColor(char lit)
{
    switch (lit)
    {
    case '0':
        return ctx.ColorsMap("green");
    case 'g':
        return ctx.ColorsMap("violet");
    case 't':
        return ctx.ColorsMap("dgreen");
    case '1':
        return ctx.ColorsMap("dgreen");
    case 'w':
        return ctx.ColorsMap("blue");
    case 'S':
        return ctx.ColorsMap("green");
    default:
        return ctx.ColorsMap("black");
    }
}