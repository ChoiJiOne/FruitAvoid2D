#include "Font.h"
#include "Texture.h"
#include "Graphics2D.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
// @third party code - END

Font::Font(const std::string& InPath, const int32_t& InSize)
	: Size_(InSize)
{
	Font_ = TTF_OpenFont(InPath.c_str(), Size_);
	CHECK((Font_ != nullptr), "failed to create font resource");
}

Font::~Font()
{
	if (Font_)
	{
		TTF_CloseFont(Font_);
		Font_ = nullptr;
	}
}

SDL_Surface* Font::CreateTextSurface(Graphics2D& InGraphics, const std::string& InText, const LinearColor& InColor)
{
	SDL_Color TextColor;
	Color::ToR8G8B8A8(InColor, TextColor.r, TextColor.g, TextColor.b, TextColor.a);

	return TTF_RenderText_Solid(Font_, InText.c_str(), TextColor);
}

SDL_Surface* Font::CreateTextSurface(Graphics2D& InGraphics, const std::wstring& InText, const LinearColor& InColor)
{
	SDL_Color TextColor;
	Color::ToR8G8B8A8(InColor, TextColor.r, TextColor.g, TextColor.b, TextColor.a);

	return TTF_RenderUNICODE_Solid(Font_, reinterpret_cast<const uint16_t*>(InText.c_str()), TextColor);
}

SDL_Texture* Font::CreateTextTexture(Graphics2D& InGraphics, const std::string& InText, const LinearColor& InColor)
{
	SDL_Surface* TextSurface = CreateTextSurface(InGraphics, InText, InColor);
	SDL_Texture* TextTexture = Texture::CreateTextureFromSurface(InGraphics, TextSurface);

	SDL_FreeSurface(TextSurface);
	TextSurface = nullptr;

	return TextTexture;
}

SDL_Texture* Font::CreateTextTexture(Graphics2D& InGraphics, const std::wstring& InText, const LinearColor& InColor)
{
	SDL_Surface* TextSurface = CreateTextSurface(InGraphics, InText, InColor);
	SDL_Texture* TextTexture = Texture::CreateTextureFromSurface(InGraphics, TextSurface);

	SDL_FreeSurface(TextSurface);
	TextSurface = nullptr;

	return TextTexture;
}
