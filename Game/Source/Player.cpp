#include "Player.h"
#include "ContentUtils.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Text.h"

std::unordered_map<Player::EColor, std::size_t> Player::ColorTextureKeys_ = {
	{ Player::EColor::Blue,   Text::GetHash("PlayerBlockBlue")   },
	{ Player::EColor::Green,  Text::GetHash("PlayerBlockGreen")  },
	{ Player::EColor::Orange, Text::GetHash("PlayerBlockOrange") },
	{ Player::EColor::Purple, Text::GetHash("PlayerBlockPurple") },
	{ Player::EColor::Red,    Text::GetHash("PlayerBlockRed")    },
	{ Player::EColor::Sky,    Text::GetHash("PlayerBlockSky")    },
	{ Player::EColor::Yellow, Text::GetHash("PlayerBlockYellow") }
};

Player::Player(const Vec2i& InPosition, const float& InSpeed, const int32_t& InWidth, const int32_t& InHeight, const EColor& InColor)
{
	Position_ = InPosition;
	Speed_ = InSpeed;
	Width_ = InWidth;
	Height_ = InHeight;
	Color_ = InColor;
}

Player::Player(Player&& InInstance) noexcept
{
	Position_ = InInstance.Position_;
	Speed_ = InInstance.Speed_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Color_ = InInstance.Color_;
}

Player::Player(const Player& InInstance) noexcept
{
	Position_ = InInstance.Position_;
	Speed_ = InInstance.Speed_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Color_ = InInstance.Color_;
}

Player::~Player()
{
}

Player& Player::operator=(Player&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Position_ = InInstance.Position_;
	Speed_ = InInstance.Speed_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Color_ = InInstance.Color_;

	return *this;
}

Player& Player::operator=(const Player& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Position_ = InInstance.Position_;
	Speed_ = InInstance.Speed_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Color_ = InInstance.Color_;

	return *this;
}

void Player::Update(Input& InInput, float InDeltaSeconds)
{
	if (InInput.GetKeyPressState(EScanCode::CODE_LEFT) == EPressState::HELD)
	{
		Position_.x -= static_cast<int32_t>(InDeltaSeconds * Speed_);
	}

	if (InInput.GetKeyPressState(EScanCode::CODE_RIGHT) == EPressState::HELD)
	{
		Position_.x += static_cast<int32_t>(InDeltaSeconds * Speed_);
	}
}

void Player::Render(Graphics& InGraphics)
{
	Texture& PlayerTexture = ContentUtils::GetTexture(ColorTextureKeys_[Color_]);
	InGraphics.DrawTexture2D(PlayerTexture, Position_, Width_, Height_);
}