#pragma once

#include "PhysicComponent.h"


/**
 * ������ ���� ���� ó�� ������Ʈ�Դϴ�.
 */
class FruitPhysicComponent : public PhysicComponent
{
public:
	/**
	 * ������ ���� ���� ó�� ������Ʈ�� ����Ʈ �������Դϴ�.
	 */
	FruitPhysicComponent() = default;


	/**
	 * ������ ���� ���� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~FruitPhysicComponent() {}


	/**
	 * ������ ���� ���� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InObject - ���� ó���� ������ ���� ������Ʈ�Դϴ�.
	 * @param InWorld - 2D ���� �����Դϴ�.
	 * @param InDeltaSeconds - �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Tick(GameObject& InObject, World& InWorld, float InDeltaSeconds) override;
};