#include "SpriteComponent.h"
#include "Body.h"
#include "ContentUtils.h"
#include "GraphicsComponent.h"
#include "Graphics.h"
#include "GameObject.h"

void SpriteComponent::Tick(GameObject& InObject, Graphics& InGraphics)
{
	const Body& ObjectBody = InObject.GetBody();

	Vec2i Position(
		static_cast<int32_t>(ObjectBody.GetCenter().x + 0.5f),
		static_cast<int32_t>(ObjectBody.GetCenter().y + 0.5f)
	);

	const std::array<Vec2f, 4>& Positions = ObjectBody.GetBoundingPositions();

	InGraphics.DrawLine2D(
		Vec2i(static_cast<int32_t>(Positions[0].x + 0.5f), static_cast<int32_t>(Positions[0].y + 0.5f)),
		Vec2i(static_cast<int32_t>(Positions[1].x + 0.5f), static_cast<int32_t>(Positions[1].y + 0.5f)),
		ColorUtils::Black
	);

	InGraphics.DrawLine2D(
		Vec2i(static_cast<int32_t>(Positions[1].x + 0.5f), static_cast<int32_t>(Positions[1].y + 0.5f)),
		Vec2i(static_cast<int32_t>(Positions[3].x + 0.5f), static_cast<int32_t>(Positions[3].y + 0.5f)),
		ColorUtils::Black
	);

	InGraphics.DrawLine2D(
		Vec2i(static_cast<int32_t>(Positions[3].x + 0.5f), static_cast<int32_t>(Positions[3].y + 0.5f)),
		Vec2i(static_cast<int32_t>(Positions[2].x + 0.5f), static_cast<int32_t>(Positions[2].y + 0.5f)),
		ColorUtils::Black
	);

	InGraphics.DrawLine2D(
		Vec2i(static_cast<int32_t>(Positions[2].x + 0.5f), static_cast<int32_t>(Positions[2].y + 0.5f)),
		Vec2i(static_cast<int32_t>(Positions[0].x + 0.5f), static_cast<int32_t>(Positions[0].y + 0.5f)),
		ColorUtils::Black
	);

	InGraphics.DrawTexture2D(
		ContentUtils::GetTexture(SpriteKey_),
		Position,
		static_cast<int32_t>(ObjectBody.GetWidth()),
		static_cast<int32_t>(ObjectBody.GetHeight()),
		bIsRotate_ ? ObjectBody.GetRotate() : 0.0f
	);
}
