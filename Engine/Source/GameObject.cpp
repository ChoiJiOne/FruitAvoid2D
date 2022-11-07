#include "GameObject.h"
#include "World.h"

GameObject::GameObject(World* InWorld)
{
	World_ = InWorld;
	World_->AddOjbect(this);
}

GameObject::GameObject(GameObject&& InInstance)
{
	World_ = InInstance.World_;
	bIsVisible_ = InInstance.bIsVisible_;
	Position_ = InInstance.Position_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
}

GameObject::GameObject(const GameObject& InInstance)
{
	World_ = InInstance.World_;
	bIsVisible_ = InInstance.bIsVisible_;
	Position_ = InInstance.Position_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
}

GameObject::~GameObject()
{
	World_->RemoveObject(this);
}

GameObject& GameObject::operator=(GameObject&& InInstance)
{
	if (this == &InInstance) return *this;

	World_ = InInstance.World_;
	bIsVisible_ = InInstance.bIsVisible_;
	Position_ = InInstance.Position_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;

	return *this;
}

GameObject& GameObject::operator=(const GameObject& InInstance)
{
	if (this == &InInstance) return *this;

	World_ = InInstance.World_;
	bIsVisible_ = InInstance.bIsVisible_;
	Position_ = InInstance.Position_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;

	return *this;
}
