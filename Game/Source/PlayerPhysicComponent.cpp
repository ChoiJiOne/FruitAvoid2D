#include "PlayerPhysicComponent.h"
#include "Body.h"
#include "GameObject.h"
#include "World.h"

void PlayerPhysicComponent::Tick(GameObject& InObject, World& InWorld, float InDeltaSeconds)
{
	Body& ObjectBody = InObject.GetBody();
	Vec2f Position = ObjectBody.GetCenter();

	Position.x += InDeltaSeconds * ObjectBody.GetVelocity() * static_cast<float>(cos(ObjectBody.GetRotate()));

	ObjectBody.SetCenter(Position);
}
