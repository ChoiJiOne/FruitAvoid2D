#include "Fruit.h"
#include "Body.h"
#include "ContentUtils.h"
#include "MathUtils.h"
#include "Text.h"
#include "Input.h"
#include "Graphics.h"
#include "World.h"
#include "FruitPhysicComponent.h"
#include "SpriteComponent.h"

std::unordered_map<Fruit::EType, std::size_t> Fruit::FruitTextureKeys_ = {
	{ Fruit::EType::Banana,          Text::GetHash("Banana")          },
	{ Fruit::EType::BlackBerryDark,  Text::GetHash("BlackBerryDark")  },
	{ Fruit::EType::BlackBerryLight, Text::GetHash("BlackBerryLight") },
	{ Fruit::EType::BlackCherry,     Text::GetHash("BlackCherry")     },
	{ Fruit::EType::Coconut,         Text::GetHash("Coconut")         },
	{ Fruit::EType::GreenApple,      Text::GetHash("GreenApple")      },
	{ Fruit::EType::GreenGrape,      Text::GetHash("GreenGrape")      },
	{ Fruit::EType::Lemon,           Text::GetHash("Lemon")           },
	{ Fruit::EType::Lime,            Text::GetHash("Lime")            },
	{ Fruit::EType::Orange,          Text::GetHash("Orange")          },
	{ Fruit::EType::Peach,           Text::GetHash("Peach")           },
	{ Fruit::EType::Pear,            Text::GetHash("Pear")            },
	{ Fruit::EType::Plum,            Text::GetHash("Plum")            },
	{ Fruit::EType::Raspberry,       Text::GetHash("Raspberry")       },
	{ Fruit::EType::RedApple,        Text::GetHash("RedApple")        },
	{ Fruit::EType::RedCherry,       Text::GetHash("RedCherry")       },
	{ Fruit::EType::RedGrape,        Text::GetHash("RedGrape")        },
	{ Fruit::EType::StarFruit,       Text::GetHash("StarFruit")       },
	{ Fruit::EType::Strawberry,      Text::GetHash("Strawberry")      },
	{ Fruit::EType::WaterMelon,      Text::GetHash("WaterMelon")      }
};

Fruit::Fruit(World* InWorld,
	const Vec2f& InPosition,
	const float& InWidth,
	const float& InHeight,
	const float& InVelocity,
	const EType& InType
) : GameObject(InWorld)
{
	Body_ = std::make_unique<Body>(InPosition, InWidth, InHeight, 0.0f, InVelocity);
	Type_ = InType;

	Physic_ = std::make_unique<FruitPhysicComponent>();
	Graphics_ = std::make_unique<SpriteComponent>(FruitTextureKeys_[Type_]);
}

Fruit::~Fruit()
{
}

void Fruit::Update(Input& InInput, float InDeltaSeconds)
{
	Physic_->Tick(*this, *World_, InDeltaSeconds);
}

void Fruit::Render(Graphics& InGraphics)
{
	Graphics_->Tick(*this, InGraphics);
}