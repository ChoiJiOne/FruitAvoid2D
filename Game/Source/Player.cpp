#include "Player.h"
#include "GameEngine.h"

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
	: Position_(InPosition)
	, Speed_(InSpeed)
	, Width_(InWidth)
	, Height_(InHeight)
	, Color_(InColor)
{
}

Player::Player(Player&& InInstance) noexcept
	: Position_(InInstance.Position_)
	, Speed_(InInstance.Speed_)
	, Width_(InInstance.Width_)
	, Height_(InInstance.Height_)
	, Color_(InInstance.Color_)
{
}

Player::Player(const Player& InInstance) noexcept
	: Position_(InInstance.Position_)
	, Speed_(InInstance.Speed_)
	, Width_(InInstance.Width_)
	, Height_(InInstance.Height_)
	, Color_(InInstance.Color_)
{
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

void Player::Update(const InputSystem& InInput, float InDeltaTime)
{
	if (InInput.GetKeyboardState().GetKeyPressState(SDL_SCANCODE_LEFT) == EPressState::Held)
	{
		Position_.x -= static_cast<int32_t>(InDeltaTime * Speed_);
	}

	if (InInput.GetKeyboardState().GetKeyPressState(SDL_SCANCODE_RIGHT) == EPressState::Held)
	{
		Position_.x += static_cast<int32_t>(InDeltaTime * Speed_);
	}

	int32_t ScreenWidth = 0;
	int32_t ScreenHeight = 0;
	GameEngine::GetWindowSystem().GetSize(ScreenWidth, ScreenHeight);

	if (Position_.x < 0)
	{
		Position_.x = ScreenWidth;
	}

	if (Position_.x > ScreenWidth)
	{
		Position_.x = 0;
	}
}

void Player::Render(const RenderSystem& InRenderer)
{
	ResourceSystem& Resource = GameEngine::GetResourceSystem();
	RenderSystem& Renderer = GameEngine::GetRenderSystem();

	Texture& PlayerTexture = Resource.GetTexture(ColorTextureKeys_.at(Color_));
	Renderer.DrawTexture2D(PlayerTexture, Position_, Width_, Height_);
}