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
	: BoundingBox(InPosition, InWidth, InHeight, 0.0f)
	, Speed_(InSpeed)
	, Color_(InColor)
{
}

Player::Player(Player&& InInstance) noexcept
	: BoundingBox(InInstance)
	, Speed_(InInstance.Speed_)
	, Color_(InInstance.Color_)
{
}

Player::Player(const Player& InInstance) noexcept
	: BoundingBox(InInstance)
	, Speed_(InInstance.Speed_)
	, Color_(InInstance.Color_)
{
}

Player::~Player()
{
}

Player& Player::operator=(Player&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	BoundingBox::operator=(InInstance);

	Speed_ = InInstance.Speed_;
	Color_ = InInstance.Color_;

	return *this;
}

Player& Player::operator=(const Player& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	BoundingBox::operator=(InInstance);

	Speed_ = InInstance.Speed_;
	Color_ = InInstance.Color_;

	return *this;
}

void Player::Update(InputSystem& InInput, float InDeltaTime)
{
	Vec2i Position = BoundingBox::GetCenter();

	if (InInput.GetKeyboardState().GetKeyPressState(SDL_SCANCODE_LEFT) == EPressState::Held)
	{
		Position.x -= static_cast<int32_t>(InDeltaTime * Speed_);
	}

	if (InInput.GetKeyboardState().GetKeyPressState(SDL_SCANCODE_RIGHT) == EPressState::Held)
	{
		Position.x += static_cast<int32_t>(InDeltaTime * Speed_);
	}

	int32_t ScreenWidth = 0;
	int32_t ScreenHeight = 0;
	GameEngine::GetWindowSystem().GetSize(ScreenWidth, ScreenHeight);

	if (Position.x < 0)
	{
		Position.x = ScreenWidth;
	}

	if (Position.x > ScreenWidth)
	{
		Position.x = 0;
	}

	BoundingBox::SetCenter(Position);
	BoundingBox::UpdateBoundingPositions();
}

void Player::Render(RenderSystem& InRenderer)
{
	ResourceSystem& Resource = GameEngine::GetResourceSystem();

	Texture& PlayerTexture = Resource.GetTexture(ColorTextureKeys_.at(Color_));
	InRenderer.DrawTexture2D(
		PlayerTexture, 
		BoundingBox::GetCenter(),
		BoundingBox::GetWidth(),
		BoundingBox::GetHeight()
	);
}