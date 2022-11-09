#include "PlayerPhysicComponent.h"
#include "Body.h"
#include "GameObject.h"
#include "MathUtils.h"
#include "World.h"

void PlayerPhysicComponent::Tick(GameObject& InObject, World& InWorld, float InDeltaSeconds)
{
	Body& ObjectBody = InObject.GetBody();

	if (ObjectBody.CanMove())
	{
		Vec2f Position = ObjectBody.GetCenter();

		Position.x += InDeltaSeconds * ObjectBody.GetVelocity() * static_cast<float>(cos(MathUtils::ToRadian(ObjectBody.GetRotate())));
		Position.x = MathUtils::Clamp<float>(Position.x, 0.0f, static_cast<float>(InWorld.GetWidth()));

		ObjectBody.SetCenter(Position);
	}
}
