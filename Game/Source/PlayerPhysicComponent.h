#pragma once

#include "PhysicComponent.h"


/**
 * �÷��̾��� ���� ���� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class PlayerPhysicComponent : public PhysicComponent
{
public:
	/**
	 * �÷��̾��� ���� ���� ó�� ������Ʈ�� ����Ʈ �������Դϴ�.
	 */
	PlayerPhysicComponent() = default;


	/**
	 * �÷��̾��� ���� ���� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PlayerPhysicComponent() {}


	/**
	 * �÷��̾��� ���� ���� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InObject - ���� ó���� ������ ���� ������Ʈ�Դϴ�.
	 * @param InWorld - 2D ���� �����Դϴ�.
	 * @param InDeltaSeconds - �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Tick(GameObject& InObject, World& InWorld, float InDeltaSeconds) override;
};