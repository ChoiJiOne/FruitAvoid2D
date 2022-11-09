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

	InGraphics.DrawTexture2D(
		ContentUtils::GetTexture(SpriteKey_),
		Position,
		static_cast<int32_t>(ObjectBody.GetWidth()),
		static_cast<int32_t>(ObjectBody.GetHeight()),
		bIsRotate_ ? ObjectBody.GetRotate() : 0.0f
	);
}
