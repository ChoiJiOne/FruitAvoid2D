#pragma once

#include "Vector.h"
#include "GraphicsComponent.h"


/**
 * �ؽ�ó ��������Ʈ�� ������ ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class SpriteComponent : public GraphicsComponent
{
public:
	/**
	 * �ؽ�ó ��������Ʈ�� ������ ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InSpriteKey - �ؽ�ó ��������Ʈ�� Ű���Դϴ�.
	 */
	explicit SpriteComponent(const std::size_t& InSpriteKey)
	{
		SpriteKey_ = InSpriteKey;
	}


	/**
	 * �ؽ�ó ��������Ʈ�� ������ ó���� �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SpriteComponent() {}


	/**
	 * �ؽ�ó ��������Ʈ�� ������ ó���� �����ϴ� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InObject - ������ ó���� ������ ���� ������Ʈ�Դϴ�.
	 * @param InInput - ������ ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(GameObject& InObject, Graphics& InGraphics) override;


private:
	/**
	 * �ؽ�ó�� Ű���Դϴ�.
	 */
	std::size_t SpriteKey_ = 0;
};