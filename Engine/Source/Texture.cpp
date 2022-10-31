#include "Texture.h"
#include "Graphics2D.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// @third party code - END

Texture::Texture(Graphics2D& InGraphics, const std::string& InPath)
{
	Texture_ = LoadTextureFromFile(InGraphics, InPath);
	CHECK((Texture_ != nullptr), "failed to create texture resource");
}

Texture::~Texture()
{
	if (Texture_)
	{
		SDL_DestroyTexture(Texture_);
		Texture_ = nullptr;
	}
}

SDL_Texture* Texture::LoadTextureFromFile(Graphics2D& InGraphics, const std::string& InPath)
{
	SDL_Surface* Surface = IMG_Load(InPath.c_str());
	SDL_Texture* NewTexture = SDL_CreateTextureFromSurface(InGraphics.GetRenderer(), Surface);

	SDL_FreeSurface(Surface);
	Surface = nullptr;

	return NewTexture;
}
