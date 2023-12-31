#pragma once

#include "Vector.h"
#include "GraphicsComponent.h"


/**
 * 텍스처 스프라이트의 렌더링 처리를 수행하는 컴포넌트입니다.
 */
class SpriteComponent : public GraphicsComponent
{
public:
	/**
	 * 텍스처 스프라이트의 렌더링 처리를 수행하는 컴포넌트의 생성자입니다.
	 * 
	 * @param InSpriteKey - 텍스처 스프라이트의 키값입니다.
	 */
	explicit SpriteComponent(const std::size_t& InSpriteKey)
	{
		SpriteKey_ = InSpriteKey;
	}


	/**
	 * 텍스처 스프라이트의 렌더링 처리를 수행하는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~SpriteComponent() {}


	/**
	 * 텍스처 스프라이트의 렌더링 처리를 수행하는 컴포넌트를 업데이트합니다.
	 *
	 * @param InObject - 렌더링 처리를 수행할 게임 오브젝트입니다.
	 * @param InInput - 렌더링 처리 클래스의 인스턴스입니다.
	 */
	virtual void Tick(GameObject& InObject, Graphics& InGraphics) override;


private:
	/**
	 * 텍스처의 키값입니다.
	 */
	std::size_t SpriteKey_ = 0;
};