#include "ContentUtils.h"
#include "CommandLineUtils.h"
#include "Texture.h"
#include "Font.h"

std::string ContentUtils::ContentPath_;
std::unordered_map<std::size_t, std::unique_ptr<Texture>> ContentUtils::Textures_;
std::unordered_map<std::size_t, std::unique_ptr<Font>> ContentUtils::Fonts_;
std::unordered_map<std::size_t, json> ContentUtils::Jsons_;

void ContentUtils::Init()
{
	ContentPath_ = CommandLineUtils::GetValue("-Content");
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

Texture& ContentUtils::AddTexture(const std::size_t& InKey, Graphics& InGraphics, const std::string& InPath)
{
	CHECK(!HaveTexture(InKey), "already load texture resource");

	std::unique_ptr<Texture> NewTexture = std::make_unique<Texture>(InGraphics, ContentPath_ + InPath);
	Textures_.insert({ InKey, std::move(NewTexture) });

	return *Textures_.at(InKey);
}

void ContentUtils::RemoveTexture(const std::size_t& InKey)
{
	if (!HaveTexture(InKey)) return;
	Textures_.erase(InKey);
}

bool ContentUtils::HaveTexture(const std::size_t& InKey)
{
	return Textures_.find(InKey) != Textures_.end();
}

Texture& ContentUtils::GetTexture(const std::size_t& InKey)
{
	CHECK(HaveTexture(InKey), "can't find texture resource");
	return *Textures_.at(InKey);
}
