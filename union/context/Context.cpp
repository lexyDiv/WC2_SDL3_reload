#include "Context.h"

// => context out

Context::Context(float SCREEN_WIDTH, float SCREEN_HEIGHT)
{
    this->SCREEN_WIDTH = SCREEN_WIDTH;
    this->SCREEN_HEIGHT = SCREEN_HEIGHT;

    bool success = true;

    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("video || audio is not init!");
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        // if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        // {
        //     printf("Warning: Linear texture filtering not enabled!");
        // }

        // Create window SDL_WINDOW_FULLSCREEN  SDL_WINDOW_OPENGL
        this->gWindow = SDL_CreateWindow("papa loh", this->SCREEN_WIDTH, this->SCREEN_HEIGHT,
                                         SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN 
                                         | SDL_WINDOW_OPENGL);

        if (this->gWindow == NULL)
        {
            SDL_Log("Can not window create !");
            success = false;
        }
        else
        {
            // Create vsynced renderer for window
            renderer = SDL_CreateRenderer(this->gWindow, nullptr);
            this->gRenderer = renderer;
            SDL_SetRenderVSync(this->gRenderer, 1);

            if (this->gRenderer == NULL)
            {
                SDL_Log("renderer is not created !");
                success = false;
            }
            else
            {
                this->getFont();
                SDL_SetRenderLogicalPresentation(this->gRenderer, this->SCREEN_WIDTH, this->SCREEN_HEIGHT,
                                                 SDL_LOGICAL_PRESENTATION_STRETCH); // strech
                // SDL_SetRenderLogicalPresentation(this->gRenderer, this->SCREEN_WIDTH, this->SCREEN_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX); // proportional strech

                // cout << "h : " + to_string(h) << endl;
            }
        }
    }

    if (!success)
    {
        this->Close();
        printf("this is pisya");
    };
}

Color Context::ColorsMap(std::string color)
{
    if (color == "red")
    {
        return {255, 0, 0};
    }
    else if (color == "orange")
    {
        return {255, 165, 0};
    }
    else if (color == "yellow")
    {
        return {255, 255, 0};
    }
    else if (color == "green")
    {
        return {0, 128, 0};
    }
    else if (color == "blue")
    {
        return {0, 0, 255};
    }
    else if (color == "violet")
    {
        return {127, 0, 255};
    }
    else if (color == "white")
    {
        return {255, 255, 255};
    }
    else if (color == "black")
    {
        return {0, 0, 0};
    }
    else if (color == "dgreen")
    {
        return {0, 100, 0};
    }
    return {0, 0, 0};
}

void Context::Close()
{
    try
    {
        // SDL_DestroyRenderer(this->gRenderer);
        // SDL_DestroyWindow(this->gWindow);
        // this->gWindow = nullptr;
        // this->gRenderer = nullptr;

        // mRawPixels = nullptr;
        // delete pixelFormat;
        // pixelFormat = nullptr;

        // IMG_Quit();
        SDL_Quit();
    }
    catch (const std::exception &e)
    {
        printf("delete is faled!");
    }
    printf(" all deleted ");
}

void Context::ClearRect()
{
    SDL_SetRenderDrawColor(this->gRenderer, 255, 255, 255, 255);
    SDL_FRect rect = {0, 0, this->SCREEN_WIDTH, this->SCREEN_HEIGHT};
    SDL_RenderFillRect(this->gRenderer, &rect);
}

void Context::ClearRect(float x, float y, float width, float height)
{
    SDL_SetRenderDrawColor(this->gRenderer, 255, 255, 255, 255);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderFillRect(this->gRenderer, &rect);
}

void Context::End()
{
    int w, h;
    SDL_GetCurrentRenderOutputSize(this->gRenderer, &w, &h);
    this->scaleIndexX = this->SCREEN_WIDTH / 1920;
    this->scaleIndexY = this->SCREEN_HEIGHT / 1080;
    SDL_RenderPresent(this->gRenderer);
}

SDL_Renderer *Context::getRenderer()
{
    return this->gRenderer;
}

void Context::getFont()
{
    if (this->font)
    {
        delete this->font;
        this->font = nullptr;
    }
    this->font = new Image("union/src/literas_1.png");
    if (this->font == nullptr)
    {
        SDL_Log("no font");
    }
}

void Context::DrawText(float x, float y, float size, string str)
{
    int drawX = x;
    for (int i = 0; i < str.size(); i++)
    {
        char litera = str[i];
        float animX = (litera - 33) * 20;
        this->DrawImage(this->font, animX, 0, 20, 20, drawX, y, size, size);
        drawX += size * 0.75;
    }
}

void Context::DrawText(float x, float y, float size, string str, int A)
{
    int drawX = x;
    for (int i = 0; i < str.size(); i++)
    {
        char litera = str[i];
        float animX = ((int)litera - 33) * 20;
        this->DrawImage(this->font, animX, 0, 20, 20, drawX, y, size, size, SDL_FLIP_NONE, 0, A);
        drawX += size * 0.75;
    }
}

void Context::CreateDrawZone(int x, int y, int width, int height)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = height;
    rect.w = width;
    SDL_SetRenderClipRect(this->gRenderer,
                          &rect);
}

void Context::DrawLine(SDL_FPoint start, SDL_FPoint finish, int R, int G, int B, int A)
{
    SDL_SetRenderDrawBlendMode(this->getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(this->getRenderer(), R, G, B, A);
    SDL_RenderLine(this->gRenderer, start.x, start.y, finish.x, finish.y);
}

void Context::DrawLine(SDL_FPoint start, SDL_FPoint finish, int R, int G, int B)
{
    SDL_SetRenderDrawColor(this->getRenderer(), R, G, B, 255);
    SDL_RenderLine(this->gRenderer, start.x, start.y, finish.x, finish.y);
}

void Context::DrawLine(SDL_FPoint start, SDL_FPoint finish, string color, int A)
{
    Color c = this->ColorsMap(color);
    SDL_SetRenderDrawColor(this->getRenderer(), c.R, c.G, c.B, A);
    SDL_RenderLine(this->gRenderer, start.x, start.y, finish.x, finish.y);
}

void Context::DrawLine(SDL_FPoint start, SDL_FPoint finish, string color)
{
    Color c = this->ColorsMap(color);
    SDL_SetRenderDrawColor(this->getRenderer(), c.R, c.G, c.B, 255);
    SDL_RenderLine(this->gRenderer, start.x, start.y, finish.x, finish.y);
}

void Context::DrawLine(SDL_FPoint start, SDL_FPoint finish)
{
    SDL_SetRenderDrawColor(this->getRenderer(), 0, 0, 0, 255);
    SDL_RenderLine(this->gRenderer, start.x, start.y, finish.x, finish.y);
}

void Context::DrawHendleFigure(SDL_FPoint arrPoints[], SDL_FPoint rotPoint, int length, float conor, string color)
{
    SDL_FPoint points[length];
    double rad = conor * (M_PI / 180);
    for (int i = 0; i < length; i++)
    {
        SDL_FPoint point = arrPoints[i];
        float deltaX = rotPoint.x - point.x;
        float deltaY = rotPoint.y - point.y;
        float delta = sqrt(deltaX * deltaX + deltaY * deltaY);
        float conorData = atan2(deltaY, deltaX);
        float x = rotPoint.x + cos(conorData + rad) * -delta;
        float y = rotPoint.y + sin(conorData + rad) * -delta;
        SDL_FPoint pointData = {x, y};
        points[i] = pointData;
    }

    for (int i = 0; i < length; i++)
    {
        SDL_FPoint point1 = points[i];
        SDL_FPoint point2 = i < length - 1 ? points[i + 1] : points[0];
        this->DrawLine(point1, point2, color);
    }
}

void Context::FillRect(float x, float y, float width, float height, int R, int G, int B, int A)
{
    SDL_SetRenderDrawBlendMode(this->getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(this->getRenderer(), R, G, B, A);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderFillRect(this->getRenderer(), &rect);
}

void Context::FillRect(float x, float y, float width, float height, int R, int G, int B)
{
    SDL_SetRenderDrawColor(this->getRenderer(), R, G, B, 255);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderFillRect(this->getRenderer(), &rect);
}

void Context::FillRect(float x, float y, float width, float height, std::string color)
{
    Color c = this->ColorsMap(color);
    SDL_SetRenderDrawColor(this->getRenderer(), c.R, c.G, c.B, 255);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderFillRect(this->getRenderer(), &rect);
}

void Context::FillRect(float x, float y, float width, float height)
{
    SDL_SetRenderDrawColor(this->getRenderer(), 0, 0, 0, 255);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderFillRect(this->getRenderer(), &rect);
}

void Context::FillRect(float x, float y, float width, float height, std::string color, int A)
{
    Color c = this->ColorsMap(color);
    SDL_SetRenderDrawBlendMode(this->getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(this->getRenderer(), c.R, c.G, c.B, A);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderFillRect(this->getRenderer(), &rect);
}

void Context::StrokeRect(float x, float y, float width, float height, int R, int G, int B, int A)
{
    SDL_SetRenderDrawBlendMode(this->getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(this->getRenderer(), R, G, B, A);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderRect(this->gRenderer, &rect);
}

void Context::StrokeRect(float x, float y, float width, float height, int R, int G, int B)
{
    SDL_SetRenderDrawColor(this->getRenderer(), R, G, B, 255);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderRect(this->gRenderer, &rect);
}

void Context::StrokeRect(float x, float y, float width, float height, std::string color, int A)
{
    Color c = this->ColorsMap(color);
    SDL_SetRenderDrawColor(this->getRenderer(), c.R, c.G, c.B, A);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderRect(this->gRenderer, &rect);
}

void Context::StrokeRect(float x, float y, float width, float height, std::string color)
{
    Color c = this->ColorsMap(color);
    SDL_SetRenderDrawColor(this->getRenderer(), c.R, c.G, c.B, 255);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderRect(this->gRenderer, &rect);
}

void Context::StrokeRect(float x, float y, float width, float height)
{
    SDL_SetRenderDrawColor(this->getRenderer(), 0, 0, 0, 255);
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderRect(this->gRenderer, &rect);
}

void Context::PixelHendler(Image *image,
                           int x,
                           int y,
                           int width,
                           int height,
                           function<void(Uint32 *pixelsArr, const SDL_PixelFormatDetails *pixelFormat)> fn)
{
    SDL_Rect rect{x, y, width, height};
    // void *mRawPixels;
    // int mRawPitch;
    SDL_LockTexture(image->mTexture, &rect, &this->mRawPixels, &this->mRawPitch);
    Uint32 *pixelsArr = (Uint32 *)this->mRawPixels;

    fn(pixelsArr, this->pixelFormat);

    SDL_UnlockTexture(image->mTexture);
    this->mRawPixels = NULL;
    this->mRawPitch = 0;
}

void Context::DrawImage(Image *image,
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
                        int B)
{
    SDL_FRect anim{animX, animY, animW, animH};
    SDL_FRect pos{x, y, width, height};
    SDL_FPoint center{rotX, rotY};

    SDL_SetTextureAlphaMod(image->mTexture, alpha);
    SDL_SetTextureColorMod(image->mTexture, R, G, B);
    SDL_RenderTextureRotated(this->gRenderer, image->mTexture, &anim, &pos, conor, &center, flip);
    SDL_SetTextureAlphaMod(image->mTexture, 255);
    SDL_SetTextureColorMod(image->mTexture, 255, 255, 255);
}

void Context::DrawImage(Image *image,
                        float animX,
                        float animY,
                        float animW,
                        float animH,
                        float x,
                        float y,
                        float width,
                        float height)
{
    SDL_FRect anim{animX, animY, animW, animH};
    SDL_FRect pos{x, y, width, height};

    SDL_RenderTextureRotated(this->gRenderer, image->mTexture, &anim, &pos, 0, NULL, SDL_FLIP_NONE);
}

void Context::DrawImage(Image *image,
                        float animX,
                        float animY,
                        float animW,
                        float animH,
                        float x,
                        float y,
                        float width,
                        float height,
                        SDL_FlipMode flip)
{
    SDL_FRect anim{animX, animY, animW, animH};
    SDL_FRect pos{x, y, width, height};

    SDL_RenderTextureRotated(this->gRenderer, image->mTexture, &anim, &pos, 0, NULL, flip);
}

void Context::DrawImage(Image *image,
                        float animX,
                        float animY,
                        float animW,
                        float animH,
                        float x,
                        float y,
                        float width,
                        float height,
                        SDL_FlipMode flip,
                        double conor)
{
    SDL_FRect anim{animX, animY, animW, animH};
    SDL_FRect pos{x, y, width, height};

    SDL_RenderTextureRotated(this->gRenderer, image->mTexture, &anim, &pos, conor, NULL, flip);
}

void Context::DrawImage(Image *image,
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
                        int alpha)
{
    SDL_FRect anim{animX, animY, animW, animH};
    SDL_FRect pos{x, y, width, height};

    SDL_SetTextureAlphaMod(image->mTexture, alpha);
    SDL_RenderTextureRotated(this->gRenderer, image->mTexture, &anim, &pos, conor, NULL, flip);
    SDL_SetTextureAlphaMod(image->mTexture, 255);
}

void Context::DrawImage(Image *image,
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
                        float rotY)
{
    SDL_FRect anim{animX, animY, animW, animH};
    SDL_FRect pos{x, y, width, height};
    SDL_FPoint center{rotX, rotY};

    SDL_SetTextureAlphaMod(image->mTexture, alpha);
    SDL_RenderTextureRotated(this->gRenderer, image->mTexture, &anim, &pos, conor, &center, flip);
    SDL_SetTextureAlphaMod(image->mTexture, 255);
}

Context::~Context()
{
    this->Close();
    printf(" here ");
    delete this->font;
    this->font = nullptr;
}

Context ctx(1024, 768);
// SDL_Renderer *Image::gRenderer = ctx.getRenderer();