#pragma once

#include "GameObject.h"
#include "BoundingBox.h"

#include <unordered_map>


/**
 * 게임 플레이어 클래스입니다.
 */
class Player : public GameObject, public BoundingBox
{
public:
	/**
	 * 게임 플레이어의 색상 타입입니다.
	 */
	enum class EColor
	{
		None = 0,
		Blue = 1,
		Green = 2,
		Orange = 3,
		Purple = 4,
		Red = 5,
		Sky = 6,
		Yellow = 7
	};


public:
	/**
	 * 게임 플레이어 클래스의 생성자입니다.
	 * 이때, 게임 플레이어의 속도는 초당 픽셀 이동값으로 계산됩니다.
	 *
	 * @param InPosition - 게임 플레이어의 화면상 위치입니다.
	 * @param InSpeed - 게임 플레이어의 속도입니다.
	 * @param InWidth - 게임 플레이어의 가로 크기입니다.
	 * @param InHeight - 게임 플레이어의 세로 크기입니다.
	 * @param InColor - 게임 플레이어의 색상입니다.
	 */
	explicit Player(const Vec2i& InPosition, const float& InSpeed, const int32_t& InWidth, const int32_t& InHeight, const EColor& InColor);


	/**
	 * 게임 플레이어 클래스의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	Player(Player&& InInstance) noexcept;


	/**
	 * 게임 플레이어 클래스의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	Player(const Player& InInstance) noexcept;


	/**
	 * 게임 플레이어의 가상 소멸자입니다.
	 */
	virtual ~Player();


	/**
	 * 게임 플레이어 클래스의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	Player& operator=(Player&& InInstance) noexcept;


	/**
	 * 게임 플레이어 클래스의 대입 연산자 입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	Player& operator=(const Player& InInstance) noexcept;


	/**
	 * 게임 플레이어 상태를 업데이트합니다.
	 * 
	 * @param InInput - 게임 엔진의 입력 시스템입니다.
	 * @param InDeltaTime - 초단위 델타 시간값 입니다
	 */
	virtual void Update(InputSystem& InInput, float InDeltaTime) override;


	/**
	 * 게임 플레이어를 화면에 그립니다.
	 *
	 * @param InRenderer - 게임 엔진의 렌더 시스템입니다.
	 * 
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render(RenderSystem& InRenderer) override;


private:
	/**
	 * 게임 플레이어의 속도입니다.
	 * 이때, 속도 계산 방식은 초당 이동할 픽셀값입니다.
	 */
	float Speed_ = 0.0f;


	/**
	 * 게임 플레이어의 색상 타입입니다.
	 */
	EColor Color_;


	/**
	 * 게임 플레이어 생상에 대응하는 텍스처 키 값입니다.
	 */
	static std::unordered_map<EColor, std::size_t> ColorTextureKeys_;
};