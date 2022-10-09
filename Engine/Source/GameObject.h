#pragma once

class InputSystem;
class RenderSystem;


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
	 * 게임 오브젝트 상태를 업데이트합니다.
	 * 
	 * @param InInput - 게임 엔진의 입력 시스템입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(const InputSystem& InInput, float InDeltaTime) = 0;


	/**
	 * 게임 오브젝트를 화면에 그립니다.
	 * 
	 * @param InRenderer - 게임 엔진의 렌더 시스템입니다.
	 * 
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render(const RenderSystem& InRenderer) = 0;
};