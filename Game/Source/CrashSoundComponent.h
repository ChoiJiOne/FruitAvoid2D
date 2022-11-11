#pragma once

#include "Vector.h"
#include "SoundComponent.h"
#include "PlayerPhysicComponent.h"


/**
 * �÷��̾�� ������ �浹���� �� ó���� ���� ������Ʈ�Դϴ�.
 */
class CrashSoundComponent : public SoundComponent
{
public:
	/**
	 * �÷��̾�� ������ �浹���� �� ó���� ���� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InSoundKey - �浹 ������ Ű ���Դϴ�.
	 */
	CrashSoundComponent(PlayerPhysicComponent* InPhysic, const std::size_t& InSoundKey)
	{
		Physic_ = InPhysic;
		SoundKey_ = InSoundKey;
	}


	/**
	 * �÷��̾�� ������ �浹���� �� ó���� ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~CrashSoundComponent() {}


	/**
	 * �÷��̾�� ������ �浹���� �� ó���� ���� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param InObject - ���� ó���� ������ ���� ������Ʈ�Դϴ�.
	 */
	virtual void Tick(GameObject& InObject) override;


private:
	/**
	 * ���� ���ҽ��� Ű ���Դϴ�.
	 */
	std::size_t SoundKey_ = 0;


	/**
	 * �÷��̾��� �浹 ó�� ������Ʈ�Դϴ�.
	 */
	PlayerPhysicComponent* Physic_ = nullptr;
};