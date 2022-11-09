#include "PlayerInputComponent.h"
#include "GameObject.h"
#include "Body.h"
#include "Input.h"

void PlayerInputComponent::Tick(GameObject& InObject, Input& InInput)
{
	float Rotate = InObject.GetBody().GetRotate();

	if (InInput.GetKeyPressState(EScanCode::CODE_LEFT) == EPressState::PRESSED)
	{
		Rotate = 180.0f;
	}

	if (InInput.GetKeyPressState(EScanCode::CODE_RIGHT) == EPressState::PRESSED)
	{
		Rotate = 0.0f;
	}

	InObject.GetBody().SetRotate(Rotate);
	

	if (InInput.GetKeyPressState(EScanCode::CODE_LEFT) == EPressState::HELD || 
		InInput.GetKeyPressState(EScanCode::CODE_RIGHT) == EPressState::HELD)
	{
		InObject.GetBody().SetCanMove(true);
	}
	else
	{
		InObject.GetBody().SetCanMove(false);
	}
}
