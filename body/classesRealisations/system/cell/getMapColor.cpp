#include "draw.cpp"
//=>out

Color Cell::getMapColor()
{
    if (this->groundUnit)
    {
        return this->groundUnit->mapColor;
    }
    return this->mapColor;
}