#include "Fruit.h"
#include "ContentUtils.h"
#include "MathUtils.h"
#include "Text.h"
#include "Input.h"
#include "Graphics.h"

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

Fruit::Fruit(const Vec2i& InPosition, const float& InSpeed, const int32_t& InWidth, const int32_t& InHeight, const EType& InType)
{
	Position_ = InPosition;
	Speed_ = InSpeed;
	Width_ = InWidth;
	Height_ = InHeight;
	Type_ = InType;
}

Fruit::Fruit(Fruit&& InInstance) noexcept
{
	Position_ = InInstance.Position_;
	Speed_ = InInstance.Speed_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Type_ = InInstance.Type_;
}

Fruit::Fruit(const Fruit& InInstance) noexcept
{
	Position_ = InInstance.Position_;
	Speed_ = InInstance.Speed_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Type_ = InInstance.Type_;
}

Fruit::~Fruit()
{
}

Fruit& Fruit::operator=(Fruit&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Position_ = InInstance.Position_;
	Speed_ = InInstance.Speed_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Type_ = InInstance.Type_;

	return *this;
}

Fruit& Fruit::operator=(const Fruit& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Position_ = InInstance.Position_;
	Speed_ = InInstance.Speed_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Type_ = InInstance.Type_;

	return *this;
}

void Fruit::Update(Input& InInput, float InDeltaSeconds)
{
	Position_.y += static_cast<int32_t>(InDeltaSeconds * Speed_);
}

void Fruit::Render(Graphics& InGraphics)
{
	Texture& FruitTexture = ContentUtils::GetTexture(FruitTextureKeys_[Type_]);
	InGraphics.DrawTexture2D(FruitTexture, Position_, Width_, Height_);
}

Fruit Fruit::GenerateRandomFruit(const int32_t& InYPosition)
{
	static float FruitSpeeds[] = {
		   200.0f,
		   250.0f,
		   300.0f,
		   350.0f,
		   400.0f,
		   450.0f,
		   500.0f,
	};

	static int32_t FruitSizes[] = {
		50,
		60,
		70
	};

	static EType FruitTypes[] = {
		Fruit::EType::Banana,
		Fruit::EType::BlackBerryDark,
		Fruit::EType::BlackBerryLight,
		Fruit::EType::BlackCherry,
		Fruit::EType::Coconut,
		Fruit::EType::GreenApple,
		Fruit::EType::GreenGrape,
		Fruit::EType::Lemon,
		Fruit::EType::Lime,
		Fruit::EType::Orange,
		Fruit::EType::Peach,
		Fruit::EType::Pear,
		Fruit::EType::Plum,
		Fruit::EType::Raspberry,
		Fruit::EType::RedApple,
		Fruit::EType::RedCherry,
		Fruit::EType::RedGrape,
		Fruit::EType::StarFruit,
		Fruit::EType::Strawberry,
		Fruit::EType::WaterMelon
	};

	int32_t ScreenWidth = 1000;
	int32_t ScreenHeight = 800;

	int32_t FruitSize = FruitSizes[MathUtils::GenerateRandomInt<int32_t>(0, std::size(FruitSizes) - 1)];

	return Fruit(
		Vec2i(MathUtils::GenerateRandomInt<int32_t>(0, ScreenWidth), InYPosition),
		FruitSpeeds[MathUtils::GenerateRandomInt<int32_t>(0, std::size(FruitSpeeds) - 1)],
		FruitSize,
		FruitSize,
		FruitTypes[MathUtils::GenerateRandomInt<int32_t>(0, std::size(FruitTypes) - 1)]
	);
}
