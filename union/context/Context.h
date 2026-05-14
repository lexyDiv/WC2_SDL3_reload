#include "in.h"

// => context.cpp

struct Color
{
    int R;
    int G;
    int B;
};

struct Point
{
    float x;
    float y;
};

class Context
{
public:

   float scaleIndexX = 1.0f;
   float scaleIndexY = 1.0f;

    const SDL_PixelFormatDetails *pixelFormat = SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_RGBA8888);
    SDL_Window *gWindow = nullptr;
    Context(float SCREEN_WIDTH, float SCREEN_HEIGHT);
    Color ColorsMap(std::string color);
    void Close();
    void ClearRect();
    void ClearRect(float x, float y, float width, float height);
    void End();
    SDL_Renderer *getRenderer();
    void getFont();

    void DrawText(float x, float y, float size, string str);
    void DrawText(float x, float y, float size, string str, int A);

    void CreateDrawZone(int x, int y, int width, int height);

    void DrawLine(SDL_FPoint start, SDL_FPoint finish, int R, int G, int B, int A);
    void DrawLine(SDL_FPoint start, SDL_FPoint finish, int R, int G, int B);
    void DrawLine(SDL_FPoint start, SDL_FPoint finish, string color, int A);
    void DrawLine(SDL_FPoint start, SDL_FPoint finish, string color);
    void DrawLine(SDL_FPoint start, SDL_FPoint finish);
    void DrawHendleFigure(SDL_FPoint arrPoints[], SDL_FPoint rotPoint, int length, float conor, string color);

    void FillRect(float x, float y, float width, float height, int R, int G, int B, int A);
    void FillRect(float x, float y, float width, float height, int R, int G, int B);
    void FillRect(float x, float y, float width, float height, std::string color, int A);
    void FillRect(float x, float y, float width, float height, std::string color);
    void FillRect(float x, float y, float width, float height);

    void StrokeRect(float x, float y, float width, float height, int R, int G, int B, int A);
    void StrokeRect(float x, float y, float width, float height, int R, int G, int B);
    void StrokeRect(float x, float y, float width, float height, std::string color, int A);
    void StrokeRect(float x, float y, float width, float height, std::string color);
    void StrokeRect(float x, float y, float width, float height);

    void PixelHendler(Image *image,
                      int x,
                      int y,
                      int width,
                      int height,
                      function<void(Uint32 *pixelsArr, const SDL_PixelFormatDetails *pixelFormat)> fn);
    void DrawImage(Image *image,
                   float animX,
                   float animY,
                   float animW,
                   float animH,
                   float x,
                   float y,
                   float width,
                   float height,
                   SDL_FlipMode flip,
                   double conor,
                   int alpha,
                   float rotX,
                   float rotY,
                   int R,
                   int G,
                   int B);
    void DrawImage(Image *image,
                   float animX,
                   float animY,
                   float animW,
                   float animH,
                   float x,
                   float y,
                   float width,
                   float height);
    void DrawImage(Image *image,
                   float animX,
                   float animY,
                   float animW,
                   float animH,
                   float x,
                   float y,
                   float width,
                   float height,
                   SDL_FlipMode flip);
    void DrawImage(Image *image,
                   float animX,
                   float animY,
                   float animW,
                   float animH,
                   float x,
                   float y,
                   float width,
                   float height,
                   SDL_FlipMode flip,
                   double conor);
    void DrawImage(Image *image,
                   float animX,
                   float animY,
                   float animW,
                   float animH,
                   float x,
                   float y,
                   float width,
                   float height,
                   SDL_FlipMode flip,
                   double conor,
                   int alpha);
    void DrawImage(Image *image,
                   float animX,
                   float animY,
                   float animW,
                   float animH,
                   float x,
                   float y,
                   float width,
                   float height,
                   SDL_FlipMode flip,
                   double conor,
                   int alpha,
                   float rotX,
                   float rotY);

    class conorDelta
    {
    public:
        float conor;
        float delta;
    };
    ~Context();

public:
    float SCREEN_WIDTH;
    float SCREEN_HEIGHT;
    void *mRawPixels = nullptr;
    int mRawPitch = 0;
    SDL_Renderer *gRenderer = renderer;
    Image *font = nullptr;
};