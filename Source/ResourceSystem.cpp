#include "ResourceSystem.h"
#include "Texture.h"
#include "Font.h"

// @third party code - BEGIN SDL2
#include <SDL2/SDL.h>
// @third party code - END

ResourceSystem::ResourceSystem(SDL_Window* InWindow)
	: Window_(InWindow)
{
}

ResourceSystem::~ResourceSystem()
{
	for (auto& Resource : Textures_)
	{
		Resource.second.reset();
	}

	for (auto& Resource : Fonts_)
	{
		Resource.second.reset();
	}
}

Texture& ResourceSystem::LoadTextureFromFile(const std::size_t& InKey, const std::string& InPath)
{
	auto Iter = Textures_.find(InKey);
	CHECK((Iter == Textures_.end()), "hash key collision");

	std::unique_ptr<Texture> NewTexture = std::make_unique<Texture>(SDL_GetRenderer(Window_), InPath);
	Textures_.insert({ InKey, std::move(NewTexture) });

	return *Textures_.at(InKey);
}

Texture& ResourceSystem::GetTexture(const std::size_t& InKey)
{
	auto Iter = Textures_.find(InKey);
	CHECK((Iter != Textures_.end()), "don't exist hash key");

	return *Textures_.at(InKey);
}

Font& ResourceSystem::LoadFontFromFile(const std::size_t& InKey, const std::string& InPath, int32_t InBeginCodePoint, int32_t InEndCodePoint, const int32_t InSize)
{
	auto Iter = Fonts_.find(InKey);
	CHECK((Iter == Fonts_.end()), "hash key collision");

	std::unique_ptr<Font> NewFont = std::make_unique<Font>(SDL_GetRenderer(Window_), InPath, InBeginCodePoint, InEndCodePoint, InSize);
	Fonts_.insert({ InKey, std::move(NewFont) });

	return *Fonts_.at(InKey);
}

Font& ResourceSystem::GetFont(const std::size_t& InKey)
{
	auto Iter = Fonts_.find(InKey);
	CHECK((Iter != Fonts_.end()), "don't exist hash key");

	return *Fonts_.at(InKey);
}
