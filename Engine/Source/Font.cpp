#include "Font.h"

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
