#pragma once

#include "Vector.h"

#include <memory>

class Input;
class Graphics;


/**
 * 게임 오브젝트 클래스입니다.
 * 게임 내의 오브젝트는 이 클래스를 상속받아야 합니다.
 */
class GameObject
{
public:
	/**
	 * 게임 오브젝트의 디폴트 생성자입니다.
	 * 서브 클래스에서는 생성자 혹은 초기화 메서드를 이용해서 오브젝트를 초기화 해야 합니다.
	 */
	GameObject() = default;


	/**
	 * 게임 오브젝트의 가상 소멸자입니다.
	 */
	virtual ~GameObject() {}


	/**
	 * 게임 오브젝트를 업데이트합니다.
	 *
	 * @param InInput - 게임의 입력 처리 인스턴스입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) = 0;


	/**
	 * 게임 오브젝트를 화면에 그립니다.
	 * 
	 * @param InGraphics - 게임의 렌더링 처리 인스턴스입니다.
	 */
	virtual void Render(Graphics& InGraphics) = 0;


	/**
	 * 게임 오브젝트가 화면에 표시될지 확인합니다.
	 * 
	 * @return 게임 오브젝트가 화면에 표시되어야 한다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsVisible() const { return bIsVisible_; }


protected:
	/**
	 * 화면에 보이는지 확인합니다.
	 */
	bool bIsVisible_ = true;
};