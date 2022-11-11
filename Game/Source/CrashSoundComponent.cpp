#include "CrashSoundComponent.h"
#include "PlayerPhysicComponent.h"
#include "ContentUtils.h"
#include "GameObject.h"
#include "World.h"
#include "Sound.h"

void CrashSoundComponent::Tick(GameObject& InObject)
{
	int32_t CountOfCollision = Physic_->GetCountOfCollision();

	while (CountOfCollision > 0)
	{
		ContentUtils::GetSound(SoundKey_).Play();
		CountOfCollision--;
	}
}
