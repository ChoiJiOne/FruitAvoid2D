#include "Player.h"
#include "Body.h"
#include "ContentUtils.h"
#include "Input.h"
#include "Graphics.h"
#include "Texture.h"
#include "Text.h"
#include "MathUtils.h"
#include "World.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicComponent.h"
#include "SpriteComponent.h"

std::unordered_map<Player::EColor, std::size_t> Player::ColorTextureKeys_ = {
	{ Player::EColor::Blue,   Text::GetHash("PlayerBlockBlue")   },
	{ Player::EColor::Green,  Text::GetHash("PlayerBlockGreen")  },
	{ Player::EColor::Orange, Text::GetHash("PlayerBlockOrange") },
	{ Player::EColor::Purple, Text::GetHash("PlayerBlockPurple") },
	{ Player::EColor::Red,    Text::GetHash("PlayerBlockRed")    },
	{ Player::EColor::Sky,    Text::GetHash("PlayerBlockSky")    },
	{ Player::EColor::Yellow, Text::GetHash("PlayerBlockYellow") }
};

Player::Player(
	World* InWorld,
	const Vec2f& InPosition,
	const float& InWidth,
	const float& InHeight,
	const float& InVelocity,
	const EColor& InColor
) : GameObject(InWorld)
{
	Body_ = std::make_unique<Body>(InPosition, InWidth, InHeight, 0.0f, InVelocity);
	Color_ = InColor;

	Input_ = std::make_unique<PlayerInputComponent>();
	Physic_ = std::make_unique<PlayerPhysicComponent>();
	Graphics_ = std::make_unique<SpriteComponent>(ColorTextureKeys_[Color_]);
}

Player::~Player()
{
}

void Player::Update(Input& InInput, float InDeltaSeconds)
{
	Input_->Tick(*this, InInput);
	Physic_->Tick(*this, *World_, InDeltaSeconds);
}

void Player::Render(Graphics& InGraphics)
{
	Graphics_->Tick(*this, InGraphics);
}