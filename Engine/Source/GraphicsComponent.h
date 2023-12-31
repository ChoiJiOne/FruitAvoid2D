#pragma once

class GameObject;
class Graphics;


/**
 * 렌더링 처리를 수행하는 컴포넌트입니다.
 * 이 클래스는 인터페이스 클래스입니다.
 */
class GraphicsComponent
{
public:
	/**
	 * 렌더링 처리를 수행하는 컴포넌트의 디폴트 생성자입니다.
	 */
	GraphicsComponent() = default;


	/**
	 * 렌더링 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~GraphicsComponent() {}


	/**
	 * 렌더링 처리 컴포넌트를 업데이트합니다.
	 * 
	 * @param InObject - 렌더링 처리를 수행할 게임 오브젝트입니다.
	 * @param InInput - 렌더링 처리 클래스의 인스턴스입니다.
	 */
	virtual void Tick(GameObject& InObject, Graphics& InGraphics) = 0;
};