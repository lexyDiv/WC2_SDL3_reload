#include "in.h"

// => Image.cpp

SDL_Renderer *renderer = nullptr;

class Image
{
public:
    SDL_Texture *mTexture;
    SDL_Renderer *gRenderer = renderer;


    // Initializes variables
    Image(std::string path);
    Image(int width, int height);

    // Deallocates memory
    ~Image();

    // Loads image at specified path
    bool loadFromFile(std::string path, SDL_Renderer *gRenderer);

    // Deallocates texture
    void free();

    // Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    // Set blending
    void setBlendMode(SDL_BlendMode blending);

    // Set alpha modulation
    void setAlpha(Uint8 alpha);

    // Renders texture at given point
    void render(float x, float y, SDL_FRect *clip = NULL, double angle = 0.0f, SDL_FPoint *center = NULL, SDL_FlipMode flip = SDL_FLIP_NONE);

    // Gets image dimensions
    int getWidth();
    int getHeight();

private:
    // The actual hardware texture

    // Image dimensions
    float mWidth;
    float mHeight;
};
