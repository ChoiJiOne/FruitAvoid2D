#include "PlayerPhysicComponent.h"
#include "Body.h"
#include "GameObject.h"
#include "MathUtils.h"
#include "World.h"

void PlayerPhysicComponent::Tick(GameObject& InObject, World& InWorld, float InDeltaSeconds)
{
	Body& ObjectBody = InObject.GetBody();
	CountOfColllision_ = 0;

	if (ObjectBody.CanMove())
	{
		Vec2f Position = ObjectBody.GetCenter();

		Position.x += InDeltaSeconds * ObjectBody.GetVelocity() * static_cast<float>(cos(MathUtils::ToRadian(ObjectBody.GetRotate())));
		Position.x = MathUtils::Clamp<float>(Position.x, 0.0f, static_cast<float>(InWorld.GetWidth()));

		ObjectBody.SetCenter(Position);
	}

	const std::list<GameObject*> Objects = InWorld.GetAllObject();
	for (auto& Object : Objects)
	{
		if (Object == &InObject) continue;
		
		if (ObjectBody.IsCollision(Object->GetBody()))
		{
			CountOfColllision_++;
		}
	}
}
