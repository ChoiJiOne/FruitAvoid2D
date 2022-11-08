#include "GameObject.h"
#include "Body.h"
#include "InputComponent.h"
#include "GraphicsComponent.h"
#include "PhysicComponent.h"
#include "World.h"

GameObject::GameObject(World* InWorld)
{
	World_ = InWorld;
	World_->AddOjbect(this);
}

GameObject::~GameObject()
{
	if (Body_) Body_.reset();
	if (Input_) Input_.reset();
	if (Physic_) Physic_.reset();
	if (Graphics_) Graphics_.reset();

	World_->RemoveObject(this);
}