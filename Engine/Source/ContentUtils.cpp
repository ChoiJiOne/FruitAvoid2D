#include "ContentUtils.h"
#include "Texture.h"
#include "Font.h"

std::unordered_map<std::size_t, std::unique_ptr<Texture>> ContentUtils::Textures_;
std::unordered_map<std::size_t, std::unique_ptr<Font>> ContentUtils::Fonts_;
std::unordered_map<std::size_t, json> ContentUtils::Jsons_;

void ContentUtils::Init()
{
}

void ContentUtils::Quit()
{
	for (auto& texture : Textures_)
	{
		texture.second.reset();
	}

	for (auto& font : Fonts_)
	{
		font.second.reset();
	}
}
