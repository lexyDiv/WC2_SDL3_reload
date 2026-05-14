#include "Image.h"

// => Image out

Image::Image(std::string path)
{
	// Initialize
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
	bool isLoad = this->loadFromFile(path, gRenderer);
	if (!isLoad) {
		printf("Unable to Load FILE ! SDL Error: \n");
	}
}

Image::Image(int width, int height)
{
	this->mTexture = SDL_CreateTexture(this->gRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	if (this->mTexture == NULL)
	{
		printf("Unable to create streamable blank texture! SDL Error: \n");
	}
}

Image::~Image()
{
	// Deallocate
	free();
}

bool Image::loadFromFile(std::string path, SDL_Renderer *gRenderer)
{
	// Get rid of preexisting texture
	free();

	// The final texture
	this->mTexture = IMG_LoadTexture(gRenderer, path.c_str());
	this->mWidth = this->mTexture->w;
	this->mHeight = this->mTexture->h;

	// // Load image at specified path
	// SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	// if (loadedSurface == nullptr)
	// {
	// 	printf("Unable to load image ! SDL_image Error: \n");
	// }
	// else
	// {
	// 	// Color key image
    //     const SDL_PixelFormatDetails *pfd = SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_RGBA8888);
	// 	SDL_SetSurfaceColorKey(loadedSurface, true, SDL_MapRGB(pfd, nullptr, 0xFF, 0xFF, 0xFF));

	// 	// Create texture from surface pixels
	// 	newTexture = SDL_CreateTextureFromSurface(this->gRenderer, loadedSurface);
	// 	if (newTexture == NULL)
	// 	{
	// 		printf("Unable to create texture from ! SDL Error: \n");
	// 	}
	// 	else
	// 	{
	// 		// Get image dimensions
	// 		mWidth = loadedSurface->w;
	// 		mHeight = loadedSurface->h;
	// 	}

	// 	// Get rid of old loaded surface
	// 	SDL_DestroySurface(loadedSurface);
	// }

	// Return success
	
	return mTexture != nullptr;
}

void Image::free()
{
	// Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Image::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	// Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Image::setBlendMode(SDL_BlendMode blending)
{
	// Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void Image::setAlpha(Uint8 alpha)
{
	// Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Image::render(float x, float y, SDL_FRect *clip, double angle, SDL_FPoint *center, SDL_FlipMode flip)
{
	// Set rendering space and render to screen
	SDL_FRect renderQuad = {x, y, mWidth, mHeight};

	// Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	// Render to screen
	SDL_RenderTextureRotated(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int Image::getWidth()
{
	return mWidth;
}

int Image::getHeight()
{
	return mHeight;
}