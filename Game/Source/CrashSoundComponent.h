#pragma once

#include "Vector.h"
#include "SoundComponent.h"
#include "PlayerPhysicComponent.h"


/**
 * 플레이어와 과일이 충돌했을 때 처리할 사운드 컴포넌트입니다.
 */
class CrashSoundComponent : public SoundComponent
{
public:
	/**
	 * 플레이어와 과일이 충돌했을 때 처리할 사운드 컴포넌트의 생성자입니다.
	 * 
	 * @param InSoundKey - 충돌 사운드의 키 값입니다.
	 */
	CrashSoundComponent(PlayerPhysicComponent* InPhysic, const std::size_t& InSoundKey)
	{
		Physic_ = InPhysic;
		SoundKey_ = InSoundKey;
	}


	/**
	 * 플레이어와 과일이 충돌했을 때 처리할 사운드 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~CrashSoundComponent() {}


	/**
	 * 플레이어와 과일이 충돌했을 떄 처리할 사운드 컴포넌트를 업데이트합니다.
	 * 
	 * @param InObject - 사운드 처리를 수행할 게임 오브젝트입니다.
	 */
	virtual void Tick(GameObject& InObject) override;


private:
	/**
	 * 사운드 리소스의 키 값입니다.
	 */
	std::size_t SoundKey_ = 0;


	/**
	 * 플레이어의 충돌 처리 컴포넌트입니다.
	 */
	PlayerPhysicComponent* Physic_ = nullptr;
};