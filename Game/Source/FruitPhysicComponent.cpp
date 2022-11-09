#include "FruitPhysicComponent.h"
#include "Body.h"
#include "GameObject.h"
#include "World.h"

void FruitPhysicComponent::Tick(GameObject& InObject, World& InWorld, float InDeltaSeconds)
{
	Body& ObjectBody = InObject.GetBody();

	Vec2f Position = ObjectBody.GetCenter();
	Position.y += InDeltaSeconds * ObjectBody.GetVelocity();

	float Rotate = ObjectBody.GetRotate();
	Rotate += InDeltaSeconds * ObjectBody.GetVelocity();

	ObjectBody.SetCenter(Position);
	ObjectBody.SetRotate(Rotate);
}
