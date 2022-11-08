#pragma once

#include "InputComponent.h"


/**
 * �÷��̾��� �Է� ó�� ������Ʈ�Դϴ�.
 */
class PlayerInputComponent : public InputComponent
{
public:
	/**
	 * �÷��̾��� �Է� ó�� ������Ʈ�� �⺻ �������Դϴ�.
	 */
	PlayerInputComponent() = default;

	/**
	 * �÷��̾��� �Է� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PlayerInputComponent() {}


	 /**
	  * �Է� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	  *
	  * @param InObject - �Է�ó���� ������ ���� ������Ʈ�Դϴ�.
	  * @param InInput - �Է� ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	  */
	virtual void Tick(GameObject& InObject, Input& InInput) override;
};