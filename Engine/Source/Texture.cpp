#include "Texture.h"
#include "Graphics2D.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// @third party code - END

Texture::Texture(Graphics2D& InGraphics, const std::string& InPath)
{
	Texture_ = CreateTextureFromFile(InGraphics, InPath);
	CHECK((Texture_ != nullptr), "failed to create texture resource");
}

Texture::Texture(Graphics2D& InGraphics, SDL_Surface* InSurface)
{
	CHECK((InSurface != nullptr), "invalid constructor parameter");

	Texture_ = CreateTextureFromSurface(InGraphics, InSurface);
	CHECK((Texture_ != nullptr), "failed to create texture resource");
}

Texture::Texture(SDL_Texture* InTexture)
{
	CHECK((InTexture != nullptr), "invalid constructor parameter");
	Texture_ = InTexture;
}

Texture::~Texture()
{
	if (Texture_)
	{
		SDL_DestroyTexture(Texture_);
		Texture_ = nullptr;
	}
}

void Texture::GetSize(int32_t& OutWidth, int32_t& OutHeight)
{
	CHECK((SDL_QueryTexture(Texture_, nullptr, nullptr, &OutWidth, &OutHeight) == 0), "failed to query texture size")
}

SDL_Texture* Texture::CreateTextureFromFile(Graphics2D& InGraphics, const std::string& InPath)
{
	SDL_Surface* Surface = IMG_Load(InPath.c_str());
	SDL_Texture* NewTexture = CreateTextureFromSurface(InGraphics, Surface);

	SDL_FreeSurface(Surface);
	Surface = nullptr;

	return NewTexture;
}

SDL_Texture* Texture::CreateTextureFromSurface(Graphics2D& InGraphics, SDL_Surface* InSurface)
{
	return SDL_CreateTextureFromSurface(InGraphics.GetRenderer(), InSurface);
}
