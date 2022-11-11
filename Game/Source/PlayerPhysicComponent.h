#pragma once

#include "Vector.h"
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


	/**
	 * �÷��̾ �ٸ� ������Ʈ�� �浹�� Ƚ���� ����ϴ�.
	 * 
	 * @return �÷��̾ �ٸ� ������Ʈ�� �浹�� Ƚ���� ��ȯ�մϴ�.
	 */
	int32_t GetCountOfCollision() const { return CountOfColllision_; }


private:
	/**
	 * �÷��̾ �ٸ� ������Ʈ�� �浹�� Ƚ���Դϴ�.
	 */
	int32_t CountOfColllision_ = 0;
};