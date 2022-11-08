#pragma once

#include "InputComponent.h"


/**
 * 플레이어의 입력 처리 컴포넌트입니다.
 */
class PlayerInputComponent : public InputComponent
{
public:
	/**
	 * 플레이어의 입력 처리 컴포넌트의 기본 생성자입니다.
	 */
	PlayerInputComponent() = default;

	/**
	 * 플레이어의 입력 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~PlayerInputComponent() {}


	 /**
	  * 입력 처리 컴포넌트를 업데이트합니다.
	  *
	  * @param InObject - 입력처리를 수행할 게임 오브젝트입니다.
	  * @param InInput - 입력 처리 클래스의 인스턴스입니다.
	  */
	virtual void Tick(GameObject& InObject, Input& InInput) override;
};