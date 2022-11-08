#pragma once

#include "PhysicComponent.h"


/**
 * 플레이어의 물리 관련 처리를 수행하는 컴포넌트입니다.
 */
class PlayerPhysicComponent : public PhysicComponent
{
public:
	/**
	 * 플레이어의 물리 관련 처리 컴포넌트의 디폴트 생성자입니다.
	 */
	PlayerPhysicComponent() = default;


	/**
	 * 플레이어의 물리 관련 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~PlayerPhysicComponent() {}


	/**
	 * 플레이어의 물리 관련 처리 컴포넌트를 업데이트합니다.
	 *
	 * @param InObject - 물리 처리를 수행할 게임 오브젝트입니다.
	 * @param InWorld - 2D 게임 월드입니다.
	 * @param InDeltaSeconds - 초단위 델타 시간 값입니다.
	 */
	virtual void Tick(GameObject& InObject, World& InWorld, float InDeltaSeconds) override;
};