#pragma once

#include "Vector.h"

#include <memory>

class World;
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
	 * 게임 오브젝트의 생성자입니다.
	 * 
	 * @param InWorld - 게임 오브젝트가 위치할 월드입니다.
	 */
	explicit GameObject(World* InWorld);


	/**
	 * 게임 오브젝트의 복사 생성자입니다.
	 * 
	 * @param InInstance - 복사할 게임 오브젝트의 인스턴스입니다.
	 */
	explicit GameObject(GameObject&& InInstance);


	/**
	 * 게임 오브젝트의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 게임 오브젝트의 인스턴스입니다.
	 */
	explicit GameObject(const GameObject& InInstance);


	/**
	 * 게임 오브젝트의 가상 소멸자입니다.
	 */
	virtual ~GameObject();

	
	/**
	 * 게임 오브젝트의 대입 연산자입니다.
	 * 
	 * @param InInstance - 복사할 게임 오브젝트의 인스턴스입니다.
	 * 
	 * @return 복사한 게임 오브젝트의 참조자를 반환합니다.
	 */
	GameObject& operator=(GameObject&& InInstance);


	/**
	 * 게임 오브젝트의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 게임 오브젝트의 인스턴스입니다.
	 *
	 * @return 복사한 게임 오브젝트의 참조자를 반환합니다.
	 */
	GameObject& operator=(const GameObject& InInstance);


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


	/**
	 * 게임 오브젝트가 화면에 표시될지 말지 설정합니다.
	 * 
	 * @param bIsVisible - true 이면 화면에 표시하고, false 라면 화면에 표시하지 않습니다.
	 */
	void SetVisible(bool bIsVisible) { bIsVisible_ = bIsVisible; }


	/**
	 * 게임 오브젝트의 위치를 얻습니다.
	 * 
	 * @return 게임 오브젝트의 위치를 반환합니다.
	 */
	Vec2i GetPosition() const { return Position_; }


	/**
	 * 게임 오브젝트의 위치를 변경합니다.
	 * 
	 * @param InPosition - 변경할 게임 오브젝트의 위치입니다.
	 */
	void SetPosition(const Vec2i& InPosition) { Position_ = InPosition; }


	/**
	 * 게임 오브젝트의 가로 크기를 얻습니다.
	 * 
	 * @return 게임 오브젝트의 가로 크기를 반환합니다.
	 */
	int32_t GetWidth() const { return Width_; }


	/**
	 * 게임 오브젝트의 가로 크기를 변경합니다.
	 * 
	 * @param InWidth - 변경할 게임 오브젝트의 가로 크기입니다.
	 */
	void SetWidth(const int32_t& InWidth) { Width_ = InWidth; }


	/**
	 * 게임 오브젝트의 세로 크기를 얻습니다.
	 *
	 * @return 게임 오브젝트의 세로 크기를 반환합니다.
	 */
	int32_t GetHeight() const { return Height_; }


	/**
	 * 게임 오브젝트의 세로 크기를 변경합니다.
	 *
	 * @param InWidth - 변경할 게임 오브젝트의 세로 크기입니다.
	 */
	void SetHeight(const int32_t& InHeight) { Height_ = InHeight; }


	/**
	 * 게임 오브젝트의 가로, 세로 크기를 얻습니다.
	 * 
	 * @param OutWidth - 게임 오브젝트의 가로 크기입니다.
	 * @param OutHeight - 게임 오브젝트의 세로 크기입니다.
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight) const
	{
		OutWidth = Width_;
		OutHeight = Height_;
	}


	/**
	 * 게임 오브젝트의 가로, 세로 크기를 변경합니다.
	 *
	 * @param OutWidth - 변경할 게임 오브젝트의 가로 크기입니다.
	 * @param OutHeight - 변경할 게임 오브젝트의 세로 크기입니다.
	 */
	void SetSize(const int32_t& OutWidth, const int32_t& OutHeight)
	{
		Width_ = OutWidth;
		Height_ = OutHeight;
	}


protected:
	/**
	 * 게임 오브젝트가 위치한 월드입니다.
	 */
	World* World_ = nullptr;


	/**
	 * 화면에 보이는지 확인합니다.
	 */
	bool bIsVisible_ = true;


	/**
	 * 게임 오브젝트의 화면상 중심 위치입니다.
	 */
	Vec2i Position_;


	/**
	 * 게임 오브젝트의 가로 크기입니다.
	 */
	int32_t Width_ = 0;


	/**
	 * 게임 오브젝트의 세로 크기입니다.
	 */
	int32_t Height_ = 0;
};