#include "miniMapDraw.cpp"
//=>out

void GameField::miniMapUpdate() {
      if (!this->miniMap) {
  this->miniMap = new Image(this->gabarit, this->gabarit);
  }

    ctx.PixelHendler(
        this->miniMap,
        0,
        this->miniMapUpdateVer,
        this->gabarit,
        1, [this](Uint32 *pixelsArr, const SDL_PixelFormatDetails *pixelFormat)
        { this->field.getItemLnk(this->miniMapUpdateVer).forEach([pixelsArr, pixelFormat](Cell *cell, int index)
                                                              {
														  pixelsArr;
														  pixelFormat;
														  Color color = cell->getMapColor();
                              SDL_Palette palette;
														  Uint8 r = color.R;
														  Uint8 g = color.G;
														  Uint8 b = color.B;
														  Uint8 a = 255;
														  Uint32 hzRes = SDL_MapRGBA(pixelFormat, &palette, r, g, b, a);
														  pixelsArr[index] = hzRes; }); });
    this->miniMapUpdateVer++;
    if (this->miniMapUpdateVer == this->gabarit)
    {
        this->miniMapUpdateVer = 0;
    }
}